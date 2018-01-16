/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_array.cpp
   Date:Tue Jan 16 23:50:38 CST 2018
   -----------------------------
*/

#include <iostream>

class Name {
  const char* s;
};

void test_array() {
  Name* t;
  t[0];

  int i = 5;
  int* ptr_i = &i;
  int r = ptr_i[0];
  std::cout << "r = " << r << std::endl;
}

/*
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

  // 将复制定义清楚
  Table(const Table&);              // 复制构造函数
  Table& operator=(const Table&);   // 复制赋值
};
*/

int main() {
  // h();
  // f();
  test_array();

  return 0;
}
