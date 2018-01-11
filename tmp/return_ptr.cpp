/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:vector_ordered.cpp
   Date:Thu Jan 11 22:05:13 CST 2018
   -----------------------------
*/


/*
  为什么不能返回函数内部定义的指针
 */

// 起因
// 唯一化(低效)
// Rank* deduplicate_lower();


// int* f() {
//   int iarr[] = {};
//   iarr[0] = 2;
//   return iarr;
// }
// warning: address of local variable ‘iarr’ returned [-Wreturn-local-addr]
// 不能返回函数内部的指针

int* f1(int* iarr) {
  *iarr += 1;
  return iarr;
}

// 将指针作为参数, 可以在修改指针后返回, 但既然是指针, 还有什么返回的必要??

void call_f1() {
  int iarr[] = {0, 3};
  f1(iarr);
}

int main() {
  // f();
  call_f1();
  return 0;
}

