/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:const_object.cpp
   Date:Wed Jan 10 18:22:39 CST 2018
   -----------------------------
*/
#include <iostream>

class MyClass;
void print(const MyClass &arg);

class MyClass {
  int x = 0;
 public:
  MyClass(int v) :x(v) {}
  const int& get() const {return x;}
  // 不声明成const类型, 无法对const对象调用get
};


void print(const MyClass& arg) {
  std::cout << "arg.x = " << arg.get() << std::endl;
}

int main() {
  // ..
  MyClass c(10);
  print(c);
  return 0;
}



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

