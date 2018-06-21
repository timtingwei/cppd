/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:CP5_ex9_5.h
   Date:Wed Jun 20 03:06:43 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_5_h
#define CP5_ex9_5_h

#include <iostream>
#include <vector>

std::vector<int>::iterator
findVal(std::vector<int>::iterator iter1, std::vector<int>::iterator iter2,
             const int& val) {
  if (iter1 > iter2) {
    auto tmp_iter = iter1;
    iter1 = iter2, iter2 = tmp_iter;
  }
  // assert iter1 < iter2
  while (iter1 != iter2) {
    if (*iter1 == val) return iter1;
    iter1++;
  }
  // if don't find value, return iter2
  return iter2;
}

#endif



