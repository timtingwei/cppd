#include <iostream>

struct Person
{
    std::string name;
    std::string address;
    
    std::string getName() const {return name;}
    std::string getAddress() const {return address;}
    
};

int main()
{
    Person man;
    man.name = "Tim"; man.address = "Zhejiang";
    std::cout << man.getName() << std::endl << man.getAddress() << 
std::endl;
    return 0;
}
