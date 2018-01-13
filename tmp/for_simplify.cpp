/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:for_simplify.cpp
   Date:Sat Jan 13 13:26:10 CST 2018
   -----------------------------
*/
#include <iostream>

/*
for语句的三个表达式如何写?
 */

/* 问题
Vector(int c = DEAFAULT_CAPACITY, int s = 0, T v = 0)
  {_elem = new T[_capacity = c];
    for (_size = 0; _size < s; _elem[size++] = v)}     // 默认   
 */

void f() {
  const int s = 8;
  int size = 0;
  int elem[s] = {};
  /*
  for (size = 0; size < s; size++) {
    elem[size] = 2;
  }
  */
  // 第三个参数, 递增size的同时, 给修改elem
  for (size = 0; size < s; elem[size++] = 2) {}
  // 第三个参数, 修改i的同时, 打印elem[i]对应的元素
  for (int i = 0; i < size; std::cout << elem[i++] << std::endl) {}
}

int main() {
  f();

  return 0;
}

