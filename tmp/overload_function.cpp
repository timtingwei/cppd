/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:overload_function.cpp
   Date:Thu Jan 11 16:10:42 CST 2018
   -----------------------------
*/
/*
  重载函数什么时候用virtual?
 */

#include <iostream>


// 函数重载 和 virtual是两个概念, virtual是虚拟的意思, 虚函数.

class MyClass_override {
  int i = 5;
 public:
  void print_i() {std::cout << "in print() i = " << i << std::endl;}
  virtual void print_i(int new_i) {   // 这里, 使用virtual与否都是一样的
    i = new_i;
    std::cout << "in print(int) i = " << i << std::endl;
  }

};


void f_override() {
  MyClass_override c;
  c.print_i();
  c.print_i(7);
}

// ===================== split line ==================================

// virtual, override 解释
struct Base {    // 声明virtual后, 可被继承类override重载
  void print() {std::cout << "Base\n";}
};

struct Derived : Base {   // 'override'可写可不写
  void print() {std::cout << "Derived\n";}
};

void f_virtual() {
  Base b;
  Derived d;

  Base& br = b;      // refer b, br的类型是Base&
  Base& dr = d;      // dr类型也是Base&
  br.print();        // Base
  dr.print();        // Derived

  Base* pb = &b;     // pointer to b, Base*
  Base* pd = &d;     // Base* as well

  pb->print();       // Base
  pd->print();       // Derived

  b.Base::print();   // Base
  d.Base::print();   // Base
}

// =========================== split line ===========================


// 函数对象用virtual声明operator()()
struct Increase {
  // 重载()后, 对象可充当函数的功能
  virtual void operator()(int* e) {(*e)++;}
};

struct Increase_two : Increase {
  void operator()(int* e) override {(*e)+= 2;}    // 元素+2;
};



void f_increase() {
  Increase a;
  Increase_two b;

  Increase& ra = a;
  Increase& rb = b;     // rb的类型为 Increase&

  int e = 5; int* pe = &e;
  ra.operator()(pe);
  std::cout << "e = " << e << std::endl;    // prints "e = 6"
  int e2 = 5; int* pe2 = &e2;
  rb.operator()(pe2);   // 调用基类的引用时, 动态绑定到Increase_two中的方法
  std::cout << "e2 = " << e2 << std::endl;  // prints "e2 = 7"
}

int main() {
  // f_override();
  // f_virtual();
  f_increase();
  return 0;
}

