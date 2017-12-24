#include <iostream>

struct Person{
    std::string name;
    std::string address;

};

int main()
{
    Person man;
    man.name = "Tim"; man.address = "Zhejiang";
    std::cout << man.name << std::endl << man.address << std::endl;
    return 0;
}
