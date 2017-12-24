#include <iostream>

struct First{
  int memi;
  int getMem();
};

struct Second{

  int memi;
  int getMem();
};

First obj1;
//Second obj2 = obj1;        //error: obj1 and obj2 have different types
