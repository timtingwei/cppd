/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@gmail.com    
   ------------------------------
   File:CP5_ex9_8.h
   Date:Thu Jun 21 10:18:38 CST 2018
   -----------------------------
*/

#ifndef CP5_ex9_8_h
#define CP5_ex9_8_h

#include <iostream>
#include <list>
#include <string>

void foo_8() {
  std::list<std::string > v{"tim", "cooper"};
  std::list<std::string >::const_iterator cbegin = v.begin();
  std::cout << "*cbegin = " << *cbegin << std::endl;
  std::list<std::string >::iterator begin = v.begin();
  *(++begin) = "b+g";
  std::cout << "*begin = " << *begin << std::endl;
}



#endif



