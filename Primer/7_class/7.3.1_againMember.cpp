 /*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:7.3.1_againMember.cpp
   Date:Tue Jun 12 14:48:16 CST 2018
   -----------------------------
*/
#include <iostream>

class Screen {
 public:
  // Screen() = default;
  // 定义某种类型在类中的别名
  typedef std::string::size_type pos;
  // using pos = std::string::size_type;
 private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
};

int main() {
  // Screen s1;
  return 0;
}
