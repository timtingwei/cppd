/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_local.cpp
   Date:Tue Jan 16 22:27:37 CST 2018
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
  explicit Table(size_t s = 15) {                 // constructor
    p = new Name[sz = s];
    for (int i = 0; i < sz; i++) {
      std::cout << "in Table() i = " << i << std::endl;
    }
  }
  ~Table() {                                      // deconstructor
    delete[] p;
    std::cout << "in ~Table() sz = " << sz << std::endl;
  }
  Name* lookup(const char*);
  bool insert(Name*);
};

void f(int i) {
  Table aa(1);
  Table bb(2);
  if (i > 0) {
    Table cc(3);
  }
  Table dd(3);
}

int main() {
  f(2);

  return 0;
}
