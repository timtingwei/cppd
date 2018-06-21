/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_18.h
   Date:Thu Jun 21 21:01:42 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_18_h
#define CP5_ex9_18_h

#include <iostream>
#include <string>
#include <deque>

using std::string; using std::deque;
using std::cin;

void foo_18() {
  // cin , append sequence of string to deque
  string word;
  deque<string> sdeq;
  while ((cin >> word) && (word != "quit")) {
    sdeq.push_back(word);
  }

  // use loop and iterator for print deque
  for (auto iter = sdeq.cbegin(); iter != sdeq.cend(); iter++) {
    std::cout << *iter << std::endl;
  }
}

#endif



