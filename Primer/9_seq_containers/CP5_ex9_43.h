/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_43.h
    Date:Sun Jun 24 00:31:19 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_43_h
#define CP5_ex9_43_h

#include <iostream>
#include <string>

using std::vector; using std::string;

void expand_words_in_string(string &s, const string& oldVal, const string& newVal) {
  // accept three params, use insert and erase,
  // replace the oldVal to newVal

  // tho -> though, thru -> through
  // string s = "tho tim thru";
  // string oldVal = "tho", newVal = "though";
  if (!s.size() || !oldVal.size() || !newVal.size()) {
    std::cout << "parameter size error\n";
    return;
  }

  int old_same_count = 0;
  auto it_old = oldVal.cbegin(), it_new = newVal.cbegin();
  while ((it_old != oldVal.cend()) && (*it_old == *it_new)) {
    old_same_count++;
    it_old++; it_new++;
  }
  int old_remove_count = oldVal.size() - old_same_count;
  int new_insert_pos = old_same_count;
  int new_insert_count = newVal.size() - old_same_count;

  it_old = oldVal.cbegin();
  s.push_back(' ');
  auto curr = s.begin();
  while (curr != s.end()) {
    if (it_old == oldVal.cend()) {   // match the oldVal string
      curr -= old_remove_count;
      curr = s.erase(curr, curr + old_remove_count);
      curr = s.insert(curr, newVal.cbegin() + new_insert_pos, newVal.cend());
      curr += new_insert_count;
      it_old = oldVal.cbegin();
    } else {  // finding the oldVal string
      if (*curr == *it_old) {
        it_old++; curr++;
      } else {
        it_old = oldVal.cbegin(); curr++;
      }
    }
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

