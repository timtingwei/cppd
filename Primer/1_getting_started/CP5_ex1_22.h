// Copyright [2018] <HankDaly>
// ex1_22.h
#ifndef CP5_ex1_22_h
#define CP5_ex1_22_h
#include "Sales_item.h"
#include <iostream>
#include <vector>

using std::vector;
/*
int foo_22()
{
    Sales_item item1,item2;
    if(std::cin>>item1)
    {
        while(std::cin>>item2)
            {
                item1 += item2;
            }
        std::cout<<item1<<std::endl;
    }
    
    else
    {
        std::cout<<"no date"<<std::endl;
    }
    return 0;
}
*/
int foo_22() {
  Sales_item item1;
  vector<Sales_item> sitm_vec = {};
  std::cin >> item1;
  sitm_vec.push_back(item1);        // add the first book
  while (std::cin >> item1) {
    // std::cout << "item1.isbn() = " << item1.isbn() << std::endl;
    int is_find = 0;
    for (auto it = sitm_vec.begin(); it != sitm_vec.end(); it++) {
      if (item1.isbn() == it->isbn()) {
        *it += item1;
        is_find = 1;
        break;
      }
    }
    if (!is_find) {sitm_vec.push_back(item1);}
  }

  for (auto it = sitm_vec.begin(); it != sitm_vec.end(); it++) {
    std::cout << *it << std::endl;
  }

  return 0;
}

#endif

