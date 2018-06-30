/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_43.h
    Date:Sat Jun 30 14:34:18 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_44_h
#define CP5_ex9_44_h

#include <iostream>
#include <string>

using std::vector; using std::string;

void expand_words_in_string_by_index(string &s, const string& oldVal, const string& newVal) {
  // accept three params, use insert and erase,
  // replace the oldVal to newVal, but should use index

  // tho -> though, thru -> through
  // string s = "tho tim thru";
  // string oldVal = "tho", newVal = "though";
  if (!s.size() || !oldVal.size() || !newVal.size()) {
    std::cout << "parameter size error\n";
    return;
  }

  int oldVal_size = oldVal.size(), newVal_size = newVal.size();
  int len_diff = newVal_size - oldVal_size;

  s.push_back(' ');
  std::size_t old_i = 0;
  std::size_t curr_i = 0;
  std::size_t orig_size = s.size();
  while (curr_i != s.size()) {
    if (old_i == oldVal.size()) {   // match the oldVal string
      curr_i -= oldVal_size;
      s.replace(curr_i, oldVal_size, newVal);
      curr_i += newVal_size;
      old_i = 0;
    } else {  // finding the oldVal string
      if (s[curr_i] == oldVal[old_i]) {
        old_i++;
      } else {
        old_i = 0;
      }
    }
    curr_i++;
  }

  std::cout << s << std::endl;
}

/*
  input:
  string s = "tho tim thru";
  string oldVal = "thru", newVal = "through";
  expand_words_in_string(s, oldVal, newVal);
  
  ./a.out:
  tho tim through 
*/

#endif

