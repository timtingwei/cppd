#include <iostream>

class Sales_data {
  //frient declare for not member funtions of Sales_data
  friend Sales_data add(const Sales_data&, const Sales_data&);
  friend std::istream &read(std::istream&, Sales_data&);
  friend std::iostream &print (std::ostream&, const Sales_data&);
  

public:               //access specifer added
  Sales_data() = dafault;
  Sales_data(const std::string &s, unsigned n, double p):
    bookNo(s), units_sold(n), revenue(p*n) {}
  Sales_data(const std::string &s):bookNo(s) {}
  Sales_data(std::istream&);
  std::string isbn() const { return bookNo;}
  Sales_data &combine(const Sales_data&);
private:             //access specifer added
  //double avg_price()const
  //{return units_sold ? revenue/units_sold :0;}
  std::string bookNo;
  unsigned units_sold = 0;
  double revenue = 0.0;
};

//
Sales_data add(const Sales_data&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);


