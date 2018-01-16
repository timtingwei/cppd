/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_significance.cpp
   Date:Tue Jan 16 22:03:09 CST 2018
   -----------------------------
*/
/*
  Date是一个具体类型, 该对象是面向值的程序设计, 和面向相去甚远。
  具体类型是单独的, 相对较小的事情。在编译时大小已经知晓, 无需使用自由储存操作. 每个对象的布局在编译时已经知晓, 操作的在线化容易做到, 不需要对兼容性做更多的努力。

  一个程序中, 不适用"小而有效的类型", 并因此使用过分一般且代价昂贵的类, 可能导致空间和时间上的浪费。缺乏具体类型的程序, 导致结构模糊的程序和时间的浪费, 因此每个程序员都要写代码去操作“小而频繁使用的数据结构”
 */

#include <iostream>

class Date_and_time {
 private:
  Date d;
  Time t;
 public:
  Date_and_time(Date d, Time t);
  Date_and_time(int d, Date::Month m, int y, Time t);
};

void f() {
  Date_and_time dat;
}

int main() {
  f();
}
