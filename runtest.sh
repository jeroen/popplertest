#!/bin/sh
g++ -std=c++11 encoding.cpp -o encoding $(pkg-config --cflags --libs poppler-cpp)
./encoding hello.pdf
