// "Copyright [2017]<Tim>"
/*
Given the following classes, explain each print function
*/
#include <iostream>

class base {
 public:
  base() = default;
  base(const std::string &name):basename(name) { }

  std::string name() { return basename; }
  virtual void print(std::ostream &os) { os << basename; }

  virtual ~base() = default;
 private:
  std::string basename;
};


class derived : public base {
 public:
  derived() = default;
  derived(const std::string &name, int ival) : base(name), mem(ival) { }

  void print(std::ostream &os) override {
    base::print(os);
    os << "--" << mem;
  }

  virtual ~derived() = default;
 private:
  int mem;
};


int main() {
  base b{"tim in b"};
  derived d{"tim in d", 5};
  b.print(std::cout);
  d.print(std::cout);
  return 0;
}
