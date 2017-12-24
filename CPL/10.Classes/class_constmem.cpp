// Copyright <2017> [Tim Hu]
// 消除对全局变量的依赖，静态变量和成员来默认缺省date
#include <iostream>


class Date {
  int d, m, y;
  static Date default_date;
 public:
  static void set_default(int, int, int);

  explicit Date(int dd = 0 , int mm = 0, int yy = 0);      // day, month, year
  Date(const char*);         // date in string representation

  void add_day(int n);                   // add n days
  void add_mouth(int n);                 // add n mouths
  void add_year(int n);                  // add n years
  void print_date();                     // print date
  // 检查年月日
  int day() const;                     // 检查日
  // int day() const {return d;}
  int month() const;                   // 检查月
  int year() const;                    // 检查年

};


/*
**default_date要定义在全局中???**
**编译时，Date::Date(int,int,int)需要default_date静态变量**
*/

// 静态成员，包括函数和数据成员都必须在某个地方另行定义
Date Date::default_date(3, 12, 1996);
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

/*
inline int Date::day() const {
  return d++;     // 错误: 不能在const成员函数中修改成员值
}
*/


inline int Date::day() const {     // 在外面定义const成员函数, 也要给出const
  return d;
}

inline int Date::month() const {
  return m;
}

inline int Date::year() const {
  return y;
}



void f(Date &d, const Date &cd) {
  // 非const和const对象都可以调用const成员函数,
  // 但是非const成员函数只能被非const对象调用
  int dd = d.day();       // 非const对象调用const成员函数
  d.add_day(5);           // 非const对象调用非const成员函数

  int cdy = cd.year();    // const对象调用const成员函数
  // cd.add_year(4);         // 错误: const对象调用非const成员函数
  // cd.print_date();        // 错误:const对象调用不改变成员的非const成员函数
  // const对象不同调用非const成员函数.
  // 也就是说, const成员函数只能被const对象调用
}


int main() {
  Date d = today;
  d.print_date();
  std::cout << "day : " << d.day() << '\n'
            << "month : " << d.month() << '\n'
            << "year : " << d.year() << std::endl;
  return 0;
}
