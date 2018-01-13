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

void f2() {
  int a = 0, b = 0, c = 0, d = 0;
  int* p_a = &a;                 // 指向int的指针
  // 指针地址可变, 指向的a可变
  (*p_a)++; p_a = &b;
  std::cout << "*p_a = " << *p_a << ", a = " << a << std::endl;
  const int* p_b = &b;          // 指向const int的指针
  // 指针地址可变, 指向的元素转换成const不可变
  // *(const_cast<int*>(p_b))+=1;
  // (*p_b)++;
  p_b = &c;
  std::cout << "*p_b = " << *p_b << ", b = " << b << std::endl;
  int* const cp_c = &c;          // 指向int的const指针
  // 指针地址不可变, 指向的元素可以变
  (*cp_c)++;
  // cp_c = &d;
  std::cout << "*cp_c = " << *cp_c << ", c = " << c << std::endl;
  // int const* cp_c1 = &c;         // 指向const int的指针, 仍采用上种方法
  const int* const cp_cd = &d;   // 指向const int的const指针
  // 指针地址不可变, 指向值不可变
  // (*cp_cd)++;
  // cp_cd = &a;
  std::cout << "*cp_cd = " << *cp_cd << ", d = " << d << std::endl;
}

void f3() {
  int a = 0;
  // int& const cref_a = a;   // const qualifiers cannot be applied to "int&"
}

int main() {
  // f();
  // f2();

  return 0;
}

