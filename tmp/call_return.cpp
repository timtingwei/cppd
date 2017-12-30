// Copyright <2017> [Tim Hu]

#include <iostream>
#include <string>

// 封装C++成员函数的调用 

// 调用一段类成员函数之前和之后，都会被执行一段被定义的代码
template <typename T>
class wrap {
  T* _pointer;
  wrap(const wrap &);
  wrap& operator=(const wrap&);

  class call_proxy {
    T* _pointer;
    call_proxy(T *p) : _pointer(p) {}
   public:
    ~call_proxy() {
      _pointer->after();
    }
    T* operator->() const {
      return _pointer;
    }
    friend class wrap<T>;
  };

 public:
  wrap(T& x): _pointer(&x) {}
  call_proxy operator->() const {
    _pointer->before();
    return call_proxy(_pointer);
  }
};

void puts(const std::string cs) {
  std::cout << cs << std::endl;
}

// 测试程序
class object{
 public:
  void test() {
    puts("test");
  }
  void after() {
    puts("after");
  }
  void before() {
    puts("before");
  }
};

int main() {
  object obj;
  wrap<object> x(obj);
  x->test();
}
