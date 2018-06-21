/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_12.h
   Date:Thu Jun 21 11:42:08 CST 2018
   -----------------------------
*/

// explain difference between construct function accept a container
// and accept two iterator

#ifndef CP5_ex9_12_h
#define CP5_ex9_12_h

#include <iostream>
#include <vector>


void foo_12() {
  std::vector<int> v1{0, 1, 2, 3};

  std::vector<int> v2(v1);
  std::vector<int> v3(v1.begin(), v1.end() - 1);
}

// v2 accept a accurate container, v3 accept a sequence which length is flexible



#endif



