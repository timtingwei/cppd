/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_inline.cpp
   Date:Tue Jan 16 21:39:45 CST 2018
   -----------------------------
*/
/*
  在类内部的函数定义
 */

#include <iostream>

class Date {
 public:
  // 在类内部定义的函数都是小而常用的
  // int day() {return d;}
  int day();
 private:
  int d, m, y;
};
// 或者使用inline将函数定义在类之后
inline int Date::day() {return d;}

void f() {
  Date d;
  d.day();
}

int main() {
  f();
}
