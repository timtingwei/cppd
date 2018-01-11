/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:vector_disordered.cpp
   Date:Thu Jan 11 11:30:45 CST 2018
   -----------------------------
*/

/*
类内static类型如何声明?
在不同实例中被多次调用改变后的情况?
 */
#include <iostream>

class MyStatic {
  // static int i_stc = 5;     // 只能通过定义初始化
  // static int i_stc;
 public:
  static int i_stc;            // 类内部只能声明静态成员
  static void set_static(int i) {i_stc = i;}
  void set_static_member(int i) {i_stc = i;}
  void increment() {i_stc += 1;}   // 改变static数据的值
  // virtual operator()() {i_stc += 1;}    // 函数对象改变static变量的值
};

int MyStatic::i_stc = 0;      // 类外部定义, 初始化静态数据成员

void f() {
  // MyStatic::set_static(2);    // 静态成员函数可以通过作用域访问
  MyStatic c0;
  // c0.set_static(3);
  c0.increment();
  std::cout << "c0 = " << c0.i_stc << std::endl;
  MyStatic c1;
  c1.increment();
  std::cout << "c1 = " << c1.i_stc << std::endl;
}

void f1() {
  MyStatic c2;
  c2.increment();
  std::cout << "c2 = " << c2.i_stc << std::endl;
}


int main() {
  // ..
  f();
  f1();
  return 0;
}
