/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_ref_init.cpp
   Date:Wed Jan 17 22:59:23 CST 2018
   -----------------------------
*/

#include <iostream>
#include <string.h>

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

class Date{};


// 定义小型有关信息组织的类
class Club {
  std::string name;
  Table members;
  Table officers;
  Date founded;
  // ...
 public:
  Club(const std::string& n, Date fd);
};

Club::Club(const std::string& n, Date fd)
    : name(n), founded(fd)
{
  // ..
}

class X {
  // const int i;
  // Club c;
  // const int i;
  // int &i;          // const 和 reference类型, 需要被构造函数初始化
  // Club& pc;
  // ..
 public:
  // X(int ii, const std::string& n, Date d, Club& c)
  //     : i(ii), c(n, d), pc(c) {}
};

void h() {
  const std::string& n = "tim";
  Date fd;
  Club c(n, fd);

  int ii = 4;
  const std::string& n1 = "cooper";
  Date d;
  // X x(ii, n1, d, c);
  X x;
  
}


int main() {
  h();
  // f();

  return 0;
}
