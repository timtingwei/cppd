// Copyright [2018] <HankDaly>
// ex1_22.h
#include"Sales_item.h"

int foo_22()
{
    Sales_item item1,item2;
    if(std::cin>>item1)
    {
        while(std::cin>>item2)
            {
                item1 += item2;
            }
        std::cout<<item1<<std::endl;
    }
    
    else
    {
        std::cout<<"no date"<<std::endl;
    }
    return 0;
}