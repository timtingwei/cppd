/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_copy.cpp
   Date:Tue Jan 16 22:47:16 CST 2018
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
      // std::cout << "in Table() i = " << i << std::endl;
    }
    std::cout << "in Table() sz = " << sz << std::endl;
  }
  ~Table() {                                      // deconstructor
    delete[] p;
    std::cout << "in ~Table() sz = " << sz << std::endl;
  }
  Name* lookup(const char*);
  bool insert(Name*);
};

void h() {
  Table t1;
  Table t2 = t1;
  Table t3;

  t3 = t2;
}


int main() {
  h();

  return 0;
}
