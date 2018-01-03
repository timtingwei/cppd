/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:over_string.cpp
   Date:Wed Jan  3 11:26:38 CST 2018
   -----------------------------
*/

class String {
  struct Srep;      // 表示
  Srep *rep;        // 用于异常
 public:
  class Cref;       // 引用char

  class Range {};   // 用于异常
  // ...
};

// 成员类(嵌套类)先声明再定义
struct String::Srep {
  char* s;                 // 到元素的指针
  int sz;                  // 字符个数
  int n;                   // 引用计数

  Srep(int nsz, const char* p) {
    n = 1;
    sz = nsz;
    s = new char[sz+1];    // 为结束符增加空间
    strcpy(s, p);
  }

  ~Srep() {delete[] s;}

  Srep* get_own_copy() {
    if (n == 1) return this;
    n--;
    return new Srep(sz, s);
  }

  void assign(int nsz, const char* p) {
    if (sz != nsz) {
      delete[] s;
      sz = nsz;
      s = new char[sz+1];
    }
    strcpy(s, p);
  }

 private:                 // 防止复制:
  Srep(const Srep&);
  Srep& operator= (const Srep&);
};


int main() {
  // ..
  String<char> cs;
  String<unsigned_char> us;
  String<wchar_t> ws;
  String<Jchar> js;

  return 0;
}
