/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_19.h
   Date:Thu Jun 21 21:11:44 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_19_h
#define CP5_ex9_19_h

#include <iostream>
#include <string>
#include <list>

using std::string; using std::list;
using std::cin;

void foo_19() {
  // cin , append sequence of string to deque
  string word;
  list<string> slist;
  auto iter_list = slist.begin();
  while ((cin >> word) && (word != "quit")) {
    // slist.push_back(word);
    // slist.push_front(word);
    // slist.insert(slist.end(), word);
    // slist.insert(slist.begin(), word);
    iter_list = slist.insert(iter_list, word);
    // that's all right for std::list
  }

  // use loop and iterator for print deque
  for (auto iter = slist.cbegin(); iter != slist.cend(); iter++) {
    std::cout << *iter << std::endl;
  }
}

#endif



