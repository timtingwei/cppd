// "Copyright [2017]<Tim>"
/*
given the classes the previous execise and the following objects, determine which function is called at run time:
*/
#include <iostream>

class base {
 public:
  base() = default;
  base(const std::string &name):basename(name) { }

  std::string name() {
    std::cout << "base::name() calling..." << std::endl;
    return basename;
  }
  virtual void print(std::ostream &os) {
    std::cout << "base::print() calling..." << std::endl;
    os << basename << std::endl;
  }

  virtual ~base() = default;
 private:
  std::string basename;
};


class derived : public base {
 public:
  derived() = default;
  derived(const std::string &name, int ival) : base(name), mem(ival) { }

  void print(std::ostream &os) override {
    std::cout << "derived::print() calling..." << std::endl;
    base::print(os);
    os << "--" << mem << std::endl;
  }

  virtual ~derived() = default;
 private:
  int mem;
};


int main() {
  /* base b{"tim in b"};
  derived d{"tim in d", 5};
  b.print(std::cout);
  d.print(std::cout);*/

  // determine which function is called at run time
  base bobj{"tim in bobj"};      base *bp1 = &bobj;   base &br1 = bobj;
  derived dobj{"tim in d", 5};   base *bp2 = &dobj;   base &br2 = dobj;
  std::cout << "0--bobj.print(std::cout)" << std::endl;
  bobj.print(std::cout);    // base::print()
  std::cout << "1--dobj.print(std::cout)" << std::endl;
  dobj.print(std::cout);    // derived::print(), base::print()
  std::cout << "2--bp1->name()" << std::endl;
  bp1->name();     // base::name()
  std::cout << "3--bp2->name()" << std::endl;
  bp2->name();     // base::name()
  std::cout << "4--br1.print(std::cout)" << std::endl;
  br1.print(std::cout);     // base::print()
  std::cout << "5--br2.print(std::cout)" << std::endl;
  br2.print(std::cout);     // deirevd::print(), base::print()

  return 0;
}

/* 
[tim@htwt 15_oop]$ ./a.out
0--bobj.print(std::cout)
base::print() calling...
tim in bobj
1--dobj.print(std::cout)
derived::print() calling...
base::print() calling...
tim in d
--5
2--bp1->name()
base::name() calling...
3--bp2->name()
base::name() calling...
4--br1.print(std::cout)
base::print() calling...
tim in bobj
5--br2.print(std::cout)
derived::print() calling...
base::print() calling...
tim in d
--5
[tim@htwt 15_oop]$ 
 */
