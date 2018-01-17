/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_free.cpp
   Date:Wed Jan 17 22:22:15 CST 2018
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

  // 将复制定义清楚
  Table(const Table&);              // 复制构造函数
  Table& operator=(const Table&);   // 复制赋值
};

Table::Table(const Table& t) {
  p = new Name[sz = t.sz];
  for (int i = 0; i < sz; i++) {
    p[i] = t.p[i];
  }
}

Table& Table::operator=(const Table& t) {
  if (this != &t) {         // 防止自复制
    delete[] p;
    p = new Name[sz = t.sz];
    for (int i = 0; i < sz; i++) {p[i] = t.p[i];}
  }
  return *this;
}

void h() {
  Table* p = new Table;
  Table* q = new Table;

  delete p;
  // delete p;    // ERROR: 删除两次
}

// 没有删除会造成内存泄漏, 很长时间运行就会造成严重问题。
// 删除两次使得其行为没有定义, 后果可能是灾难性的。

int main() {
  h();
  // f();

  return 0;
}
