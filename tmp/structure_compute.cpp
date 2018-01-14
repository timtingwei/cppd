/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:structure_compute.cpp
   Date:Sun Jan 14 19:17:01 CST 2018
   -----------------------------
*/

#include <iostream>
#include <math.h>

#define PI 3.1415926

void f() {
  double a = sqrt(5);
  std::cout << a << std::endl;
  double t1 = 2*PI*sqrt(2700*1000 / (245*1000*1000*9.8));
  std::cout << "t1 = " << t1 << std::endl;
  double fek = 0.16 * 0.85 * (2700 + 2700 + 1800);
  std::cout << "fek = " << fek << std::endl;
  double theta = 0.08 * 0.4 + 0.01;
  std::cout << "theta = " << theta << std::endl;
  double f1 = (2700)/(2700 + 2700 + 1800) * 979.2 * (1-0.42);
  std::cout << "f1 = " << f1 << std::endl;
}

int main() {
  f();
  return 0;
}
