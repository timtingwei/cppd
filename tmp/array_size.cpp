/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:array_size.cpp
   Date:Fri Jan 12 11:40:18 CST 2018
   -----------------------------
*/

#include <iostream>

// #define ARRAY_SIZE = 5;
#define ARRAY_SIZE 5
void f() {
  int iarr[] = {};
  iarr[2] = 5;
  std::cout << "iarr[0] = " << iarr[0] << std::endl;   // iarr[0] = 0


  const unsigned int size = 5;
  int iarr1[size] = {};
  for (int i = 0; i < size; i++)
    std::cout << ++iarr1[i] << std::endl;

  int iarr2[ARRAY_SIZE] = {};
  for (int i = 0; i < ARRAY_SIZE; i++)
    std::cout << (iarr2[i]+=2) << std::endl;
  
}

int main() {
  // ..
  f();
  return 0;
}

