// Copyright [2018] <HankDaly>
// ex1_23.h

#ifndef CP5_ex1_23_h
#define CP5_ex1_23_h

#include"Sales_item.h"
#include <vector>
#include <string>

using std::vector; using std::string;

/*
int foo_23()
{
    Sales_item item1,item2;
    if(std::cin>>item1)
    {
        int cnt = 1;
        while(std::cin>>item2)
        {
            if(item1.isbn()==item2.isbn())
            {
                cnt += 1;
            }
            else
            {
                std::cout<< item1 <<" occurs "<< cnt << " times " << std::endl;
                item1 = item2;
                cnt = 1;
            }
            
        }
        std::cout<< item1 << " occurs " << cnt << " times " <<std::endl;
    }
    return 0;
}
*/

/* 对你原来代码的测试
bash-3.2$ ./a.out
0-201-78665-x 4 20.00
0-201-786345-x 4 20.00
0-201-78665-x 3 20.00
0-201-3322-y 9 20.00
0-201-78665-x 4 20.00
0-201-786345-x 4 20.00
0-201-3322-y 9 20.00
0-201-999-x 2 20.00

0-201-78665-x 4 80 20 occurs 1 times 
0-201-786345-x 4 80 20 occurs 1 times 
0-201-78665-x 3 60 20 occurs 1 times 
0-201-3322-y 9 180 20 occurs 1 times 
0-201-78665-x 4 80 20 occurs 1 times 
0-201-786345-x 4 80 20 occurs 1 times 
0-201-3322-y 9 180 20 occurs 1 times 
*/

int foo_23() {
  Sales_item item1;
  std::vector<std::string> isbn_vec = {};
  vector<int> cnt_vec = {};
  if (std::cin >> item1) {
    isbn_vec.push_back(item1.isbn());
    cnt_vec.push_back(1);
  }
  while (std::cin >> item1) {
    int is_find = 0;
    for (int i = 0; i < isbn_vec.size(); i++) {
      if (item1.isbn() == isbn_vec[i]) {
        cnt_vec[i]++;
        is_find = 1;
        break;
      }
    }
    if (!is_find) {
      isbn_vec.push_back(item1.isbn());
      cnt_vec.push_back(1);
    }
  }

  for (int i = 0; i < isbn_vec.size(); i++) {
    std::cout << isbn_vec[i] << " occurs " << cnt_vec[i] << " times\n";
  }

  return 0;
}
/*
  ./a.out
0-201-78665-x 4 20.00
0-201-786345-x 4 20.00
0-201-78665-x 3 20.00
0-201-3322-y 9 20.00
0-201-78665-x 4 20.00
0-201-786345-x 4 20.00
0-201-3322-y 9 20.00
0-201-999-x 2 20.00

0-201-78665-x occurs 3 times
0-201-786345-x occurs 2 times
0-201-3322-y occurs 2 times
0-201-999-x occurs 1 times
*/

#endif
