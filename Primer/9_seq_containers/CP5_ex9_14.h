/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_14.h
   Date:Thu Jun 21 14:53:35 CST 2018
   -----------------------------
*/


#ifndef CP5_ex9_14_h
#define CP5_ex9_14_h

#include <iostream>
#include <vector>
#include <list>
#include <string>


void foo_13() {
  // char c1 = 't', c2 = 'c', c3 = 'b';
  // char *pc1 = &c1, *pc2 = &c2, *pc3 = &c3;
  // std::list<char*> clist = {pc1, pc2, pc3};
  std::list<const char*> clist = {"tim", "cooper", "b+g"};
  // could not use char* for string
  std::vector<std::string> svec;
  svec.assign(clist.cbegin(), clist.cend());

  std::cout << svec.capacity() << " " << svec.size() << " "
            << svec[0] << " " << svec[svec.size() - 1] << std::endl;
}







#endif



