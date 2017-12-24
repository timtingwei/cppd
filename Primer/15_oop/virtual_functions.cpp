// "Copyright [2017]<Tim>"
// 15.1 object-oriented programming overview
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

double Quote::net_price(size_t n) const {
  return n*price;
}

double Bulk_quote::net_price(size_t cnt) const {
  if (cnt >= min_qty)
    return cnt * (1-discount) * price;
  else
    return cnt * price;
}

// ***final and override***
struct B {
  virtual void f1(int) const;
  virtual void f2();
  void f3();
};

struct D1 : B {
  void f1(int) const override;
  // void f2(int) override; // error: marked override, but does not override
  // void f3() override;  // error: marked override, but does not override
  // void f4() override;  // error: B doesn't have a function named f4
};

struct D2 : B{
  // derived f2() and f3() from B, override f1(int)
  void f1(int) const final;
};

struct D3 : D2{
  void f2() override;
  void f1(int) const override;   // error: cannot override final funtions
};


int main() {
  Quote base("0-201-82470-1", 50);
  print_total(std::cout, base, 10);        // call Quote::net_price
  Bulk_quote derived("0-201-82470-1", 50, 5, .19);
  print_total(std::cout, derived, 10);     // call Bulk_quote::net_price
  return 0;
}
