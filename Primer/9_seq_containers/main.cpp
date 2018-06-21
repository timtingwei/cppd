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
#include <list>
#include <string>
#include "CP5_ex9_16.h"

using std::vector; using std::list;
using std::string;

int main() {
  
  std::vector<int> ivec = {0, 1, 2, 3};
  std::list<int> ilist = {0, 1, 2, 3};
  std::cout << v_l_compare(ivec, ilist) << std::endl;
  return 0;
}
