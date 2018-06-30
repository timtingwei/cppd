/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_45.h
    Date:Sat Jun 30 15:27:43 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_45_h
#define CP5_ex9_45_h

#include <iostream>
#include <string>

using std::vector; using std::string;

void company_name(string &s, const string& prefix, const string& suffix) {
  // accept three params, use iter, insert, append,
  // company the name by prefix and suffix

 if (!s.size() || !prefix.size() || !prefix.size()) {
    std::cout << "parameter size error\n";
    return;
  }

  s.insert(s.cbegin(), ' '); s.push_back(' ');

  auto curr = s.begin();
  auto it_pref = prefix.begin();
  while (it_pref != prefix.end()) {
    curr = s.insert(curr, *it_pref);
    curr++; it_pref++;
  }
  s.append(suffix);

  std::cout << s << std::endl;
}

/*
  input:
  string s = "Tim";
  string prefix = "Mr.", suffix = "Jr.";
  company_name(s, prefix, suffix);
  
  ./a.out:
  Mr. Tim Jr.
*/

#endif

