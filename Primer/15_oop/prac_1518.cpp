// "Copyright [2017] Tim Hu "
#include <iostream>
// ----public, private, and protected Inheritance
class Base {
 public:
  void pub_mem();    // public member
 protected:
  int prot_mem();    // protect member
 private:
  char priv_mem();   // private member
};

struct Pub_Derv : public Base {
  // ok: derived members are inaccessible to derived classes
  int f() { return prot_mem; }
  // error : private members are inaccessible to derived classes
  // char g() { return priv_mem;}
};

struct Priv_Derv : private Base {
  // private derivation doesn't affect access in the derived class
  int f1() const {return prot_mem;}
  // char f2() {return priv_mem;}
};

struct Prot_Derv : protected Base {/*...*/};

struct Derived_from_Public : public Pub_Derv {
  int use_base() {return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv {
  // error: Base::prot_mem is private in Priv_Derv
  // int use_base() {return prot_mem; }
};

struct Derived_from_Protected : protected Base {
  // ...
};

int main() {
  Pub_Derv d1; Priv_Derv d2; Prot_Derv d3;
  Derived_from_Public    dd1;
  Derived_from_Private   dd2;
  Derived_from_Protected dd3;
  Base *p = &d1;    // d1  Pub_Derv
  // p = &d2;          // d2  Priv_Derv              error
  // p = &d3;          // d3  Prot_Derv              error
  p = &dd1;         // dd1 Derived_from_public       ok
  // p = &dd2;         // dd2 Derived_from_Private   error
  // p = &dd3;         // dd3 Derived_from_Protected error
  return 0;
}



