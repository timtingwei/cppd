/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_33.h
    Date:Sat Jun 23 11:44:01 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_33_h
#define CP5_ex9_33_h

#include <iostream>
#include <vector>

using std::vector;

void foo_33() {
  vector<int> v{2, 4, 6, 7, 8};
  auto begin = v.begin();
  while (begin != v.end()) {
    ++begin;        // 为了在begin之后添加元素
    v.insert(begin, 42);    // 42插入begin之前, begin指向42
    ++begin;
  }

  for (auto it = v.cbegin(); it != v.cend(); it++)
    std::cout << *it << " ";
  std::cout << std::endl;
}

/*
  ./a.out
  a.out(44606,0x7fffa2810380) malloc: *** error for object 0x7f8602402838: incorrect checksum for freed object - object was probably modified after being freed.
*** set a breakpoint in malloc_error_break to debug
*/

#endif

