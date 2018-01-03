/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:temp_string.cpp
   Date:Wed Jan  3 11:17:00 CST 2018
   -----------------------------
*/

template<class C> class String {
  struct Srep;
  Srep *rep;
 public:
  String();
  String(const C*);
  String(const String&);

  C read(int i) const;
  // ...
}



int main() {
  // ..
  return 0;
}
