/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_13.h
   Date:Thu Jun 21 11:50:15 CST 2018
   -----------------------------
*/


#ifndef CP5_ex9_13_h
#define CP5_ex9_13_h

#include <iostream>
#include <vector>
#include <list>

void foo_13() {
  std::list<int> ilist{0, 1, 2, 3};
  std::vector<int> ivec{4, 5, 6, 7};
  std::vector<double> dvec1(ilist.begin(), ilist.end());
  std::vector<double> dvec2(ivec.begin(), ivec.end());
}

// if the type of elements could convert, it can initialize by iterator





#endif



