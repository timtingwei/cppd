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

struct Sales_data {
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
}

#endif
