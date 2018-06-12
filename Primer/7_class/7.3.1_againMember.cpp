 /*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:7.3.1_againMember.cpp
   Date:Tue Jun 12 14:48:16 CST 2018
   -----------------------------
*/
#include <iostream>
#include <vector>

class Screen {
 public:
  
  // 定义某种类型在类中的别名
  typedef std::string::size_type pos;
  // using pos = std::string::size_type;
  // 默认构造函数
  Screen() = default;
  // 类内初始值构造Screen类
  Screen(pos ht, pos wd, char c) : height(ht), width(wd),
                                   contents(ht * wd, c) {
    // std::cout << "ht * wd = " << ht * wd << std::endl;
  }
  // 读取光标处的字符
  char get() const {
    // 隐式内联
    return contents[cursor];}
  // 显式内联
  inline char get(pos ht, pos wd) const;
  // 能在之后被设为内联函数
  Screen &move(pos r, pos c);
  // 常量成员函数
  void some_memFunc() const;

 private:
  pos cursor = 0;
  pos height = 0, width = 0;
  std::string contents;
  // 可变数据成员
  mutable size_t access_ctr;
  // size_t access_ctr;
};

inline
char Screen::get(pos r, pos c) const {
  pos row = r * width;
  return contents[row + c];
}

inline
Screen& Screen::move(pos r, pos c) {
  pos row = r * width;
  cursor = row + c;
  return *this;
}

inline
void Screen::some_memFunc() const {
  access_ctr++;
}

class Window_mgr {
 private:
  std::vector<Screen> screens{Screen(24, 80, ' ')};
};

int main() {
  Screen s1;
  std::string::size_type ht = 3, wd = 4;
  char c = 't';
  Screen s2(ht, wd, c);
  std::cout << "s2.get() = " << s2.get() << std::endl;
  std::cout << "s2.get(ht, wd) = " << s2.get(ht, wd) << std::endl;
  std::string::size_type move_r = 2, move_c = 3;
  s2.move(move_r, move_c);
  std::cout << "s2.get() = " << s2.get() << std::endl;

  s2.some_memFunc();

  Window_mgr win_mgr;
  return 0;
}
