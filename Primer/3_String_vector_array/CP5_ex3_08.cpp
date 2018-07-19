// Copyright [2018] <HankDaly>
// CP5_ex3_06

#include<iostream>
#include<string>

int main()
{
    std::string s1;
    std::cin>>s1;
    decltype(s1.size()) x = 0;
    while(x != s1.size()){
        s1[x] = 'X';
        ++x;
    }
    std::cout<<s1<<std::endl;
    return 0;
}