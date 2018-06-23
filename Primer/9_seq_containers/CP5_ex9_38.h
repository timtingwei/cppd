/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_38.h
    Date:Sat Jun 23 22:39:09 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_38_h
#define CP5_ex9_38_h

#include <iostream>
#include <vector>

using std::vector;

void foo_38() {
  vector<int> iv;
  std::cout << "iv.capacity() = " << iv.capacity() << "\n"
            << "iv.size()     = " << iv.size() << std::endl;

  while (iv.size() != 50) {
    iv.push_back(0);
    std::cout << "iv.capacity() = " << iv.capacity() << "\n"
              << "iv.size()     = " << iv.size() << "\n" << std::endl;
  }
}

/*
  ./a.out
*/

#endif

