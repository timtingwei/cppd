/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_m.cpp
   Date:Wed Jan 17 22:41:36 CST 2018
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

// Club::Club(const std::string& n, Date fd)
//     : name(n), members(), officers(), founded(fd)
// {
  // ..
// }

Club::Club(const std::string& n, Date fd)
    : name(n), founded(fd)
{
  // ..
}
// 构造函数在类容器本身构造函数执行之前执行
// 构造函数按照成员在类中的声明顺序执行。 为了避免混乱, 按照声明顺序描述初始式

// 对象被销毁, 将自己的析构函数先执行, 然后按照与声明相反的顺序执行各个成员的析构函数。构造函数自下而上(成员在先), 析构函数自下而上(成员在后)拆除。

void h() {
  const std::string& n = "tim";
  Date fd;
  Club(n, fd);
  
}


int main() {
  h();
  // f();

  return 0;
}
