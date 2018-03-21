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

using namespace poppler;

std::string to_string(ustring x){
  if(x.length()){
    byte_array buf = x.to_utf8();
    return std::string(buf.data(), buf.size());
  } else {
    return std::string("null");
  }
}

void print_toc(toc_item * item){
  std::cout << " - " << to_string(item->title()) <<  std::endl;
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

  // Test meta fields:
  std::cout << "TOC title: " << to_string(doc->create_toc()->root()->title()) <<  std::endl;

  // Test meta keys
  for (std::string& s: doc->info_keys())
    std::cout << "KEY: " << s << " :" << to_string(doc->info_key(s)) << std::endl;

  // Test toc
  std::cout << "Table of Contents:\n"  << std::endl;
  print_toc(doc->create_toc()->root());

  // Test full text
  std::cout << "PDF text:\n" << to_string(p->text()) <<  std::endl;

  // Test text list
  for (text_box& box: p->text_list())
      std::cout << "textbox " << to_string(box.text()) <<  std::endl;
  return 0;
}
