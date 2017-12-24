//15.1 object-oriented programming overview
#include <iostream>

class Quote {
public:
  std::string isbn() const;
  virtual double net_price(std::size_t n)const;
};

class Bulk_quote : public Quote {
public:
  double net_price(std::size_t) const override;
};

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
  //Quote basic;
  //Bulk_quote bulk;
  //print_total(std::cout,basic,20);  //cakk Quote version of net_price
  //print_total(std::cout,bulk,20);   //call Bulk_quote version of net_price
  return 0;
}
