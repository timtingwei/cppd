/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:template_specialization.cpp
   Date:Wed Jan 10 18:59:09 CST 2018
   -----------------------------
*/
#include <iostream>

/*
mycontainer类, 保存一个元素element, 只有一个increase方法递增element
特殊化:
如果T为char, 实现uppercase(), 大写化这个char 
*/

template <typename T>
class mycontainer {
  T element;
 public:
  mycontainer(const T e) : element(e) {}
  T increase() {return ++element;}    // 递增element
  T getElement() const {return element;}   // 返回element数据
};


template <>
class mycontainer<char> {
  char element;
 public:
  mycontainer(const char e): element(e) {}
  char increase() {return ++element;}    // 递增char
  char getElement() const {return element;}   // 返回element数据
  char uppercase() {
    if (element <= 'z' && element >= 'a') {   // 是小写字母
      element += 'A' - 'a'; return element;
    }  // 返回元素
    std::cout << "element " << element << "is not lower" << std::endl;
    return element;
  }
};




template <typename T>
void print_ele(mycontainer<T> e) {
  std::cout << "element = " << e.getElement() << std::endl;
}

// 当一个函数中要用当泛型之后, 在这之前一定要template声明

void f() {
  // ..
  mycontainer<char> mcchar('t');
  mcchar.increase();
  print_ele(mcchar);      // element = u
  mcchar.uppercase();
  print_ele(mcchar);      // element = U
  mycontainer<int> myint(44);
  myint.increase();
  print_ele(myint);       // element = 45
  // myint.uppercase();   // T = int 类型时, 没有uppercase()
}

void f_char() {
  char c = 's';
  c++;
  std::cout << "c = " << c << std::endl;   // c = t;
  c += 'A' - 'a';
  std::cout << "c = " << c << std::endl;   // c = T;
}

int main() {
  f();
  // f_char();
  return 0;
}
