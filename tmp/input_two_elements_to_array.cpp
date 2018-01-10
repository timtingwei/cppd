/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:input_two_elements_to_array.cpp
   Date:Wed Jan 10 11:41:45 CST 2018
   -----------------------------
*/

/*
receive two numbers from the keyboard, save them in an array of two element?
*/

#include <iostream>
void revise_value_int(int* arr, int n);
void call_revise();
void revise_value_ptr(int** ptrArr, int n);
// void revise_value_ptr(int* ptrArr, int n);

void f0() {     // ERROR: 先存放再输入不会修改数组中的数据
  int a, b;
  int iarr[2] = {a, b};
  std::cin >> a >> b;   // 不合理:先存放, 再输入
  std::cout << iarr[0] << ' ' << iarr[1] << std::endl;
  // 4197661 0
}

void f1() {
  int iarr[2] = {};
  std::cin >> iarr[0] >> iarr[1];
  std::cout << iarr[0] << ' ' << iarr[1] << std::endl;  // 直接输入到数组中
}

void f2() {
  int a, b;
  std::cin >> a >> b;     // 先输入, 再存放
  int iarr[2] = {a, b};
  std::cout << iarr[0] << ' ' << iarr[1] << std::endl;
}

void f3() {  // BUG: 为什么不能通过数组中保存的指针修改数组??
  int *pa, *pb;
  int* iarr[2] = {pa, pb};
  int tmp_a, tmp_b;
  std::cin >> tmp_a >> tmp_b;        // 存放到临时变量
  pa = &tmp_a; pb = &tmp_b;
  std::cout << "*pa = " << *pa << std::endl;    // *pa = 1
  std::cout << *(*iarr) << std::endl;
  std::cout << *(iarr[0]) << ' ' << *(iarr[1]) << std::endl;
}

void f4() {
  int a, b;
  int *pa = &a, *pb = &b;
  int* iarr[2] = {pa, pb};
  std::cin >> a >> b;                      // 存放到临时变量
  std::cout << *(iarr[0]) << ' ' << *(iarr[1]) << std::endl;
}

// 创建一个函数, 输入一个保存指向整数的数组, 修改保存的值,

void revise_value_int(int* arr, int n) {
  // 索引为n指向的整数递增1
  (*(arr+n)) += 1;
}

void call_revise() {
  int iarr[] = {0, 1, 2};
  revise_value_int(iarr, 2);
  std::cout << "iarr[2] = " << iarr[2] << std::endl;
  int a = 0, b = 1, c = 2;
  int *pa = &a, *pb = &b, *pc = &c;
  int* ptrArr[] = {pa, pb, pc};      // 存放指针的数组!! int* arr[] = {};
  // std::cout << "*(ptrArr[2]) = " << *(ptrArr[2])<< '\n';
  std::cout << "*(ptrArr[0]) = " << *(ptrArr[0])<< std::endl;
  std::cout << "**ptrArr = " << **ptrArr << std::endl;
  std::cout << "**(ptrArr+1) = " << **(ptrArr+1) << std::endl;
  std::cout << "**(ptrArr+2) = " << **(ptrArr+2) << std::endl;
  // std::cout << "**(ptrArr+3) = " << **(ptrArr+3) << std::endl;  // Error: Overflow
  revise_value_ptr(ptrArr, 2);    // 修改索引为2位置的指针指向的整数
  std::cout << "*(ptrArr[2]) = " << *(ptrArr[2]) << std::endl;
}


// 创建一个函数, 输入一个保存指向整数的指针的数组, 修改指针所指向的值, 返回
void revise_value_ptr(int** ptrArr, int n) {
  // 索引为n的指向的指针所指向的整数递增1
  (**(ptrArr+n))+=1;
  std::cout << "revise....\n"
            <<"*(ptrArr[n])" << *(ptrArr[n]) << std::endl;
}

// Segmentation fault (core dumped) 指针指向的位置未定义

void f5() {  // DEBUG: 为什么不能通过数组中保存的指针修改数组??
  int a = 3, b = 5;
  int* pa = &a, * pb = &b;
  int* iarr[2] = {pa, pb};
  std::cin >> a >> b;        // 存放到变量
  std::cout << "*pa = " << *pa << std::endl;    // *pa = 1
  std::cout << **iarr << std::endl;             // 1
  std::cout << *(iarr[0]) << ' ' << *(iarr[1]) << std::endl;  // 1 2
}


int main() {
  // f1();
  // call_revise();
  f5();
  return 0;
}

