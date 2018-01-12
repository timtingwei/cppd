/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:if_else_elseif.cpp
   Date:Fri Jan 12 22:42:07 CST 2018
   -----------------------------
*/

#include <iostream>

/*
  if...else 和 if...else if的区别
 */

void f_else() {
  int i = 6;
  if (i == 5) {std::cout << "i = 5" << std::endl;
  } else {
    if (i > 5) {std::cout << "i > 5" << std::endl;
    } else { std::cout << "i < 5" << std::endl;}
  }
}

void f_else_if() {
  int i = 4;
  if (i == 5) std::cout << "i = 5" << std::endl;
  else if (i < 5) std::cout << "i < 5" << std::endl;
  else if (i > 5) std::cout << "i > 5" << std::endl;
}

int main() {
  f_else();
  // f_else_if();
}
