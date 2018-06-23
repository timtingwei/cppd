/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_41.h
    Date:Sat Jun 23 23:27:40 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_41_h
#define CP5_ex9_41_h

#include <iostream>
#include <vector>
#include <string>

using std::vector; using std::string;

string init_str(const vector<char> &cvec) {
  // vector<char> cvec = {'t', 'i', 'm', 'c', 'o', 'o', 'l', '!'};
  /* my code
  char c_arr[50] = {};
  for (int i = 0; i < cvec.size(); i++) {
    c_arr[i] = cvec[i];
  }
  

  string str(c_arr, cvec.size() - 1);
  */
  std::cout << "*c(vec.data()) = " << *(cvec.data()) << std::endl;
  
  string str(cvec.data(), cvec.size());

  std::cout << str << std::endl;

  return str;
}

/*
  ./a.out

  cvec.data() = t
  timcool
*/

#endif

