/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:class_dtor.cpp
   Date:Mon Jan  8 19:28:20 CST 2018
   -----------------------------
*/

#include iostream

class Name {
  const char* s;
};

class Table {
  Name* p;
  size_t sz;
 public:
  Table(size_t s = 15) { p = new Name[sz = s];}   // constructor
  ~Table() {delete[] p;}                          // deconstructor

  Name* lookup(const char*);
  bool insert(Name*);
};
