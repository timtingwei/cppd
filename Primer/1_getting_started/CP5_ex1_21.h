// Copyright [2018] <HankDaly>
// revise [Fri Jul  6 12:31:38 CST 2018] <mituh>
// ex1_21.h
#ifndef CP5_ex1_21_h
#define CP5_ex1_21_h

#include"Sales_item.h"

int foo_21() {
  Sales_item item1, item2;
  std::cin >> item1 >> item2;
  if (item1.isbn() == item2.isbn()) {
    std::cout << item1 + item2 << std::endl;
  } else {
    std::cout << "different isbn!! " << std::endl;
  }
  return 0;
}

#endif
