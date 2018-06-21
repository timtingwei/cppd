/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_8.h
   Date:Thu Jun 21 11:21:39 CST 2018
   -----------------------------
*/

// six methods to create and initialize a vector

#ifndef CP5_ex9_11_h
#define CP5_ex9_11_h

#include <iostream>
#include <vector>


void foo_11() {
  std::vector<int> v1 = {0, 1, 2};  // 0, 1, 2     equal to std::vector<int> v1{0, 1, 2};
  std::vector<int> v2;
  std::vector<int> v3(5);          // 0, 0, 0, 0, 0
  std::vector<int> v4(5, -1);      // -1, -1, -1, -1, -1
  std::vector<int> v5(v4);         // -1, -1, -1, -1, -1  equal to std::vector<int> v5 = v2
  std::vector<int> v6(v4.begin(), v4.end());  // -1, -1, -1, -1, -1
}



#endif



