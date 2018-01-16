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
  // Table t2 = t1;    // ERROR: 复制初始化
  Table t3;

  // t3 = t2;          // ERROR: 复制赋值
}
// t1所创建而分配的数组, 将同时分配给t1, t2, t3, 被删除3次, 所导致结果是无意义的

int main() {
  h();

  return 0;
}
