// Copyright [2018] <HankDaly>
// ex1_23.h
#include"Sales_item.h"

int foo_23()
{
    Sales_item item1,item2;
    if(std::cin>>item1)
    {
        int cnt = 1;
        while(std::cin>>item2)
        {
            if(item1.isbn()==item2.isbn())
            {
                cnt += 1;
            }
            else
            {
                std::cout<< item1 <<" occurs "<< cnt << " times " << std::endl;
                item1 = item2;
                cnt = 1;
            }
            
        }
        std::cout<< item1 << " occurs " << cnt << " times " <<std::endl;
    }
    return 0;
}