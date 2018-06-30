/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_47.h
    Date:Sat Jun 30 16:35:16 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_47_h
#define CP5_ex9_47_h

#include <iostream>
#include <string>

using std::vector; using std::string;

void find_number(const string &s) {
  // use find_first_of
  // s = "ab2c3d7R4E6";
  if (!s.size()) {
    std::cout << "parameter size error\n";
    return;
  }

  string numbers = "0123456789";
  auto pos = s.find_first_of(numbers);
  while ((pos = s.find_first_of(numbers, pos)) != string::npos) {
    std::cout << "number element pos = " << pos << std::endl;
    pos++;
  }
}

void find_letter(const string &s) {
  // use find_first_of_not
  // s = "ab2c3d7R4E6";
  if (!s.size()) {
    std::cout << "parameter size error\n";
    return;
  }

  string numbers = "0123456789";
  auto pos = s.find_first_not_of(numbers);
  while ((pos = s.find_first_not_of(numbers, pos)) != string::npos) {
    std::cout << "letter element pos = " << pos << std::endl;
    pos++;
  }
}
#endif

