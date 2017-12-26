// Copyright <2017> [Tim Hu]

#include <iostream>

// ..
int INT_MAX = 5;
int INT_MIN = -4;

class Matherr {
  // ...
 public:
  std::cout << "Initialize as Matherr" << std::endl;
  virtual void debug_print() const {std::cerr << "Math error" << std::endl;}
};

class Int_overflow : public Matherr {
  const char* op;
  int a1;
  int a2;
 public:
  Int_overflow(const char* p, int a, int b) {
    op = p; a1 = a; a2 = b;
    std::cout << "Initialize as Matherr" << std::endl;
  }
  virtual void debug_print() const {std::cerr << op << '(' << a1 << ',' << a2 << ')' << std::endl;}
};

class Overflow : public Matherr { };
class Underflow : public Matherr { };
class Zerodivide : public Matherr { };

void g();

int add(int x, int y) {
  if ((x>0 && y>0 && x>INT_MAX-y) || (x<0 && y<0 && x<INT_MIN-y))
    throw Int_overflow("+", x, y);          // throw可以调用一个函数??
    // throw INT_MAX; // terminate called after throwing an instance of 'int'

  return x+y;       // x+y 没有溢出
                                        
}


void g() {
  try {
    int i1 = add(1, 2);
    int i2 = add(INT_MAX, -2);
    int i3 = add(INT_MAX, 2);         // 这里发生异常
    int i4 = add(INT_MIN, -2);        // 这里发生异常, 但i3抛出异常在先
    // std:: cout << "i4 = " << i4 << std::endl; 
  }
  catch (Overflow) {
    // 处理Overflow或者任何Overflow派生的异常
  }
  
  catch (Matherr &m) {
    // 处理所有不是Overflowi派生的Matherr
    std::cout << "catched in Matherr" << std::endl;
    m.debug_print();
  }
  /* // 不能被重复catch
  catch (Int_overflow &m) {
    // 处理Int_overflow类
    std::cout << "catched in Int_overflow" << std::endl;
    m.debug_print();
  }
  */
}

int main(){
  g();
  return 0;
}

