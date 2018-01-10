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
  StrBlobPtr s = *this;     // 保存当前值备份
  // ++curr;
  ++*this;                   // 后置递增以前置递增为基础 
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
  // -- ------ test forward increment --------
  std::cout << "-- ------ test forward increment -------- --" << std::endl;
  s.operator++();   // 显式调用前置递增
  s.print_curr();
  ++s;              // 重载前置递增后的调用
  s.print_curr();
  
  // -- ------ test backward increment --------
  std::cout << "-- ------ test back increment -------- --" << std::endl;
  s.operator++(1).print_curr();   // 显式调用后置递增
  (++s).print_curr();             // 前置递增
  (s++).print_curr();             // 后置递增
  std::cout << "(s++).curr_i = " << (s++).curr_i << std::endl;
  s.print_curr();
  return 0;
}

/* $ ./a.out
-- ------ test forward increment -------- --
curr = 6
curr_i = 6
curr = 7
curr_i = 7
-- ------ test back increment -------- --
curr = 7
curr_i = 7
curr = 9
curr_i = 9
curr = 9
curr_i = 9
(s++).curr_i = 10
curr = 11
curr_i = 11
 */
