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

  // 将复制定义清楚
  Table(const Table&);              // 复制构造函数
  Table& operator=(const Table&);   // 复制赋值
};

// 将复制定义清楚
/* my test code
Table::Table(const Table& t) {
  p = new Name[sz = t.sz];
  for (int i = 0; i < sz; i++) {
    std::cout << "t[i] = " << t[i] << std::endl;
    p[i] = t[i];
  }
}

Table& Table::operator=(const Table& t) {
  p = new Name[sz = t.sz];
  for (int i = 0; i < sz; i++) {
    std::cout << "t[i] = " << t[i] << std::endl;
    p[i] = t[i];
  }
}
*/

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
  Table t1;
  // Table t2 = t1;    // ERROR: 复制初始化
  Table t3;

  // t3 = t2;          // ERROR: 复制赋值
}
// t1所创建而分配的数组, 将同时分配给t1, t2, t3, 被删除3次, 所导致结果是无意义的

void f() {
  Table t1(2);
  Table t2 = t1;
  Table t3(t1);
}
/*
in Table() sz = 2
in ~Table() sz = 2
in ~Table() sz = 2
in ~Table() sz = 2
*/
int main() {
  // h();
  f();

  return 0;
}
