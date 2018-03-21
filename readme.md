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

