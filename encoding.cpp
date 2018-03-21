/* Example of encoding problem with ustrings.
 *
 * Compile using:
 *   g++ -std=c++11 test.cpp $(pkg-config --cflags --libs poppler-cpp)
 *
 */
#include <poppler-document.h>
#include <poppler-page.h>
#include <poppler-toc.h>
#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

using namespace poppler;

std::string to_utf8(ustring x){
  if(x.length()){
    byte_array buf = x.to_utf8();
    return std::string(buf.data(), buf.size());
  } else {
    return std::string("null");
  }
}

std::string to_latin1(ustring x){
  return std::string(x.to_latin1());
}

void print_toc(toc_item * item){
  std::cout << " - " << to_utf8(item->title()) <<  std::endl;
  for (toc_item* & i: item->children())
    print_toc(i);
}

int main(int argc, char* argv[]){
  if (argc < 2)
    throw std::runtime_error("Use pdf filename as parameter");
  document * doc = document::load_from_file(argv[1], "", "");
  if(!doc)
    throw std::runtime_error("Failed to read pdf file");
  page *p(doc->create_page(0));
  if(!p)
    throw std::runtime_error("Failed to create pagee");

#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif

  // Test meta fields:
  std::cout << "TOC title: " << to_utf8(doc->create_toc()->root()->title()) <<  std::endl;

  // Test meta keys
  for (std::string& s: doc->info_keys())
    std::cout << s << ": " << to_utf8(doc->info_key(s)) << std::endl;

  // Test toc
  std::cout << "\nTable of Contents:"  << std::endl;
  print_toc(doc->create_toc()->root());

  // Test full text
  std::cout << "\nPDF text:\n" << to_utf8(p->text()) <<  std::endl;

  // Test text list
  std::cout << "\nText Boxes:\n" << std::endl;
  for (text_box& i: p->text_list())
      std::cout << "[" << i.bbox().x() << "x" << i.bbox().y() << "] "  << to_utf8(i.text()) << std::endl;
  return 0;
}
