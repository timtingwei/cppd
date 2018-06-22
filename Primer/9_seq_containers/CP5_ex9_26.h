/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_26.h
   Date:Fri Jun 22 20:28:16 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_26_h
#define CP5_ex9_26_h

#include <iostream>
#include <vector>
#include <list>

using std::vector; using std::list;

void foo_26() {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  // copy elements to list and vector respectly
  vector<int> ivec;
  vector<int> ilist;
  for (int i = 0; i < 11; i++) {
    ivec.push_back(ia[i]);
    ilist.push_back(ia[i]);
  }

  // use erase(iter), delete even value in vector, oods in list
  auto it_vec = ivec.begin();
  auto it_list = ilist.begin();
  while (it_vec != ivec.end() && it_list != ilist.end()) {
    if (*it_vec % 2) {  // odd
      it_vec = ivec.erase(it_vec);  // remove odd
    } else {
      it_vec++;  // keep on even
    }

    if (*it_list % 2) {  // odd
      it_list++;  // keep on odd
    } else {
      it_list = ilist.erase(it_list);  // remove even
    }
  }

  for (auto it = ivec.cbegin(); it != ivec.cend(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  for (auto it = ilist.cbegin(); it != ilist.cend(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;
  /*
    ./a.out
    0 2 8 
    1 1 3 5 13 21 55 89 
  */
}
#endif

