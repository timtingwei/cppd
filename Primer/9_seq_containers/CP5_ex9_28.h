/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_28.h
    Date:Sat Jun 23 10:41:13 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_28_h
#define CP5_ex9_28_h

#include <iostream>
#include <forward_list>
#include <string>

using std::forward_list; using std::string;

void insert_string_to_flst(forward_list<string> &s_flist, const string &s1, const string &s2) {
  // forward_list<string> s_flist = {"abc", "tim", "cooper", "tim", "hello", "tim"};
  // string s1 = "tim";
  // string s2 = "<is cool>";
  auto curr = s_flist.begin();
  bool is_find = false;
  while (curr != s_flist.end()) {
    if (*curr == s1) {  // find s1 in forward_list
      curr = s_flist.insert_after(curr, s2);  // insert after curr
      is_find = true;   // sign to find
    } else {
      curr++;
    }
  }

  if (!is_find) {  // s1 not in s_flist
    s_flist.insert_after(s_flist.end(), s2);
  }

  for (auto it = s_flist.cbegin(); it != s_flist.cend(); it++) {
    std::cout << *it << " ";
  }
  std::cout << std::endl;

  /*
    ./a.out
    abc tim <is cool> cooper tim <is cool> hello tim <is cool> 
  */
}
#endif

