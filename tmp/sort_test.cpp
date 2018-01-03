// Copyright <2017>[Tim Hu]

#include <iostream>

void sort(int A[], int n);
void swap(int &v1, int &v2);
void print_array(int A[], int n);

void sort(int A[], int n) {
  for (int i = 0; i < n-1; i++) {
    for (int j = i+1; j < n; j++)
      swap(A[i], A[j]);
  }
}


void swap(int &v1, int &v2) {
  if (v1 > v2) {
    int tmp = v1;
    v1 = v2;
    v2 = tmp;
  }
}

void print_array(int A[], int n) {
  for (int i = 0; i <= n-1; i++) {
    std::cout << i << " " << A[i] << std::endl;
  }
}

int main() {
  int A[] = {3, 4, 5, 2, 1};
  int n1 = 3, n2 = 5;
  swap(n1, n2);
  std::cout << "n1 = " << n1 << '\n'
            << "n2 = " << n2 << std::endl;
  std::cout << "-- -------------------------- --" << '\n';

  int n = 4;
  sort(A, n);
  print_array(A, n);
  return 0;
}
