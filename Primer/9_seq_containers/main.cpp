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
#include "CP5_ex9_24.h"

using std::vector; using std::list;
using std::string;

int main() {
  // pop odd value
  vector<int> v = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  auto iter = v.begin();
  while (iter != v.end()) {
    if (*iter % 2) {  // iter指向奇数
      iter = v.erase(iter);
    } else {
      iter++;
    }
  }

  for (auto it = v.cbegin(); it != v.cend(); it++) {
    std::cout << *it << std::endl;
  }
  std::cout << std::endl;

  v.clear();
  for (auto it = v.cbegin(); it != v.cend(); it++) {
    std::cout << *it << std::endl;
  }
  std::cout << std::endl;

  v.insert(v.end(), {2, 3, 4, 8, 9});
  for (auto it = v.cbegin(); it != v.cend(); it++) {
    std::cout << *it << std::endl;
  }
  std::cout << std::endl;

  v.erase(v.cbegin(), v.cend());
  for (auto it = v.cbegin(); it != v.cend(); it++) {
    std::cout << *it << std::endl;
  }
}
