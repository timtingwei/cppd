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
#include "CP5_ex9_45.h"

using std::list; using std::vector;
using std::string;

int main() {
  string s = "Tim";
  string prefix = "Mr.", suffix = "Jr.";
  company_name(s, prefix, suffix);

  /*
  s.insert(0, "sds");
  std::cout << s << std::endl;

  s.insert(s.cbegin(), 't');
  std::cout << s << std::endl;

  auto append_s = s.append("love");
  std::cout << s << std::endl;
  std::cout << "append_s = " << append_s << std::endl;
  */
  return 0;
}
