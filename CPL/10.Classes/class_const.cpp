/*
Copyright <2017> [Tim Hu]

物理和逻辑的常量性, 为了改变private, 可以强制去掉const, 用在constmem中使用this对private成员修改。
*/ 
#include <iostream>
#include <string>

class Date {
  bool cache_valid;
  std::string cache;
  void compute_cache_value() {}      // 填充缓存
 public:
  Date(bool bc = false, std::string c = "tim") :
      cache_valid(bc), cache(c) {}
  std::string string_rep() const;
};

std::string Date::string_rep() const {
  if (cache_valid == false) {
    Date* th = const_cast<Date*> (this);   // 强制去掉cast
    // compute_cache_value();
    // cache_valid = true;     // error: 对于this -> cache_valid 来说是只读的
    // (*th).compute_cache_value();  // 以后用 ->更为简洁
    // (*th).cache_valid = true;
    th -> compute_cache_value();
    th -> cache_valid = true;
  }
  return cache;
}

int main() {
  // ...
  Date d;
  // d = Date();  error: Date()没有构造函数.
  d.string_rep();

  Date d1;
  const Date d2;
  std::string s1 = d1.string_rep();
  std::string s2 = d2.string_rep();    // 无定义行为
  return 0;
}
