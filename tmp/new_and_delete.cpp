/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:new_and_delete.cpp
   Date:Thu Jan 11 01:04:43 CST 2018
   -----------------------------
*/

#include <iostream>

template <typename T>
class Table {
  T* _elem; int _size; int _capacity;
 public:
  Table(const T* iarr, int lo, int hi) {copyFrom(iarr, lo, hi);}
  void copyFrom(const T* iarr, int lo, int hi);
  void print_elem() const;
};

template <typename T>
void Table<T>::copyFrom(const T* iarr, int lo, int hi) {
  for (int i = lo; i < hi; i++)
    _elem[i] = iarr[i];
  _size = hi - lo;
  _capacity = 2 * _size;
  
}


template <typename T>
void Table<T>::print_elem() const {
  for (int i = 0; i < _size; i++)
    std::cout << "_elem[i] = " << _elem[i] << std::endl;
}
int main() {
  // ..
  int iarr[] = {1, 2, 3, 5};
  int lo = 0, hi = 4;
  Table<int> ti(iarr, lo, hi);
  ti.print_elem();
  return 0;
}
