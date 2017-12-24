/*
Copyright <2017> [Tim Hu]
为了实现d.add_day().add_month().add_year(), 修改返回类型为函数调用所针对的对象。
*/ 
#include <iostream>


class Date {
  int d, m, y;
  static Date default_date;
 public:
  static void set_default(int, int, int);

  explicit Date(int dd = 0 , int mm = 0, int yy = 0);      // day, month, year
  Date(const char*);         // date in string representation

  // 修改原函数, 使得每个函数返回自身
  Date& add_day(int n);                   // add n days
  Date& add_month(int n);                 // add n mouths
  Date& add_year(int n);                  // add n years
  void print_date();                     // print date
  // 检查年月日
  int day() const;                     // 检查日
  int month() const;                   // 检查月
  int year() const;                    // 检查年
};


// 静态成员，包括函数和数据成员都必须在某个地方另行定义
Date Date::default_date(3, 12, 1996);
void Date::set_default(int dd, int mm, int yy) {
  // 设置默认日期
  default_date = Date(dd, mm, yy);
}
Date today = Date();

inline Date& Date::add_day(int n) {
  d += n;
  // 函数返回 这次调用所针对的那个对象
  return *this;
  // this的类型是 Date*, 在const成员函数中是 const Date* 以防成员修改
}

inline Date& Date::add_month(int n) {
  m += n;
  return *this;     // 函数返回自身
}

inline Date& Date::add_year(int n) {
  if (d == 29 && m == 2) {
    d = 1;
    m = 3;
  }
  y += n;
  return *this;     // 函数返回自身
}




Date::Date(int dd, int mm, int yy) {
  // 定义一个缺省值后, 先判断缺省值是否存在，再选择给或不给，再赋值
  d = dd ? dd : default_date.d;        // dd == 0, dd 取24
  m = mm ? mm : default_date.m;
  y = yy ? yy : default_date.y;
}


inline void Date::print_date() {
  // 解引用实例本身 this->d 等价于 (*this).d 等价于 d
  std::cout << "today.d = " << (*this).d << '\n'
            << "today.m = " << (*this).m << '\n'
            << "today.y = " << (*this).y  << std::endl;
}


inline int Date::day() const {     // 在外面定义const成员函数, 也要给出const
  return d;
}

inline int Date::month() const {
  return m;
}

inline int Date::year() const {
  return y;
}


int main() {
  Date d = Date(2, 29, 2017);
  d.print_date();
  // 想要实现如下调用
  d.add_day(1).add_month(1).add_year(1);
  d.print_date();
  return 0;
}
