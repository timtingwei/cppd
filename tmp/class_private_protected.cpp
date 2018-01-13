/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_private_protected.cpp
   Date:Sat Jan 13 12:52:49 CST 2018
   -----------------------------
*/
#include <iostream>

/*
  protected能否被实例对象访问?
  protected能否被继承类访问?
 */

class Base {
 private:
  int i = 0;
  void f_priv() {std::cout << "calling f_priv() in private" << std::endl;}
 protected:
  void f_prot() {std::cout << "calling f_prot() in protected" << std::endl;}
 public:
  void f() {
    std::cout << "calling f() in public" << std::endl;
    f_prot();
  }
};

class Derived : Base {
 public:
  void call_f_prot() {f_prot();}
  // void call_f_priv() {f_priv();}    // private不能被继承类直接访问
};

int main() {
  Base b;
  Derived d;
  // b.f_prot();      // protected成员不能被实例对象直接访问
  d.call_f_prot();    // 通过继承类的public成员, 访问基类的protected
  // d.call_f_priv();

  return 0;
}

