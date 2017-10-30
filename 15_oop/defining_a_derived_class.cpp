//15.1 object-oriented programming overview
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
  double price = 0.0;            //normal undiscounted price

};

class Bulk_quote : public Quote {  //Bulk_quote inherits from Quote
public:
  Bulk_quote() = default;
  Bulk_quote(const std::string&, double, std::size_t,double);
  
  double net_price(std::size_t) const override;
private:
  std::size_t min_qty = 0;        //minimun purchase for the discount to apply
  double discount = 0.0;          //fractional discount to apply
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
