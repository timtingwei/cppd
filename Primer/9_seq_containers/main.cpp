/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:main.cpp
   Date:Wed Jun 20 02:03:46 CST 2018
   -----------------------------
*/
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include "CP5_ex9_38.h"

using std::list; using std::vector;
using std::string;

int main() {
  vector<string> svec;                           // 创建一个未定义的svec容器
  svec.reserve(1024);                            // 分配将要用到的内存空间1024
  int i = 0;
  while (i != 1028) {                          // 标准输入word
    svec.push_back("t");                        // 每次将word添入svec尾部
    i++;
  }
  svec.resize(svec.size() + svec.size() / 2);    // 容器中size()扩大1/2倍, 元素值初始化为空字符串
  std::cout << "capacity = " << svec.capacity() << "\n"
            << "size = " << svec.size() << std::endl;

  // 512,   c = 1024, s = 768;
  // 1000,  c = 2048, s = 1500;
  // 1028,  c = 2048, s = 1542;
  return 0;
}
