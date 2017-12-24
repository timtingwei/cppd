// "Copyright [2017] <Tim Hu>"
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
  double price = 1.8;            // normal undiscounted price
};


class Disc_quote : Quote {
 public:
  Disc_quote() = default;
  Disc_quote(const std::string& book, double sales_price,
             std::size_t lmc, double disc) :
      Quote(book, sales_price), min_lmc(lmc), discount(disc) {}
  double net_price(std::size_t) const = 0;
 protected:
  std::size_t min_lmc = 0;       // minimun count for the purchase
  double discount = 0.0;         // fractional discount to apply
};


int main() {
  Quote basic{"201-a-a", 5};
  Disc_quote discQ{"201-a-a", 5, 20, .19};
  return 0;
}

/*
  [tim@htwt 15_oop]$ g++ -std=c++11 prac_1517.cpp
prac_1517.cpp: In function ‘int main()’:
prac_1517.cpp:37:14: error: cannot declare variable ‘discQ’ to be of abstract type ‘Disc_quote’
   Disc_quote discQ{"201-a-a", 5, 20, .19};
              ^
prac_1517.cpp:22:7: note:   because the following virtual functions are pure within ‘Disc_quote’:
 class Disc_quote : Quote {
       ^
prac_1517.cpp:28:10: note: 	virtual double Disc_quote::net_price(std::size_t) const
   double net_price(std::size_t) const = 0;
          ^
 */
