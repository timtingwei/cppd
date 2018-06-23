/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_27.h
   Date:Sat Jun 23 10:39:40 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_27_h
#define CP5_ex9_27_h

#include <iostream>
#include <forward_list>

using std::forward_list;

void remove_odd_flst(forward_list<int> &i_flist) {
  // i_flist = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  // prev to before begin iterator
  auto prev = i_flist.before_begin();
  auto curr = i_flist.begin();
  while (curr != i_flist.end()) {
    if (*curr % 2) {  // odd
      curr = i_flist.erase_after(prev);  // remove curr after prev, it's odd
    } else {
      curr++;
      prev++;
    }
  }

  for (auto it = i_flist.cbegin(); it != i_flist.cend(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  /*
    ./a.out
    0 2 8  
  */
}
#endif

