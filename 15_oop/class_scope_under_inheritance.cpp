// "Copyright [2017]<Tim Hu>"
// define a pure virtual function
#include <iostream>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book, double sales_price):
    bookNo(book), price(sales_price) { }
  std::string isbn() const {return bookNo; }

  virtual double net_price(std::size_t n)const;
  // {return n*price;}

  virtual ~Quote() = default;    // dynamic binging for the destructor
 private:
  std::string bookNo;            // ISBN number of this item
 protected:
  double price = 0.0;            // normal undiscounted price
};

class Disc_quote : public Quote {   // refactoring
 public:
  Disc_quote() = default;
  Disc_quote(const std::string& book, double price,
             std::size_t qty, double disc):
      Quote(book, price), quantity(qty), discount(disc) {}
  double net_price(std::size_t) const = 0;
  std::pair<size_t, double> discount_policy() const
       {return {quantity, discount};}
 protected:
  std::size_t quantity = 0;    // purchase size for the discount to apply
  double discount = 0.0;       // fractional discount to apply
};

class Bulk_quote : public Disc_quote {  // Bulk_quote inherits from Quote
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string& book, double p,
             std::size_t qty, double disc):
    Disc_quote(book, p, qty, disc) { }
  double net_price(std::size_t) const override;

  virtual ~Bulk_quote() = default;
  //  private:
  // std::size_t min_qty = 0;  // minimun purchase for the discount to apply
  // double discount = 0.0;    // fractional discount to apply
};

double print_total(std::ostream &os,
                   const Quote &item, size_t n) {
  // depending on the type of the object bound to the item parameter
  // call either Quote::net_price or Bulk_quote::net_price
  double ret = item.net_price(n);
  os << "ISBN:" << item.isbn() <<   // calls Quote::isbn
    " # sold: " << n << "total due: " << ret << std::endl;
  return ret;
}

double Quote::net_price(size_t n) const {
  return n*price;
}

double Bulk_quote::net_price(size_t cnt) const {
  if (cnt >= quantity)
    return cnt * (1-discount) * price;
  else
    return cnt * price;
}


/* -----Name collisions and inheritance----
struct Base {
  Base():mem(11) {}
 protected:
  int mem;
};

struct Derived : Base {
  explicit Derived(int i) : mem(i) {}   // initializes Derived::mem to i
  // Base::mem is default initialized
  int get_mem() {return mem;}           // return Derived::mem;
  int get_base_mem() {return Base::mem;}
 protected:
  int mem;     // hides mem in the base
};

int main() {
  Bulk_quote bulk;
  Bulk_quote *bulkP = &bulk;      // static and dynamic types are the same
  Quote *itemP = &bulk;           // static and dynamic types differ
  bulkP->discount_policy();       // ok:bulkP has type Bulk_quote*
  // itemP->discount_policy();       // error: itemP has type Quote*

  Derived d(42);
  std::cout << d.get_mem() << std::endl;
  std::cout << d.get_base_mem() << std::endl;
  // std::cout << d.Base::mem << std::endl;
  return 0;
}
*/

/* ----As usual, name lookup happenes before type checking----
struct Base {
  int memfcn();
};

struct Derived : Base {
  int memfcn(int);        // hides memfcn in the base
};
int main() {
  Derived d; Base b;
  b.memfcn();             // calls Base::memfcn
  d.memfcn(10);           // calls Derived::memfcn
  // d.memfcn();          // error: memfcn with no arguments is hidden
  d.Base::memfcn();       // ok:calls Base::memfcn
  return 0;
}
*/

class Base {
 public:
  virtual int fcn();
};

class D1 : public Base {
 public:
  int fcn(int);       // parameter list differs from fcn in Base
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
  bp2->fcn();        // virtual, Base::fcn
  bp3->fcn();        // virtual, D2:fcn

  D1 *d1p = &d1obj, D2 *d2p = &d2obj;
  // bp2->f2();      // error: Base has no member named f2
  d1p->f2();         // D1::f2()
  d2p->f2();         // D2::f2()

  Base *p1 = &d2obj; D1 *p2 = &d2obj; D2 *p3 = &d2obj;
  p1->fcn(42);     // error: Base has no version of fcn that takes an int
  p2->fcn(42);     // statically bound, call D1::fcn(int)
  p3->fcn(42);     // statically bound, call D2::fcn(int)
  return 0;
}

