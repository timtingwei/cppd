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
  vector<int> c{2, 3, 4, 9, -2, -3};
  if (!c.empty()) {
    auto val1 = *c.cbegin(), val2 = c.front();
    auto last = c.end();

    auto val3 = *(--last), val4 = c.back();
    std::cout << "val3 = " << val3 << " " << "val 4 = " << val4 << std::endl;
  }
  return 0;
}
