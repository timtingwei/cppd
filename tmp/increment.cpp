/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:increment.cpp
   Date:Tue Jan  9 16:11:20 CST 2018
   -----------------------------
*/

#include <iostream>
/*
在同if, for, while中, 对某一变量i后置递增, i前后不变
在同一行中, 对某一变量i后置递增, i上一句和这一句产生变化
 */


bool equal(int a, int b) {
  // std::cout << "arr[ " << i << " ] = " << arr[i] << std::endl;
  std::cout << "a = " << a << ", b = " << b << std::endl;
  return a == b;
}

void f() {
  std::cout << "---- test in same if statement----" << std::endl;
  int i = 1;
  int arr[] = {0, 1, 2, 3, 4};
  // 在同if, for, while中, 对某一变量i后置递增, i前后不变
  if (equal(i++, arr[i])) std::cout << "equal\n"
                                    << "now i = " << i << std::endl;
}

void f2() {
  std::cout << "---- test in same line ------" << std::endl;
  int i = 5;
  i++; std::cout << "i = " << i << std::endl;
}


int main() {
  // ..
  std::cout << "runing main()...." << std::endl;
  f();
  f2();
  return 0;
}

/*
runing main()....
---- test in same if statement----
a = 1, b = 1
equal
now i = 2
---- test in same line ------
i = 6
*/
