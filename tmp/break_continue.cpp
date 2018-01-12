/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:break_continue.cpp
   Date:Fri Jan 12 12:08:57 CST 2018
   -----------------------------
*/

#include <iostream>

void f_break() {
  // loop, or switch终止
  for (int i = 0; i < 5; i++) {
    if (i == 3) break;
    for (int j = 2; j <7; j++) {
      if (j - i == 2) {break;}
      std::cout << "j - i = " << j - i << std::endl;
    }
  }

  int i = 2;
  switch (i) {
    case 1: std::cout << "1\n";
    case 2: std::cout << "2\n";
    case 3: std::cout << "3\n";
    case 4:
    case 5: std::cout << "45 \n";
      break;
    case 6: std::cout << "6\n";
  }
  // -------
  // 2
  // 3
  // 45
}

void f_continue() {
  // 跳过loop剩余部分
  for (int i = 0; i < 5; i++) {
    for (int j = 2; j <7; j++) {
      if (j - i == 2) {
        std::cout << "j-i = 2" << std::endl;
        continue;}
      // ...
      std::cout << "after continue " << std::endl;
    }
  }
}

int main() {
  // ..
  f_break();
  // f_continue();
  return 0;
}

