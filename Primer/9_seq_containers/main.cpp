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
#include "CP5_ex9_51.h"

using std::list; using std::vector;
using std::string;

int main() {
  Date();
  Date("January 22, 888xo");
  Date("12/03/1900");
  Date("Feb 2 1996");
  // January 1, 1900;  1/1/1900;  Jan 1 1900;
  string s("abcs");
  auto new_s = s.replace(0, 2, "abc");
  std::cout << s << std::endl;
  std::cout << new_s << std::endl;

  return 0;
}
