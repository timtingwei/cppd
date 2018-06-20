/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:CP5_ex9_6.h
   Date:Wed Jun 20 17:38:38 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_6_h
#define CP5_ex9_6_h

#include <iostream>
#include <list>
#include <vector>

void foo() {
  std::vector<int> lst1{0, 1, 2};
  std::vector<int>::iterator iter1 = lst1.begin(),
      iter2 = lst1.end();
  while (iter1 != iter2) {    // opps! invalid operands to binary expression
    // ..
    std::cout << "into while!\n";
    iter1++;
  }
}

// only std::vector and std::deque can use compare operation


#endif



