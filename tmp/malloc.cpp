/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:malloc.cpp
   Date:Fri Jan 12 11:06:33 CST 2018
   -----------------------------
*/
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

void f() {
  int i, n;
  char* buffer;

  printf("how long do you want the string?");
  scanf("%d", &i);

  buffer = (char*) malloc(i+1);
  if (buffer==NULL) exit(1);

  for (n=0; n < i; n++)
    buffer[n] = rand()%26 + 'a';
  buffer[i] = '\0';

  printf("Random string: %s\n", buffer);
  free(buffer);
}

int* fun() {
  int* i_ptr = (int*) malloc(sizeof(int*));
  for (int i = 0; i < sizeof(int*); i++)
    *(i_ptr+i) = 0;
  // free(i_ptr);
  return i_ptr;    // 函数返回指针
}

/*
int fun_int() {
  int i = (int) malloc(sizeof(int));   // 为指针分配内存
  // free(i);
  return i;
}
*/


int main() {
  //..
  // f();
  int* ptr = fun();
  std::cout << "*ptr = " << *ptr << std::endl;
  // fun_int();
  return 0;
}


