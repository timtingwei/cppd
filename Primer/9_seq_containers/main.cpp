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
#include <forward_list>
#include <deque>
#include <string>

// using std::vector; using std::list; using std::deque; using std::forward_list;
// using std::string;

int main() {
  std::vector<int> ivec(10, -1);
  std::list<std::string> svec(5, "tim");
  std::forward_list<int> fivec(10);
  std::deque<std::string> dsvec(10);

  std::cout << "*(fivec.begin()) = " << *(fivec.begin()) << std::endl;
  std::cout << "*(svec.begin()) = " << *(dsvec.begin()) << std::endl;

  return 0;
}
