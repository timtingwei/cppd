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
  list<string> names;
  vector<const char*> oldstyles = {"tim", "cooper"};

  // names = oldstyles;
  names.assign(oldstyles.cbegin(), oldstyles.cend());

  list<int> ilist(1);  // an empty element
  ilist.assign(10, -1);

  for (auto iter = ilist.cbegin(); iter != ilist.cend(); iter++)
    std::cout << *iter << std::endl;

  // equal to
  list<int> ilist1(1);  // an empty element
  ilist1.clear();
  ilist1.insert(ilist1.begin(), 10, -5);

  for (auto iter = ilist1.cbegin(); iter != ilist1.cend(); iter++)
    std::cout << *iter << std::endl;
  
  return 0;
}
