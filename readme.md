# Poppler Test

Example code to test the poppler C++ frontend. To download:

```
git clone https://github.com/jeroen/popplertest
cd popplertest
```

Then compile and run:

```
g++ -std=c++11 encoding.cpp -o encoding $(pkg-config --cflags --libs poppler-cpp)
./encoding hello.pdf
```

The expected output should be something like this:

```
TOC title:
Author: Jeroen Ooms
Title: Hello World
Subject:
Creator: LaTeX with hyperref package
Producer: pdfTeX-1.40.18
Keywords:
CreationDate: D:20180320225741+01'00'
ModDate: D:20180320225741+01'00'
Trapped:
PTEX.Fullbanner: This is pdfTeX, Version 3.14159265-2.6-1.40.18 (TeX Live 2017) kpathsea version 6.2.3

Table of Contents:
 -
 - Chapter 1
 - Subsection 1

PDF text:
                          Hello World
                           Jeroen Ooms
                            3/20/2018
Chapter 1
Subsection 1
Today is a beautiful day!
                                 1


Text Boxes:

[256.318x78.8185] Hello
[305.075x78.8185] World
[272.435x104.62] Jeroen
[309.806x104.62] Ooms
[278.291x124.545] 3/20/2018
[72x159.474] Chapter
[124.54x159.474] 1
[72x185.054] Subsection
[129.505x185.054] 1
[72x209.521] Today
[102.442x209.521] is
[112.457x209.521] a
[120.766x209.521] beautiful
[162.822x209.521] day!
[303.509x743.024] 1
```