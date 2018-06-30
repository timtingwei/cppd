/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_50.h
    Date:Sat Jun 30 21:34:06 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_50_h
#define CP5_ex9_50_h

#include <iostream>
#include <string>

using std::vector; using std::string;

int sum_strings_int(const vector<string> &svec) {
  int rst = 0;
  auto it = svec.begin();
  while (it != svec.end()) {
    rst += stoi(it->substr(it->find_first_of("+-0123456789")));
    it++;
  }
  std::cout << "result = " << rst << std::endl;
  return rst;
}

double sum_strings_double(const vector<string> &svec) {
  double rst = 0.0;
  auto it = svec.begin();
  while (it != svec.end()) {
    rst += stod(it->substr(it->find_first_of("+-.0123456789")));
    it++;
  }
  std::cout << "result = " << rst << std::endl;
  return rst;
}


/*
  input:
  vector<string> svec = {"2", "3", "19", "-11", "int = 3"};
  vector<string> svec1 = {"2.11", "3.11", ".12", "0.233"};
  sum_strings_int(svec);
  sum_strings_double(svec1);

  ./a.out:
  result = 16
  result = 5.573
*/

#endif

