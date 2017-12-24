// Copyright <2017> [Tim Hu]
// 消除对全局变量的依赖，静态变量和成员来默认缺省date
#include <iostream>


class Date {
  int d, m, y;
  static Date default_date;
  // static Date today = default_date;
 public:
  // static void set_default(int n, int n, int n);
  static void set_default(int, int, int);

  explicit Date(int dd = 0 , int mm = 0, int yy = 0);      // day, month, year
  Date(const char*);         // date in string representation

  void add_day(int n);                   // add n days
  void add_mouth(int n);                 // add n mouths
  void add_year(int n);                  // add n years
  void print_date();                     // print date

};

// Date today(24, 12, 2017);   // 实例today作为全局函数

/*
**default_date要定义在全局中???**
**编译时，Date::Date(int,int,int)需要default_date静态变量**
*/

// 静态成员，包括函数和数据成员都必须在某个地方另行定义
Date Date::default_date(3, 12, 1996);
// std::cout << "define default_date......" << std::endl;
void Date::set_default(int dd, int mm, int yy) {
  // 设置默认日期
  default_date = Date(dd, mm, yy);
}
Date today = Date();

inline void Date::add_day(int n) {
  y += n;
}


Date::Date(int dd, int mm, int yy) {
  // 定义一个缺省值后, 先判断缺省值是否存在，再选择给或不给，再赋值
  d = dd ? dd : default_date.d;        // dd == 0, dd 取24
  m = mm ? mm : default_date.m;
  y = yy ? yy : default_date.y;
}


inline void Date::print_date() {
  // 解引用实例本身 this->d
  std::cout << "today.d = " << this->d << '\n'
            << "today.m = " << this->m << '\n'
            << "today.y = " << this->y << std::endl;
}



int main() {
  Date d = today;
  d.print_date();
  return 0;
}
