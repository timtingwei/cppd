/* ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
    File:CP5_ex9_49.h
    Date:Sat Jun 30 17:10:03 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_49_h
#define CP5_ex9_49_h

#include <iostream>
#include <string>

using std::vector; using std::string;


bool not_scender(const string &word) {
  // input a word, output the max not include ascender
  // and not include descender
  // s = "misunderstanding";
  string letter("abcdefghijklmnopqrstuvwxyz");
  if (!word.size()) {
    std::cout << "parameter size error\n";
    return false;
  }

  if ((word.find_first_not_of(letter)) != string::npos) {
    std::cout << "not a word, return false" << std::endl;
    return false;
  }

  string ascender("bdijklt");
  string descender("gjpq");
  if ((word.find_first_of(ascender)) != string::npos
      || (word.find_first_of(descender)) != string::npos) {
    // std::cout << word << " include scender, return false" << std::endl;
    return false;
  } else {
    return true;
  }
}

string max_length_words(const vector<string> &words) {
  string result_word = " ";
  vector<string>::const_iterator it = words.begin();
  while (it != words.end()) {
    if (not_scender(*it)) {  // string is not scender
      if (it -> size() > result_word.size()) result_word = *it;
    }
    it++;
  }
  if (result_word != " ") {
    return result_word;
  } else {
    std::cout << "no match words" << std::endl;
    return result_word;
  }
}

/*
  input:
  vector<string> words = {"understanding", "misunderstanding", "give", "emacs",
                          "happy", "architecture", "computer", "science",
                          "amused", "cart", "income", "shave", "fretful",
                          "stir", "hurried", "list", "pot", "ambiguous",
                          "remove", "tent"};
  string result = max_length_words(words);
  std::cout << "result_word is -> " << result << std::endl;

  ./a.out:
  result_word is -> remove
*/

#endif

