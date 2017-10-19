#include <iostream>
//class all of its members to be public before first private
//if we want to have private members, we use class
class Sales_data {
public:               //access specifer added
  Sales_data() = dafault;
  Sales_data(const std::string &s, unsigned n, double p):
    bookNo(s), units_sold(n), revenue(p*n) {}
  Sales_data(const std::string &s):bookNo(s) {}
  Sales_data(std::istream&);
  std::string isbn() const{return bookNo;}
  Sales_data &combine(const Sales_data&);
private:             //access specifer added
  double avg_price()const
  {return units_sold ? revenue/units_sold :0;}
  std::string bookNo;
  unsigne units_sold = 0;
  double revenue = 0.0;
};

//after public:constructor and member functions
//after private:data members and functions of implementation
