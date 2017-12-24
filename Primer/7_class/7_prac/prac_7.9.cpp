#include <iostream>

struct Person{
//private:
public:
    std::string name;
    std::string address;

    std::string getName() const {return name;}
    std::string getAddress() const {return address;}
};

//std::istream read(std::cin&, Person&){};
//std::ostream print(std::cout&, Person&){};            error0 
//std::istream &read(std::istream&, Person&){};         error1
//std::ostream &print(std::ostream&, Person&){};
std::istream &read(std::istream&, Person&);
std::ostream &print(std::ostream&, Person&);

std::istream &read(std::istream& is, Person& item){
    is >> item.name >> item.address;
    return is;
}

std::ostream &print(std::ostream& os, Person& item){
    os << item.getName() << " " << item.getAddress() << " " << 
std::endl;
    return os;
}

int main()
{
    Person man;
    //man.name = "Tim"; man.address = "Zhejiang";
    //std::cout << man.name << std::endl << man.address << std::endl;
    read(std::cin, man);
    print(std::cout, man);
    return 0;
}
