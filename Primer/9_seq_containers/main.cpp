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

using std::vector; using std::list;
using std::string;

int main() {
  vector<int> v{2, 3, 4, 9, -2, -3};
  if (!v.empty()) {
    v.front() = 42;
    auto &r = v.back();
    r = 1024;              // change the last value
    std::cout << "v.back() = " << v.back() << std::endl;

    auto nr = v.back();
    // it's not reference to last value, can not change last one
    nr = 88;
    std::cout << "v.back() = " << v.back() << std::endl;

    auto &r2 = v[v.size() - 1];   // change it
    r2 = 7;
    std::cout << "v.back() = " << v.back() << std::endl;
  }
  return 0;
}
