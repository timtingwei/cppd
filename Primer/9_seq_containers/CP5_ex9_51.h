/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_51.h
    Date:Sat Jun 30 21:47:33 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_51_h
#define CP5_ex9_51_h

#include <iostream>
#include <string>

using std::vector; using std::string;

class Date {
 public:
  Date() = default;

  explicit Date(const string &date);
 private:
  unsigned _year, _month, _day;
};

inline Date::Date(const string &date) {
  // January 1, 1900;  1/1/1900;  Jan 1 1900;
  vector<string> svec{"January", "Febuary", "March", "April", "May", "June",
          "July", "August", "September", "October", "November", "December"};
  vector<string> svec_simp = {};
  for (auto it = svec.cbegin(); it != svec.cend(); it++) {
    svec_simp.push_back(it->substr(0, 3));
  }
  
  if (date.find(",") != string::npos) {  // first condition
    // convert month
    for (int i = 0; i < svec.size(); i++) {
      if (date.find(svec[i]) != string::npos) {  // find the month
        _month = i + 1;
        break;
      }
    }
    // convert day
    auto day_begin = date.find_first_of("0123456789");
    auto day_end = date.find(",");
    string day_s = date.substr(day_begin, day_end - day_begin);
    _day = std::stoi(day_s);
    // convert year
    auto pos_space = date.rfind(" ");
    _year = std::stoi(date.substr(pos_space, date.size() - pos_space));
  } else if (date.find("/") != string::npos) {  // second condition
    // get / position
    vector<size_t> pos_vec = {};
    auto pos = date.find_first_of("/");
    while ((pos = date.find_first_of("/", pos)) != string::npos) {
      pos_vec.push_back(pos);
      pos++;
    }
    // convert day
    _day = std::stoi(date.substr(pos_vec[0] + 1, pos_vec[1]));
    // convert month
    _month = std::stoi(date.substr(0, pos_vec[0]));
    // convert year
    _year = std::stoi(date.substr(pos_vec[1] + 1, date.size()));
  } else {  // third condition
    // get space position
    vector<size_t> pos_vec = {};
    auto pos = date.find_first_of(" ");
    while ((pos = date.find_first_of(" ", pos)) != string::npos) {
      pos_vec.push_back(pos);
      pos++;
    }
    // convert day
    _day = std::stoi(date.substr(pos_vec[0] + 1, pos_vec[1]));
    // convert month
    for (int i = 0; i < svec_simp.size(); i++) {
      if (date.substr(0, pos_vec[0]) == svec_simp[i]) {
        _month = i + 1; break;
      }
    }
    // convert year
    _year = std::stoi(date.substr(pos_vec[1] + 1, date.size()));
  }
  
  std::cout << "_year = "  << _year << " "
            << "_month = " << _month << " "
            << "_day = "   << _day << std::endl;
}

/*
  input:
  Date("January 22, 888xo");
  Date("12/03/1900");
  Date("Feb 2 1996");
  
  ./a.out:
  _year = 888 _month = 1 _day = 22
  _year = 1900 _month = 12 _day = 3
  _year = 1996 _month = 2 _day = 2
*/

#endif

