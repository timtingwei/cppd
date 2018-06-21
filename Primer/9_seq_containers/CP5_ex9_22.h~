/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_20.h
   Date:Thu Jun 21 21:11:44 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_20_h
#define CP5_ex9_20_h

#include <iostream>
#include <list>
#include <deque>

using std::deque; using std::list;

void foo_20() {
  list<int> ilist{0, 1, 2, 3, 4, 5, 6 , 7};
  deque<int> ideq1, ideq2;
  // even to deque1, odd to deque2
  for (auto iter = ilist.cbegin(); iter != ilist.cend(); iter++) {
    if (*iter % 2 == 0) {
      ideq1.push_back(*iter);
    } else {
      ideq2.push_back(*iter);
    }
  }
}
#endif



