/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:overload_members.cpp
   Date:Wed Jan 10 17:39:50 CST 2018
   -----------------------------
*/

#include <iostream>


class MyClass {
  int x = 0;
 public:
  int c = 5;
  MyClass(int v) :x(v) {}
  const int& get() const {    // 常量成员函数在是否为常量上可以重载
    int a = 5, &b = a;
    return x;
  }
  int& get() {return --x;}
};

/*
// 为什么可以对a.get()赋值
// get()返回的是引用, 引用可作为左值, 且如果非常量引用的话,  该值可以被修改。

// 在是否为成员函数上重载后如何匹配?
// 成员函数在是否为常量函数上可以重载。如果对象实例化成const类型, 则匹配常量成员函数。

// const int& get() const {return x;} 为什么返回类型需要const?
常量函数返回数据成员, 编译器会将数据成员声明成const类型;

// 什么是数据成员?
在class中声明的, 无论是私有的还是公有的数据, 都是成员数据。如果在常量函数中返回, 会常量函数会被声明成const类型。



*/
int main() {
  // ..
  MyClass a(10);
  // const MyClass b(5);
  a.get() = 15;
  // b.get() = 20;
  std::cout << "a.get() = " << a.get() << std::endl;
  // std::cout << "b.get() = " << b.get() << std::endl;
  return 0;
}
