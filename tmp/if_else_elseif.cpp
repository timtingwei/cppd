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

void f_if() {
  int i = 6;
  if (i == 6) std::cout << "i = 6" << std::endl;
  if (i != 7) std::cout << "i != 7" << std::endl;
}

void fun() {
  bool foo = true, bar = true, baz = true;
  if( foo ) {
    // <- this block is only executed if 'foo' is true
    std::cout << "if(foo) <- this block is only executed if 'foo' is true\n";
  }
  else if( bar )  // <- 'bar' is only checked if 'foo' is false
  {
    // <- this block only executed if 'foo' is false and 'bar' is true
    std::cout << "else if(bar) <- this block only executed if 'foo' is false and 'bar' is true\n";
  }
  else
  {
    // <- this block only executed if 'foo' and 'bar' are both false
    std::cout << "else {} <- this block only executed if 'foo' and 'bar' are both false\n";
  }
  if( baz ) // <- no 'else', so previous 'ifs' don't matter
  {
    // <- this block only executed if 'baz' is true.   foo/bar don't matter
    std::cout << "if(baz) <- this block only executed if 'baz' is true.   foo/bar don't matter\n";
  }
}

int main() {
  // f_else();
  // f_else_if();
  // f_if();
  fun();
}
