// Copyright [2018] <HankDaly>
// ex2_42.h

#ifndef SALES_DATA
#define SALES_DATA
#include<iostream>
#include<string>

struct Sales_data {
    std::string bookNo;
    unsigned units_sold = 0;
    double price = 0;
    double revenue = 0.0;
};
#endif