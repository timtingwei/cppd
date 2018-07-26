// Copyright [2018] <HankDaly>
// CP5_ex3_05

#include<iostream>
#include<string>

int main()
{
    std::string s1,s2,s3;
    while(std::cin>>s1){
        s2 += s1;
        s3 += s1;
        s3 += " ";
    }
    //no space
    std::cout<<s2<<"\n"<<std::endl;
    //space
    std::cout<<s3<<std::endl;
        
}