#include<iostream>

int main()
{    
    int i = 0 , &r1 = i;
    double d = 0,&r2 = d;
    r1 = d;
    std::cout<<r1<<std::endl;
    return 0;
}
