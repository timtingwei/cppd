/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_42.h
    Date:Sat Jun 23 23:44:44 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_42_h
#define CP5_ex9_42_h

#include <iostream>
#include <string>

using std::vector; using std::string;

string init_str(string &s) {
  // ..
  s.reserve(100);
  char ch;
  while (std::cin >> ch && ch != 'q') {
    s.push_back(ch);
  }
  
  std::cout << s << std::endl;

  return s;
}

/*
  ./a.out
  timcool
*/

#endif

