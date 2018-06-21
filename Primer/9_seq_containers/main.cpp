/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:main.cpp
   Date:Wed Jun 20 02:03:46 CST 2018
   -----------------------------
*/
#include <iostream>
#include <array>

int main() {
  std::array<int, 10> iarr1;
  std::array<int, 10> iarr2 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::array<int, 10> iarr3 = {3};

  for (auto iter = iarr3.begin(); iter != iarr3.end(); iter++) {
    std::cout << *iter << std::endl;
  }

  return 0;
}
