/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:bool_int_convert.cpp
   Date:Fri Jan 12 09:55:26 CST 2018
   -----------------------------
*/

/*
bool隐式转换为int
boolu转换成其他类型
 */
#include <iostream>

// bool -> 其他类型
// 初始值false为0, true为1
void f_to_other_type() {
  bool b = true, b2 = false;
  int i = b, i2 = b2;
  std::cout << "i = " << i << std::endl;    // prints "i = 1"
  std::cout << "i2 = " << i2 << std::endl;  // prints "i2 = 0"
  char c = b;
  std::cout << "c = " << c << std::endl;    // prints "c = "
  unsigned int un = b;
  std::cout << "un = " << un << std::endl;    // prints "un = 1"
}


// 其他类型 -> bool
// 非布尔值转换成布尔值, 初始值非0为true, 初始值为0和空指针为false;
void f_to_bool() {
  int i1 = 5, i2 = 0;
  int* pi0 = 0;       // 定义空指针
  int* pi1 = &i1;      // 指针指向i1
  int& ri0 = i2;      // 引用i2, i2的值为0
  int& ri1 = i1;      // 引用i1

  bool bi = i1;        // prints  bi = 1
  bool bpi0 = pi0;     // prints  bpi0 = 0
  bool bpi1 = pi1;     //         bpi1 = 1
  bool bri0 = ri0;     //         bri0 = 0
  bool bri1 = ri1;     //         bri1 = 1
  std::cout << "bi = " << bi << '\n'
            << "bpi0 = " << bpi0 << '\n'
            << "bpi1 = " << bpi1 << '\n'
            << "bri0 = " << bri0 << '\n'
            << "bri1 = " << bri1 << std::endl;
}

void f() {
  int arr1[] = {0, 1, 3, 4};
  int arr2[] = {0, 2, 3, 1};
  int n = 4;
  int count = 0;
  for (int i = 0; i < n; i++) {count += (arr1[i] != arr2[i]);}
  std::cout << "count = " << count << std::endl;   // prints count = 2
}

void f_size() {
  std::cout << "sizeof(bool) = " << sizeof(bool) << std::endl;
}

// 判断结果作为右值, 赋给左值int。


int main() {
  // ...
  f();
  f_to_bool();
  f_size();
  return 0;
}
