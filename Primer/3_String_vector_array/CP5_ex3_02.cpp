// Copyright [2018] <HankDaly>
// CP5_ex3_02

#include<iostream>
#include<string>

using std::cin;
using std::cout;
using std::endl;

int main()
{   
    //每次读入一整行
    string line;
    while (getline(cin,line))
        cout << line << endl;
    //每次读入一个词
    string word;
    while (cin >> word)
        cout << word << endl;
    return 0;
}