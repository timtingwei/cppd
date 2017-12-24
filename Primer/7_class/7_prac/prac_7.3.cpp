#include <iostream>

struct Sales_data{
    //
    std::string isbn() const{ return bookNo; }
    Sa0les_data& combine(const Sales_data&);
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

/*std::ostream & Sales_data::print (std::ostream &, const Sales_data&){
    //
    std::cout << total << std::endl;
    return *cout;
}
std::istream & Sales_data::read (std::istream &, const Sales_data&){
    std::cin >> total;
    return *cin;
}*/

std::ostream & Sales_data::transp(std::ostream &cout, std::istream 
&cin){
    Sales_data total;
    if (read(cin, total)){
        Sales_data trans;
        while (read(cin, trans)){
            if (total.isbn() == trans.isbn())
                total.combine(trans);
    	    else{
                print (cout, total) << std::endl;
                total = trans;
            }
        }
        print (cout, total) << std::endl;
    }else{
        std::cerr << "No data??" << std::endl;
    }
}



int main()
{
    Sales_data total;
    Sales_data rhs;
    total.units_sold = 1.2; total.revenue = 22;
    rhs.units_sold = 2.3; rhs.revenue = 11;
    total.combine(rhs);
    std::cout << "total.units_sold = " << total.units_sold << 
"total.revenue = " << total.revenue << std::endl;
    return 0;
}
