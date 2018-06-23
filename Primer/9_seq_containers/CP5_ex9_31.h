/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_31.h
    Date:Sat Jun 23 11:44:01 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_31_h
#define CP5_ex9_31_h

#include <iostream>
#include <forward_list>
#include <list>

using std::forward_list; using std::list; using std::vector;

void remove_even_copy_odd(vector<int> &ivec) {
  // remove even elements, and copy each odd elements
  // vector<int> ivec = {0, 1, 2, 3, 2, 4, 5, 7, 8};
  auto iter = ivec.begin();     // need to revise ivec
  while (iter != ivec.end()) {
    if (*iter % 2) {  // odd
      iter = ivec.insert(iter, *iter);
      iter += 2;
    } else {
      iter = ivec.erase(iter);
    }
  }

  for (auto it = ivec.cbegin(); it != ivec.cend(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  /*
    ./a.out
    1 1 3 3 5 5 7 7
  */
}

void remove_even_copy_odd(list<int> &ilist) {
  // remove even elements, and copy each odd elements
  // vector<int> ilist = {0, 1, 2, 3, 2, 4, 5, 7, 8};
  auto iter = ilist.begin();     // need to revise ivec
  while (iter != ilist.end()) {
    if (*iter % 2) {  // odd
      iter = ilist.insert(iter, *iter);
      // iter += 2;   error??? why list cannot +=2
      iter++;
      iter++;      // 链表中元素并非在内存中连续存储, 无法通过地址的加减跨越移动
    } else {
      iter = ilist.erase(iter);
    }
  }

  for (auto it = ilist.cbegin(); it != ilist.cend(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  /*
    ./a.out
    1 1 3 3 5 5 7 7
  */
}

void remove_even_copy_odd(forward_list<int> &i_for_lst) {
  // remove even elements, and copy each odd elements
  // vector<int> i_for_list = {0, 1, 3, 2, 3, 2, 4, 5, 7, 8};
  auto prev = i_for_lst.before_begin();
  auto iter = i_for_lst.begin();     // need to revise ivec
  while (iter != i_for_lst.end()) {
    if (*iter % 2) {  // odd
      iter = i_for_lst.insert_after(iter, *iter);
      prev = iter;       // 仔细想想这两句
      iter++;
    } else {
      iter = i_for_lst.erase_after(prev);
    }
  }

  for (auto it = i_for_lst.cbegin(); it != i_for_lst.cend(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  /*
    ./a.out
    1 1 3 3 5 5 7 7
  */
}


#endif

