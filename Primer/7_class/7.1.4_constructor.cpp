#include <iostream>

//add constructor

struct Sales_data{
    //add constructor
    //Sales_data() = default;    //default constructor
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
               bookNo(s), units_sold(n), revenue(p*n)  { }
    Sales_data(std::istream &);

    //exist defs
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold;
    double revenue;

};

int main()
{
    Sales_data total;
    return 0;
}

