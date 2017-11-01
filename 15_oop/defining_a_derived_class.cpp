"Copyright [2017]<Tim>"
// 15.1 object-oriented programming overview
#include <iostream>

class Quote {
 public:
  Quote() = default;
  Quote(const std::string &book, double sales_price):
    bookNo(book), price(sales_price) { }
  std::string isbn() const {return bookNo; }

  virtual double net_price(std::size_t n)const
  {return n*price;}

  virtual ~Quote() = default;    // dynamic binging for the destructor
 private:
  std::string bookNo;            // ISBN number of this item
 protected:
  double price = 0.0;            // normal undiscounted price
};

class Bulk_quote : public Quote {  // Bulk_quote inherits from Quote
 public:
  Bulk_quote() = default;
  Bulk_quote(const std::string& book, double p, std::size_t qty, double disc):
    Quote(book, p), min_qty(qty), discount(disc) { }
  double net_price(std::size_t) const override;

  virtual ~Bulk_quote() = default;
 private:
  std::size_t min_qty = 0;        // minimun purchase for the discount to apply
  double discount = 0.0;          // fractional discount to apply
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

double Bulk_quote::net_price(size_t cnt) const {
  if (cnt >= min_qty)
    return cnt * (1-discount) * price;
  else
    return cnt * price;
}

/*
class Base{
public:
  static void statmem();
};

class Derived : public Base {
  void f(const Derived&);
};

void Derived::f(const Derived &derived_obj)
{
  Base::statmem();        //ok:Base defines statmem
  Derived::statmem();     //ok:Derived inherits statmem
  //ok: derived objects can be used to access static from base
  derived_obj.statmem();  //accessed through a Derived object
  statmem();              //accessed through this object
  //::stamem();
}
*/

// Classes used to a Base Class
class Base {/*...*/};
class D1: public Base {/*...*/};
class D2: public D1 {/*...*/};

// Preventing Inheritance
class NoDerived final {/*...*/};      // NoDerived can't be a base class
class Base {/*...*/};
class Last final : Base {/*...*/};    // Last cannot be a base class
// class Bad : NoDerived {/*...*/};      // error: NoDerived is final
// error: cannot derive from ‘final’ base ‘NoDerived’ in derived type ‘Bad’
// class Bad2 : Last {/*...*/};          // error:Last if final

int main() {
  Quote basic;
  Bulk_quote bulk;
  print_total(std::cout, basic, 20);  // call Quote version of net_price
  print_total(std::cout, bulk, 20);   // call Bulk_quote version of net_price

  // Quote item;
  // bulk_quote bulk;
  // Quote *p = &item;
  // p = &bulk;
  // Quote &r = bulk;

  return 0;
}
