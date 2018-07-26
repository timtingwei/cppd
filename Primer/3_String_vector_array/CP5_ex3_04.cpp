// Copyright [2018] <HankDaly>
// CP5_ex3_04
#include<iostream>
#include<string>

using std::string;

int main()
{
    string s1,s2;
    std::cin >> s1 >> s2;
    //compare string big
    if (s1 != s2)
        if (s1 > s2)
            std::cout<<"big--"<<s1<<std::endl;
        else
            std::cout<<"big--"<<s2<<std::endl;
    //compare string long
    if (s1.size() != s2.size())
        if (s1.size() > s2.size())
            std::cout<<"long--"<<s1<<std::endl;
        else
            std::cout<<"long--"<<s2<<std::endl;
}