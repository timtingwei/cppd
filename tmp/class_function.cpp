/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_function.cpp
   Date:Wed Jan 10 08:50:01 CST 2018
   -----------------------------
*/

/*
  函数对象, 对象实现函数的功能
 */

#include <iostream>

// 定义一个函数对象
class Sum{
 public:
  int sum = 0;
  void operator()(int iarr[], int n) {
    for (int i = 0; i < n; i++)
      sum += iarr[i];
    std::cout << "sum = " << sum << std::endl;
  }
};

// 函数对象作为另一个函数的形参
template <typename CLS>
void f(CLS & c) {
  int iarr[] = {3, 6, 9};
  int n = 3;
  c(iarr, n);
}

template <typename T>
class Vector {
 private:
  T* _elem; int _size; int _capacity;
 public:
  // 构造函数
  Vector<T>(T* tarr, int lo, int hi) {
    copyFrom(tarr, lo, hi);
  }
  // 函数调用时候不带类型
  // 复制函数
  void copyFrom(T* tarr, int lo, int hi) {
    _elem = new T[_capacity = 2*(hi - lo)];
    _size = hi - lo;
    std::cout << "*tarr = " << tarr[1] << std::endl;
    std::cout << "*_elem = " << *_elem << std::endl;
    for (int i = 0; i < _size; i++) {*(_elem+i) = tarr[i];}
  }

  // 为什么一定要为_elem分配空间?
  // 寻秩访问
  void operator[](int i) const {return *(_elem+i);}
  // 遍历操作
  template <typename VST> void traverse(VST visit);
  // 重载后置++
  void operator++(int);

  void print_vector() const {
    std::cout << "-- ---------print vector------- -- " << std::endl;
    std::cout << "_size = " << _size << std::endl;
    for (int i = 0; i < _size; i++)
      std::cout << "_elem[" << i << "] = " << _elem[i] << std::endl;
  }
};

template <typename T> template <typename VST>
void Vector<T>::traverse(VST visit) {
  // 对每个元素执行visit操作
  for (int i = 0; i < _size; i++) {visit(_elem[i]);}
}

// 为什么不能用引用类型?
// no known conversion for argument 1 from ‘Increase<int>’ to ‘Increase<int>&’

/*
template <typename T>
void Vector<T>::operator++(int) {
  for (int i = 0; i < _size; i++) {*(_elem + i)++;}
}
*/



template <typename T>
struct Increase {     // Increase对象即是visit对应的操作
  void operator()(T& e) {e++;}    // T类型已经重载++符号, T对应的是*_elem的类型int
};



/*
template <typename T>
void increase(Vector<T> V) {
  V.traverse(Increase(T& e));
}
*/
template <typename T>
void increase(Vector<T> V) {
  V.traverse(Increase<T>());
}


int main() {
  // ..
  // f();

  // Sum()
  Sum s;
  int iarr[] = {1, 2, 3, 4, 5, 7};
  int n = 6;
  s(iarr, n);

  Sum s1;
  f(s1);

  int lo = 0, hi = 6;
  Vector<int> v(iarr, lo, hi);
  v.print_vector();
  increase(v);
  v.print_vector();
  return 0;
}
