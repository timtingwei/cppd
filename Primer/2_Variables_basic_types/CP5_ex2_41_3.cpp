// Copyright [2018] <HankDaly>
// ex2_41_3.h
#include<iostream>
#include<string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double price = 0;
    double revenue = 0.0;
};
int main()
{ 
    Sales_data data1,data2;
    if(std::cin >> data1.bookNo >> data1.units_sold >> data1.price){
        unsigned totalCnt = data1.units_sold;
        double totalRevenue = data1.units_sold*data1.price;
        while(std::cin >> data2.bookNo >> data2.units_sold >> data2.price){
            if(data1.bookNo == data2.bookNo){
                totalCnt += data2.units_sold;
                totalRevenue += data2.units_sold*data2.price;
            }
            else{
                std::cout<< "not same" << data1.bookNo << " " << totalCnt << " " << totalRevenue << " " << totalRevenue/totalCnt << std::endl;
                return 0;
            }
        }
        std::cout<< data1.bookNo << " " << totalCnt << " " << totalRevenue << " " << totalRevenue/totalCnt << std::endl;
    }
    else{
        std::cout<<"no data"<<std::endl;
    }
    return 0;
}
