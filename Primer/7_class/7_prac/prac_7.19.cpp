#include <iostream>

class  Person{
public:
  //Person() = default;
  Person (std::string const &s, std::string const&a):
    name(s), address(a) { }
  std::string getName(){return name;}
  std::string getAddress(){return address;}
  //Person (std::string const &a):adress(a){}  
private:
  std::string name;
  std::string address;
  std::string addNameAndAddress() const
  {return name + address;}
};

int main()
{
  Person man("Tim","Zhejiang");
  //man.name = "Tim"; man.address = "Zhejiang";
  std::cout << man.getName() << std::endl << man.getAddress() << std::endl;
  return 0;
}
