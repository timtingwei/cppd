/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_16.h
   Date:Thu Jun 21 15:29:56 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_16_h
#define CP5_ex9_16_h

#include <iostream>
#include <vector>
#include <list>


bool v_l_compare(const std::vector<int> &ivec, const std::list<int> &ilist) {
  // return is or not equal between two container
  if (ivec.size() != ilist.size())
    return false;

  auto bv = ivec.cbegin(), ev = ivec.cend();
  auto bl = ilist.cbegin();
  for (; bv != ev; bv++, bl++) {
    if (*bv != *bl)
      return false;
  }
  return true;
}

#endif



