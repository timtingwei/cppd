/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_25.h
   Date:Fri Jun 22 19:57:55 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_25_h
#define CP5_ex9_25_h

#include <iostream>
#include <vector>

using std::vector;

void foo_25() {
  vector<int> iv = {1, 2, 3};

  // auto elem1 = iv.begin(), elem2 = elem1;          // 1, 2, 3   | *elem1 = 1
  // auto elem1 = iv.begin()+2, elem2 = iv.end();   // 1         | *elem1 = 2
  auto elem1 = iv.end(),   elem2 = iv.end();  // 1, 2, 3   | *elem1 -> undefined

  elem1 = iv.erase(elem1, elem2);

  // when elem1 = elem2, erase nothing, return elem1 + 1;
  //      elem2 = iv.end(), erase from elem1 to last, return iv.end()
  //      elem1 = elem2 = iv.end(), erase nothing, return iv.end();

  for (auto it = iv.cbegin(); it != iv.cend(); it++) {
    std::cout << *it << std::endl;
  }
  std::cout << "*elem1 = " << *elem1 << std::endl;
}
#endif



