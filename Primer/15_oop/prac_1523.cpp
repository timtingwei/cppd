// "Copyright [2017]<Tim Hu>"
// D1 intended to override its inherited fcn function, fix it.
#include <iostream>

class Base {
 public:
  virtual int fcn();
};

class D1 : public Base {
 public:
  int fcn() override;       // override its inherited fcn funtion
  virtual void f2();  // new virtual function that does not exist in Base
};

class D2 : public D1 {
 public:
  int fcn(int);      // nonvirtual function hides D1::fcn(int)
  int fcn();         // override virtual fcn from Base
  void f2();         // override virtual f2 from D1
};

int main() {
  Base bobj; D1 d1obj; D2 d2obj;

  Base *bp1 = &bobj, *bp2 = &d1obj, *bp3 = &d2obj;
  bp1->fcn();        // virtual, Base::fcn
  bp2->fcn();        // virtual, D1::fcn
  bp3->fcn();        // virtual, D2:fcn

  D1 *d1p = &d1obj, D2 *d2p = &d2obj;
  // bp2->f2();      // error: Base has no member named f2
  d1p->f2();         // D1::f2()
  d2p->f2();         // D2::f2()

  Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
  p1->fcn(42);     // error: Base has no version of fcn that takes an int
  p2->fcn(42);     // error: D1 has no version of fcn that takes an int
  p3->fcn(42);     // statically bound, call D2::fcn(int)
  return 0;
}

