#ifndef SALES_DATA_H
#define SALES_DATA_H
#include <string>

/*struct Sales_data{
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};*/

/*//Sales_data after imporved
struct Sales_data {
    //new member: operation about Sales_data object
    std::string isbn() const {return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    //data-member not changed with 2.6.1 section
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;


};

//Sales_data not member functions
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);*/

//prac_7.7 Sales_data.h
/*struct Sales_data {
    std::string bookNo;
    unsigned units_sold;
    double sellingprice;
    double sellprice;
    double discount;
    std::string isbn() const{return bookNo;}         //memberFunc
    Sales_data& combine(Sales_data &rhs) {

        units_sold = rhs.units_sold;
        sellingprice = (sellingprice + rhs.sellingprice) / (units_sold 
+ rhs.units_sold);
        sellprice = (rhs.sellprice * rhs.units_sold + 
sellprice*units_sold) / (rhs.units_sold + units_sold);
        if (sellingprice != 0)
            discount = sellprice / sellingprice;

        return *this;
    }
};

std::istream &read(std::istream &is, Sales_data &item)
{
    //double price = 0.0;
    is >> item.bookNo >> item.units_sold >> item.sellingprice >> 
item.sellprice;
    return is;
}

std::ostream &print(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.sellingprice
       << " " << item.sellprice;  
    return os;
}*/

//add constructor

struct Sales_data{
    //add constructor
    Sales_data() = default;    //default constructor
    Sales_data(const std::string &s): bookNo(s) { }
    Sales_data(const std::string &s, unsigned n, double p):
               bookNo(s), units_sold(n), revenue(p*n)  { }
    Sales_data(std::istream &);

    //exist defs
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};



#endif
