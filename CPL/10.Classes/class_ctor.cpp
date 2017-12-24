// Copyright <2017> [Tim Hu]

#include <iostream>


class Date {
  int d, m, y;
 public:
  // Date today;
  // Date(int , int, int);      // constructor
  // ...
  explicit Date(int dd = 0 , int mm = 0, int yy = 0);      // day, month, year
  // Date(int, int);            // day, month, today's year
  // Date(int);                 // day, today's month and year
  // Date();                    // default Date:today?
  Date(const char*);         // date in string representation

  void add_day(int n);                   // add n days
  void add_mouth(int n);                 // add n mouths
  void add_year(int n);                  // add n years
  void print_date();              // print date
};

Date today(24, 12, 2017);   // 实例today作为全局函数

inline void Date::add_day(int n) {
  y += n;
}


Date::Date(int dd, int mm, int yy) {
  // 定义一个缺省值后, 先判断缺省值是否存在，再选择给或不给，再赋值
  d = dd ? dd : today.d;        // dd == 0, dd 取24
  m = mm ? mm : today.m;
  y = yy ? yy : today.y;
}


/*不需要重新定义每个重载函数
Date::Date(int dd, int mm) {
  // day, month, today's year 
  d = dd ? dd : 24;
  m = mm ? mm : today.m;
  std::cout << "today.m " << today.m << std::endl;
  y = today.y;                 // default today's year
}
*/



inline void Date::print_date() {
  // 解引用实例本身 this->d
  std::cout << "today.d = " << this->d << '\n'
            << "today.m = " << this->m << '\n'
            << "today.y = " << this->y << std::endl;
}

int main() {
  Date now = Date(25, 12, 2017);
  Date test_now = Date();
  // now.print_date();
  // test_now.print_date();
  Date today_main(4, 12);
  // today_main.print_date();
  Date now_1;
  // now_1.print_date();

  // Date july4("July 4, 1983");
  // Date guy("5 Nov");
  return 0;
}
