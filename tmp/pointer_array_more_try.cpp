/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:pointer_array_more_try.cpp
   Date:Wed Jan 10 14:23:51 CST 2018
   -----------------------------
*/

/*
存放不同长度数组(指针)的数组(指针)
存放对象的数组(指针)
存放不同函数的数组(指针)
*/

#include <iostream>
template <typename T> class Name;
void print_instance_data_in_array(Name<int>* nArr, int size);



/*
int* convert_size_structor(int** size_arr) {
  // {{3}, {1, 3, 2}} =>
  // {{0, 0}, {1, 0}, {1, 1}, {1, 2}, {2, 2}, {2, 3}
  for (int i = 0; i < **size_arr; i++)
    for (int j = 0; j< )
}
*/


void print_arr_b(int*** ppArr) {
  // 解引用并打印ppArr数组中依次数组中的pa, pb, pc
  std::cout << "a0 = " << ***ppArr<< " in pArr1[0]" << '\n'
            << "b0 = " << **(*(ppArr+1)+1)<< " in pArr2[1]" << '\n'
            << "c0 = " << **(*(ppArr+2)+1)<< " in pArr3[1]" << '\n'
            << std::endl;
}


void f_array() {
  int a = 3, b = 5, c = 7;
  int* pa = &a, *pb = &b, *pc = &c;
  int _size_pa = 1, _size_pb = 1, _size_pc = 1;
  int* pArr1[] = {pa};    // pArr1数组存放pa, pb指针
  int _size_pArr1 = 1;
  int* pArr2[] = {pa, pb, pc};    // pArr2数组存放pa, pb, pc指针
  int _size_pArr2 = 3;
  int* pArr3[] = {pa, pc};
  int _size_pArr3 = 2;
  int size_pArr[] = {1, 3, 2};
  int** ppArr[] = {pArr1, pArr2, pArr3};   // ppArr存放3个指针数组
  int _size_ppArr = 3;
  int size_ppArr[] = {3};
  int* size_arr[] = {size_ppArr, size_pArr};
  // convert_size_structor(size_arr);
  print_arr_b(ppArr);
}


template <typename T>
class Name {
  char* _c; int _length; int _capacity;
 public:
  Name(char* c, int length): _c(c), _length(length) {}
  char* getName() const;
  int getLength() const;
};

template <typename T>
char* Name<T>::getName() const {
  return _c;
}

template <typename T>
int Name<T>::getLength() const {
  return _length;
}



void class_array() {
  char c1[] = {'t', 'i', 'm'};
  char c2[] = {'h', 'u'};
  int length1 = 3, length2 = 2;
  Name<int> name1(c1, length1), name2(c2, length2);
  Name<int> nArr[] = {name1, name2};
  int size = 2;
  print_instance_data_in_array(nArr, size);
}

void f() {
  char c[] = {'t', 'i', 'm'};
  int length = 3;
  Name<int> n(c, length);
}

void print_instance_data_in_array(Name<int>* nArr, int size) {
  for (int i = 0; i < size; i++) {
    std::cout << "Name = ";
    for (int j = 0; j < nArr[i].getLength(); j++) {
      std::cout << *((nArr[i].getName())+j);
    }
    std::cout << "\n";
  }
}


int main() {
  // ..
  // f_array();
  class_array();
  // f();
  return 0;
}

