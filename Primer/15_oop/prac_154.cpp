#include <iostream>

class Base {/*...*/};

//class Derived : public Derived { /*...*/ };
class Derived : private Base { /*...*/ };
//class Derived : public Base;

int main()
{
  return 0;
}
