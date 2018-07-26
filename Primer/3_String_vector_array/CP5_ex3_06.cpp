// Copyright [2018] <HankDaly>
// CP5_ex3_06

#include<iostream>
#include<string>

int main()
{
    std::string s1;
    std::cin>>s1;
    for(auto &s : s)
        s = 'X';
    std::cout<<s1<<std::endl;
    return 0;
}