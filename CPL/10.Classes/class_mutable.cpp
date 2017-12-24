/*
Copyright <2017> [Tim Hu]

物理和逻辑的常量性, 为了改变private, 可以强制去掉const, 用在constmem中使用this对private成员修改。

仍然可以用mutable避免依赖于实现的行为。并简化string_rep()的定义

mutable适合部分可变，而如果缓存绝大多数需要变，将数据放入一个独立的对象
*/ 
#include <iostream>
#include <string>

/* mutable数据部分可变
class Date {
  mutable bool cache_valid;    // cache_valid不可能是const
  mutable std::string cache;
  void compute_cache_value() const {}      // 填充缓存
 public:
  Date(bool bc = false, std::string c = "tim") :
      cache_valid(bc), cache(c) {}
  std::string string_rep() const;
};

std::string Date::string_rep() const {
  // 简化定义
  if (!cache_valid) {
    compute_cache_value();
    cache_valid = true;
  }
  return cache;
}
*/

struct cache {    // struct成员公有
  explicit cache(bool cb = true, std::string cs = "tim")
      : valid(cb), rep(cs) {}
  bool valid;               // **成员数据在构造之前需要声明**
  std::string rep;
};

class Date {
  // 可推广到各种形式的延迟求值 (lazy evalution)
  cache *c;                              // 在构造函数中初始化
 public:
  explicit Date(cache *c_smp):c(c_smp) {}
  void compute_cache_value() const {}    // 填充引用缓存
  std::string string_rep() const;
};

std::string Date::string_rep() const {
  if (!(c->valid)) {
    compute_cache_value();
    c->valid = true;
  }
  return c->rep;
}



int main() {
  // ...

  /* mutable数据部分可变
  Date d;
  // d = Date();  error: Date()没有构造函数.
  d.string_rep();

  Date d3;
  const Date d4;
  std::string s3 = d3.string_rep();
  std::string s4 = d4.string_rep();    // 无定义行为
  */

  cache c5;
  cache c6;

  Date d5(&c5);
  const Date d6(&c6);
  std::string s5 = d5.string_rep();
  std::string s6 = d6.string_rep();
  
  return 0;
}
