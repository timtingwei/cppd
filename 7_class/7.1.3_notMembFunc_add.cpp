#include <iostream>
//definate function of read() and print()

struct Sales_data{
    //
    std::string isbn() const{ return bookNo; }
    Sales_data& combine(const Sales_data&);
    double avg_price() const;
    std::ostream& transp(std::ostream&, std::istream&);
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
    //std::cout << "running combine..." << std::endl;
    return *this;
}

std::istream &read(std::istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = price * item.units_sold;
    return is;
}

std::ostream &print(std::ostream &os, Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue 
<< " " << item.avg_price();
    return  os;
}

Sales_data add(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;      //copy lhs data to sum
    sum.combine(rhs);
    return sum;    
}

int main()
{
    Sales_data total;
    Sales_data rhs;
    read(std::cin, total);
    read(std::cin, rhs);
    //print(std::cout, total);
    Sales_data sum = add(total, rhs);
    print (std::cout, sum);
    return 0;
}
