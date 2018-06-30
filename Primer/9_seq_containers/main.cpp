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
#include "CP5_ex9_49.h"

using std::list; using std::vector;
using std::string;

int main() {
  vector<string> words = {"understanding", "misunderstanding", "give", "emacs",
                          "happy", "architecture", "computer", "science",
                          "amused", "cart", "income", "shave", "fretful",
                          "stir", "hurried", "list", "pot", "ambiguous",
                          "remove", "tent"};
  string result = max_length_words(words);
  std::cout << "result_word is -> " << result << std::endl;
  return 0;
}
