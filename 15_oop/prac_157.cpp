#include <iostream>

class Quote {
public:
  Quote() = default;
  Quote(const std::string &book, double sales_price):
    bookNo(book), price(sales_price) { }

  std::string isbn() const {return bookNo; }
  virtual double net_price(std::size_t n)const
  {return n*price;}

  virtual ~Quote() = default;    //dynamic binging for the destructor
private:
  std::string bookNo;            //ISBN number of this item
protected:
  double price = 1.8;            //normal undiscounted price

};

class Limit_Quote : public Quote{
public:
  Limit_Quote() = default;
  Limit_Quote( const std::string &book, double p,std::size_t lmc, double disc):
    Quote(book, p), min_lmc(lmc), discount(disc){ }

  double net_price(std::size_t) const override;  //declare in class,def out

  virtual ~Limit_Quote() = default;
private:
  std::size_t min_lmc = 18;       //minimun count for the purchase
  double discount = 0.99;      //fractional discount to apply
};

double Limit_Quote::net_price(size_t cnt) const
{
  if (cnt >= min_lmc){
    return (1-discount)*min_lmc*price + (cnt-min_lmc)*price;
  }
  else{
    return cnt*(1-discount)*price;
  }
}

double print_total(std::ostream &os,
		   const Quote &item, size_t n)
{
  //depending on the type of the object bound to the item parameter
  //call either Quote::net_price or Bulk_quote::net_price
  double ret = item.net_price(n);
  os << "ISBN:" << item.isbn() << //calls Quote::isbn
    " # sold: " << n << "total due: " << ret << std::endl;
  return ret;
}

int main()
{
  Quote basic;
  Limit_Quote limit;
  print_total(std::cout,basic,20);
  print_total(std::cout,limit,20);

  return 0;
}
