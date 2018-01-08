/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_default.cpp
   Date:Mon Jan  8 20:03:14 CST 2018
   -----------------------------
*/

/*
  1, 编译器生成的默认构造函数将隐式地为类类型的成员和它的基类调用有关的默认构造函数
  2, const 和引用成员的类不能进行默认构造
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
    std::cout << "---initialize Table(size_t s = 15)-------\n"
         << "sz = " << sz << std::endl;
  }
  Table(int lo, int hi) {
    p = new Name[sz = 2*(hi-lo)];
    std::cout << "---initialize Table(int lo, int hi)-------\n"
         << "sz = " << sz << std::endl;
  }
  ~Table() {                                      // deconstructor
    delete[] p;
  }
  Name* lookup(const char*);
  bool insert(Name*);
};



struct Tables {
  int i;
  int vi[10];

  int lo = 2, hi = 5;
  Table t1;      //  编译器默认构造函数将为类类型的成
                 //  员和它的基类调用有关默认构造函数
  Table vt[2];
};

// const 和引用成员的类不能进行默认构造
struct X {
  // const int a;
  // const int& r;
  // int &r;
  Table t1;
};

int main() {
  // Table();

  // int lo_main = 1, hi_main = 2;
  // Table(lo_main, hi_main);

  // Table t1(lo_main, hi_main);
  // Table t2[3];

  Tables tt;    // tt.t1, tt.vt的每个成员调用Table15;
                // 但不会区初始化tt.i 和 tt.vi, 他们不是类类型的对象

  X x;   // Error: X无默认构造函数

  return 0;
}
