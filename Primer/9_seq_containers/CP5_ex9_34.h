/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_34.h
    Date:Sat Sat Jun 23 16:22:53 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_34_h
#define CP5_ex9_34_h

#include <iostream>
#include <vector>

using std::vector;

void foo_34() {
  vector<int> v{2, 4, 6, 7, 8, 1, 4, 5};
  auto it = v.begin();
  while (it != v.end()) {
    if (*it % 2) {  // odd
      it = v.insert(it, *it);
      // it++;
    }
    it++;
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

