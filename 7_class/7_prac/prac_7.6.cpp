#include <iostream>

struct Sales_data{
    //
    std::string isbn() const{ return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    std::string bookNo;
    unsigned units_sold;
    double revenue;
};

//not member function
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

double Sales_data::avg_price() const{
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

Sales_data& Sales_data::combine(const Sales_data &rhs){
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

Sales_data add(const Sales_data &tmp1, const Sales_data &tmp2){
    Sales_data sum = tmp1;
    sum.combine(tmp2);
    return  sum;
}

std::ostream &print (std::ostream &os, const Sales_data &item){
    os << item.isbn() << "  "<< item.units_sold << " " << item.revenue 
<< " " << item.avg_price();
    return os;
}

std::istream &read (std::istream &is, Sales_data &item){
    double price =  0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}


int main()
{
    Sales_data total;
    read (std::cin, total);
    print (std::cout, total);
    return 0;
}
