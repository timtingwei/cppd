// Copyright [2018] <HankDaly>
// CP5_ex3_01_2

#include<iostream>
#include<string>
#include"Sales_data.h"

using std::cin;
using std::cout;
using std::cerr
int main()
{
    Sales_data data1,data2;
    double price = 0;
    cin >> data1.bookNo >> data1.units_sold >> price;
    data1.revenue = data1.units_sold * price;
    cin >> data2.bookNo >> data2.units_sold >> price;
    data2.revenue = data2.units_sold * price;

    if (datal1.bookNo == data2.bookNo){
        unsigned totalCnt = datal1.units_sold + data2.units_sold;
        double totalRevenue = datal.revenue + data2.revenue;
        cout << data1.bookNo << " " << totalCnt << " " << totalRevenue << " ";
        if (totalCnt != 0)
            cout << totalRevenue/totalCnt << endl;
        else
            cout << "(no sales)" << endl;
        return 0;
    }
    else{
        cerr << "Data must refer to the same ISBN" << endl;
        return -1;
    }
    return 0;
}