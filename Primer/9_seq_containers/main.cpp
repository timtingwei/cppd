/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:main.cpp
   Date:Wed Jun 20 02:03:46 CST 2018
   -----------------------------
*/
#include <iostream>
#include <vector>
#include "CP5_ex9_2.h"
#include "CP5_ex9_5.h"

int main() {
  std::cout << "hello, world\n";
  std::vector<int> v{0, 1, 2, 3, 4};
  std::cout << "v.begin() = " << *v.begin() << " "
            << "v.end() = " << *v.end() << " "
            << "--v.end() = " << *(--v.end()) << std::endl;
  // ./a.out: v.begin() = 0 v.end() = 32767 --v.end() = 4

  int val = 8;
  auto begin = v.begin(), end = v.end();
  while (begin != end) {
    *begin = val;
    begin++;
  }

  for (auto iter = v.begin(); iter != v.end(); iter++) {
    std::cout << *iter << std::endl;
  }

  begin = v.begin(), end = v.end();
  val = 2;
  auto result_find_iter = findVal(begin, end, val);
  std::cout << "*result_find_iter = " << *result_find_iter << std::endl;
  return 0;
}
