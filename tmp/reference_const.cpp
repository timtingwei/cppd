/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:reference_const.cpp
   Date:Sat Jan 13 13:52:05 CST 2018
   -----------------------------
*/
#include <iostream>

/*
`T const&, const T&, T& const, T const*, const T*, T* const` 辨析
 */

/* 问题
Vector(T* const A, Rank lo, Rank hi)           // 数组区间复制
Vector(Vector<T> const& V, Rank lo, Rank hi)   // 向量区间复制
*/

void f();
void f1(int const&);            // const放在引用type的左右效果一样
void f2(const int&);
// void f3(const int& const);   // error,
// void f4(const int const&);   // error

void f() {
  int a = 0, b = 1;
  const int ca = 0, cb = 1;

  int& ref_a = a;      // ref_a是整数a的引用类型
  int* ptr_a = &a;     // ptr_a是指向整数a的指针
  const int* ptr_ca = &ca;           // ptr_ca是指向常量整型的指针
  const int* const cptr_ca = &ca;    // cptr_ca是指向常量整型的常量指针
  int const& cref_a = a;             // cref_a是对整型的常量引用?
  const int& cref_a_1 = ca;          // cref_a_1是对整型常量引用?
  // const int& const cref_a_2 = ca;    // 对整型常量的常量引用?
  // const int const& cref_a_3 = ca;    // 还是这样? 对整型常量的常量引用?
  // 引用不能duplicate const
  f1(cref_a);
  // cref_a++;      // read-only    // 两者都是常量引用
  // cref_a_1++;    // read-only

  // 引用指针
  int* const& cref_ptra = ptr_a;            // 对整型指针的常量引用
  // int const& cref_ptra_1 = ptr_a;        // 错误: 引用对象类型int*
  const int* const& cref_ptrca = ptr_ca;    // 对指向常量指针的常量引用
  // int* const& cref_ptrca_1 = ptr_ca;     // 错误: 引用对象类型const int*
  const int* const& cref_cptrca = cptr_ca;

  (*cref_ptra)+=1;          // cref_ptra整型指针的常量引用, 改变指向整型
  // (*cref_cptrca)+=1;     // ERROR: 无法通过引用, 改变指向常量的常量指针指向的整数(常量)
}

// 常量引用的写法. 所引用的对象类型为type
// (type) const& ref_t;      // const&写在右边是因为侧重于表明其常量指针
// (const int) const ptr_ci and (int) const& cref_i

void f1(int const& ic) {
  std::cout << "calling f1()...\n";
}


int main() {
  f();

  return 0;
}

