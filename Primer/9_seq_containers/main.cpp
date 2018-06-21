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
#include "CP5_ex9_22.h"

using std::vector; using std::list;
using std::string;

int main() {
  vector<int> iv = {0, 2, 9, 3, 9, 11, 22, 2, 3, 4, 8, 9, 10, 9, 22, 3, 9};
  int some_val = 9;
  insert_doubleVal(iv, some_val);

  for (auto iter = iv.cbegin(); iter != iv.cend(); iter++) {
    std::cout << *iter << " ";
  }
  std::cout << std::endl;
  
  return 0;
}
