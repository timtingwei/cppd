/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:pointer_to_functions.cpp
   Date:Wed Jan 10 07:08:35 CST 2018
   -----------------------------
*/

#include <iostream>


bool compareInt(const int& i1, const int& i2) {
  return i1 < i2 ? true : false;      // i1 < i2, 返回true
}

bool otherCompare(const int& i1, const int&) {return 0;}

// 声明: 指针替换函数名
bool (*pf)(const int&, const int&);

// 定义另外几个函数
int getLarger(const int& i1, const int& i2) {
  return i1 < i2 ? i2: i1;            // 返回两者较大
}

int increment(const int& i_original) {
  return i_original + 1;
}

void ff(int*) {return;}
void ff(unsigned int) {return;}

// 函数指针作为形参
void useBigger(const int&, const int&, bool (*pf)(const int&, const int&)) {
  return;
}

// Func2是函数类型
typedef decltype(compareInt) Func2;
typedef decltype(compareInt) *FuncP2;

// 等价声明
void useBigger2(const int&, const int&, FuncP2);
void useBigger3(const int&, const int&, Func2);
// 函数指针作为返回值

// 定义函数指针类型的方法
using F = int(int*, int);          // F是函数类型
using PF = int(*)(int*, int);      // PF是指针类型

PF f1(int);      // PF是指针类型, f1返回指向函数的指针
// F f2(int);       // Error:F是函数类型, 无法返回一个函数
F *f1(int);      // 显式返回类型是指向函数的指针


int main() {
  // ..
  int i1 = 3, i2 = 5;

  // 定义
  pf = compareInt;           // pf 指向名为compareInt的函数
  pf = &compareInt;          // 也可以用这种形式
  // 使用
  bool b1 = pf(3, 5);
  bool b2 = (*pf)(5, 3);
  bool b3 = compareInt(3, 5);
  std::cout << "b1 = " << b1 << std::endl;    // b1 = 1
  std::cout << "b2 = " << b2 << std::endl;    // b2 = 0
  std::cout << "b3 = " << b3 << std::endl;    // b3 = 1

  // 赋nullptr:指针没有指向任何一个函数
  pf = 0;
  // pf = getLarger;     // error: pf已经被声明成bool(*)(const int&, const int&)
  // pf = increment;     // error: 同上
  pf = otherCompare;
  int (*pf1)(const int&, const int&) = &getLarger;
  int i_pf1 = (*pf1)(3, 5);
  std::cout << "i_pf1 = " << i_pf1 << std::endl;     // i_pf1 = 5

  // 重载
  void (*pff1)(int *) = &ff;

  // void (*pff2)(int) = &ff;
  // int (*pff3)(unsigned) = &ff;

  // 调用函数指针作为形参的函数
  useBigger(i1, i2, compareInt);

  
  return 0;
}

