/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_dtor.cpp
   Date:Mon Jan  8 19:28:20 CST 2018
   -----------------------------
*/

#include <iostream>

class Name {
  const char* s;
};

class Table {
  Name* p;
  size_t sz;
 public:
  Table(size_t s = 15) {                          // constructor
    p = new Name[sz = s];
    for (int i = 0; i < sz; i++) {
      // p[i] = 'c';
      std::cout << "i = " << i << std::endl;
    }
  }
  ~Table() {                                      // deconstructor
    delete[] p;
    std::cout << "sz = " << sz << std::endl;
  }
  Name* lookup(const char*);
  bool insert(Name*);
};

int main() {
  Table();

  return 0;
}
