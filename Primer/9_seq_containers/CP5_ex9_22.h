/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_22.h
   Date:Thu Jun 21 22:03:35 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_22_h
#define CP5_ex9_22_h

#include <iostream>
#include <vector>

using std::vector;

void insert_doubleVal(vector<int> &iv, const int &some_val) {
  vector<int>::iterator iter = iv.begin();
  int org_size = iv.size(), new_ele = 0;

  while (iter != iv.begin() + org_size / 2 + new_ele) {
    if (*iter == some_val) {
      iter = iv.insert(iter, some_val * 2);
      new_ele++;             // 新元素个数增加
      iter++, iter++;        // 递增两次, 指向x元素之后
    } else {
      iter++;                // 正常推进迭代器
    }
  }
}
#endif



