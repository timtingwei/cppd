// Copyright <2017> [Tim Hu]

#include <iostream>

// 对三个数进行排序

void compare_swap(int &a, int &b);
void compare_swap_ptr(int* a, int* b);
void print_array(int* a, int n);


void compare_swap(int &a, int &b) {
  // 比较大小甚至交换
  if (a > b) {
    int t = a;
    a = b;
    b = t;
  }
}

void compare_swap_ptr(int* a, int* b) {
  // 比较大小并交换
  if (*a > *b) {
    int t = *a;
    *a = *b;
    *b = t;
  }
}

void sort(int* A, int n) {
  // 输入一个数组A以及它的规模n， 返回从小到大排序的数组A
  for (int i = 0; i< n-1; i++) {
    for (int j = i + 1; j < n; j++) {
      compare_swap(A[i], A[j]);
    }
  }
}



void print_array(int* A, int n) {
  for (int i = 0; i < n; i++)
    std::cout << A[i] << std::endl;
}

int main() {
  int v1 = 5; int v2 = 3;
  compare_swap(v1, v2);
  // std::cout << "v1 = " << v1 << " v2 = " << v2 << std::endl;
  int A[] = {2, 5, 3};    // 定于用于排序的三个数的数组
  int A_tmp[] = {4, 6, 3, 1, 2, 5};
  int n = 3;
  int n_tmp = 6;
  // sort(A, n);
  // print_array(A, n);

  sort(A_tmp, n_tmp);
  print_array(A_tmp, n_tmp);

  /*
  int A_tmp[] = {4, 6, 3, 1, 2, 5};
  int n = 5;
  sort(A_tmp, n);
  
  */
  return 0;
}
