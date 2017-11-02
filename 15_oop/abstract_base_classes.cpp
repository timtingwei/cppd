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

/*class Bulk_quote : public Quote {  // Bulk_quote inherits from Quote
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
*/

class Disc_quote : public Quote {   // refactoring
 public:
  Disc_quote() = default;
  Disc_quote(const std::string& book, double price,
             std::size_t qty, double disc):
      Quote(book, price), quantity(qty), discount(disc) {}
  double net_price(std::size_t) const = 0;
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
  if (cnt >= min_qty)
    return cnt * (1-discount) * price;
  else
    return cnt * price;
}




int main() {
  // Disc_quote discounted;  // error:cannnot define a Disc_quote object
  Bulk_quote bulk;           // ok: Bulk_quote has no pure virtual func
  return 0;
}
