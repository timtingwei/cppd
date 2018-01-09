/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:increment_and_decrement_operators.cpp
   Date:Tue Jan  9 18:22:42 CST 2018
   -----------------------------
*/
#include <iostream>


class StrBlobPtr {
  std::size_t curr;
 public:
  int curr_i = 5;
  StrBlobPtr& operator++();      // 前置运算符
  StrBlobPtr& operator--();
  StrBlobPtr operator++(int);
  StrBlobPtr(std::size_t c) : curr(c) {}

  void print_curr() const;
};

StrBlobPtr& StrBlobPtr::operator++() {
  ++curr;
  ++curr_i;
  return *this;
}

// 为什么返回*this


StrBlobPtr StrBlobPtr::operator++(int) {    // 后置递增不返回引用类型
  std::cout << "calling back increment ....."
            << "now curr = " << curr << std::endl;
  StrBlobPtr s = *this;     // 保存当前值备份
  std::cout << "s.curr = " << s.curr << std::endl;
  // ++curr;
  ++*this;
  return s;                  // 后置递增, 返回递增前的值
}

// 如果后置递增用的是引用类型, ++*this之后, 改变了s, 返回的s是递增后的s

void StrBlobPtr::print_curr() const {
  std::cout << "curr = " << curr << '\n'
            << "curr_i = " << curr_i << std::endl;
}




int main() {
  std::size_t c = 5;
  StrBlobPtr s(c);
  s.curr_i = 5;
  s.operator++();   // 显式调用前置递增
  s.print_curr();
  ++s;              // 重载前置递增后的调用
  s.print_curr();
  // -- ------ test back increment --------
  std::cout << "-- ------ test back increment -------- --" << std::endl;
  // (++s).print_curr();
  // (s++).print_curr();
  std::cout << "(s++).curr_i = " << (s++).curr_i << std::endl;
  // std::cout << "s++.cerr"(s++).print_curr();
  // s.print_curr();
  
  return 0;
}
