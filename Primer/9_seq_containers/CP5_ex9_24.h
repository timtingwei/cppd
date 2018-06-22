/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_24.h
   Date:Fri Jun 22 19:22:56 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_24_h
#define CP5_ex9_24_h

#include <iostream>
#include <vector>

using std::vector;

void visit_firstEle(const vector<int> &iv) {
  // iv.empty() = true;
  // auto v1 = iv.at(0);  // out of range
  // auto v2 = iv[0];     // 运行时错误 Segmentation fault: 11
  // auto v3 = *iv.cbegin();   // Segmentation fault: 11
  auto v4 = iv.front();  // Segmentation fault: 11

  // 看起来at比较安全
}
#endif



