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
#include "CP5_ex9_28.h"

using std::vector; using std::list;
using std::string;

int main() {
  forward_list<string> s_flist = {"abc", "tim", "cooper", "tim", "hello", "tim"};
  string s1 = "tim";
  string s2 = "<is cool>";
  insert_string_to_flst(s_flist, s1, s2);

  return 0;
}
