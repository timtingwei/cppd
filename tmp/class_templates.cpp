/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_templates.cpp
   Date:Wed Jan 10 18:37:05 CST 2018
   -----------------------------
*/
#include <iostream>

template <typename T>
class My_pair {
 private:
  T values[2] = {};
 public:
  My_pair(T first, T second) {
    values[0] = first; values[1] = second;
  }
  void print_values() const {
    std::cout << "values[0] = " << values[0] << '\n'
              << "values[1] = " << values[1] << std::endl;
  }
  T getMax() const;  // 在外部定义
};

template <typename T>
T My_pair<T>::getMax() const {
  return (values[0] < values[1]) ? values[1] : values[0];
}

/*
<typename T> 和 <class T>的区别
 */

void f() {
  int i1 = 3, i2 = 5;
  My_pair<int> myint(3, 5);
  myint.print_values();
  My_pair<float> myfloat(1.22, 3.22);
  myfloat.print_values();
  std::cout << "myfloat.getMax() = " << myfloat.getMax() << std::endl;
}

int main() {
  f();
}
