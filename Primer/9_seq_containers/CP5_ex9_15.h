/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_15.h
   Date:Thu Jun 21 15:22:17 CST 2018
   -----------------------------
*/


#ifndef CP5_ex9_15_h
#define CP5_ex9_15_h

#include <iostream>
#include <vector>


void foo_15() {
  std::vector<int> ivec1 = {0, 1, 2, 3};
  std::vector<int> ivec2 = {0, 1};
  std::vector<int> ivec3 = {0, 1, 3};

  std::cout << "ivec1 == ivec2: " << (ivec1 == ivec2) << "\n"  // false
            << "ivec2 < ivec1: " << (ivec2 < ivec1) << "\n"    // true
            << "ivec3 < ivec1: " << (ivec3 < ivec1) << std::endl;  // false
}







#endif



