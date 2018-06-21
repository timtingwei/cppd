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
  
  std::vector<int> ivec = {0, 1, 2, 3};
  int i = 5;
  ivec.push_back(i);
  
  string s = "tim";
  s.push_back('H');
  std::cout << "s = " << s << std::endl;
  s += 'U';
  std::cout << "s = " << s << std::endl;

  std::list<int> ilist;
  for (size_t ix = 0; ix != 4; ix++)
    ilist.push_front(ix);  // equal to : ilist.insert(ilist.begin(), ix);

  for (auto iter = ilist.cbegin(); iter != ilist.cend(); iter++)
    std::cout << *iter << std::endl;

  auto iter = ilist.end();
  ilist.insert(iter, 5);
  
  for (auto iter = ilist.cbegin(); iter != ilist.cend(); iter++)
    std::cout << *iter << std::endl;

  ilist.insert(ilist.end(), {11, 22, 33, 44});
  for (auto iter = ilist.cbegin(); iter != ilist.cend(); iter++)
    std::cout << *iter << std::endl;

  ilist.insert(ilist.begin(), ilist.begin(), ilist.end());
  for (auto iter = ilist.cbegin(); iter != ilist.cend(); iter++)
    std::cout << *iter << std::endl;

  list<string> lst;
  string word;
  auto iter_s = lst.begin();
  while (std::cin >> word) {
    iter_s = lst.insert(iter_s, word);
    std::cout << *iter_s << std::endl;
  }
  return 0;
}
