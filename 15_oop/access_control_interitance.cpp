// "Copyright [2017] Tim Hu "
#include <iostream>

/*  ----protected Members----
class Base {
  // friend void clobber(Base&);
 protected:
  int prot_mem;       // member of protected
};

class Sneaky : public Base {
  friend void clobber(Sneaky&);    // can access Sneaky:prot_member
  // friend void clobber(Base&);      // can't access Base::pro_mem;
 protected:
  int j;                           // j is private by default
};

class Derived : public Sneaky {
  friend void clobber(Derived&);
  int i;
};

// ok: clobber can access the private and protected members in Sneaky objects
void clobber( Sneaky& s) { s.j = s.prot_mem = 0;}
// error: clobber can't access the protected members in Base
// void clobber(const Base& s) {s.prot_mem = 0;}
// void clobber( Derived& d) {d.i = d.prot_mem = 0;}
void clobber( Derived& d) {d.i = d.j = d.prot_mem = 0;}
// void clobber( Derived& d1) { d1.prot_mem = 0;}
int main() {
  return 0;
}
*/

// ----public, private, and protected Inheritance
/*
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
  // int f() { return prot_mem; }
  // error : private members are inaccessible to derived classes
  // char g() { return priv_mem;}
};

struct Priv_Derv : private Base {
  // private derivation doesn't affect access in the derived class
  // int f1() const {return prot_mem;}
  // char f2() {return priv_mem;}
};

struct Prot_Derv : protected Base {
  // a
};

struct Derived_from_Public : public Pub_Derv {
  int use_base() {return prot_mem; }
};

struct Derived_from_Private : public Priv_Derv {
  // error: Base::prot_mem is private in Priv_Derv
  // int use_base() {return prot_mem; }
};

int main() {
  Pub_Derv d1;   // members inherited from Base are public
  Priv_Derv d2;  // members inherited from Base are private
  d1.pub_mem();
  // d2.pub_mem();  // error: pub_mem is private in derived class
  return 0;
}
*/


/* friendship and inheritance
class Base {
 public:
  void pub_mem();
  friend class Pal;
 protected:
  int prot_mem;       // member of protected
};

class Sneaky : public Base {
  friend void clobber(Sneaky&);    // can access Sneaky:prot_member
 protected:
  int j;                           // j is private by default
};

class Pal {
 public:
  int f(Base b) {return b.prot_mem;}  // ok: Pal is a friend of Base
  // int f2(Sneaky s) {return s.j;}      // error: Pal is not friend of Sneaky
  int f3(Sneaky s) {return s.prot_mem;}  // ok: Pal is a friend of Base
};

class D2 : public Pal {
 public:
  // int mem(Base b) {return b.prot_mem;}  // error: friendship doesn't inherit
};
*/

// ----exempting individual members----

class Base {
 public:
  std::size_t size() const {return n;}
 protected:
  std::size_t n;
};

class Derived : private Base {     // note: private inheritance
 public:
  // mantain access levels for memebers related to the size of the object
  using Base::size;
 protected:
  // using Base::n;
  int j = n;
};



int main() {
  return 0;
}


