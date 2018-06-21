/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_7.h
   Date:Thu Jun 21 10:10:17 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_7_h
#define CP5_ex9_7_h

#include <iostream>
#include <vector>

void foo_7() {
  std::vector<int> ivec{0, 1, 2, 3};
  std::vector<int>::const_iterator begin = ivec.begin();
  std::cout << "*begin = " << *begin << std::endl;
  // *(++begin) = 5;       // opps! iterator is const
}



#endif



