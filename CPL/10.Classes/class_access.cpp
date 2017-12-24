// Copyright <2017> [Tim Hu]




class Date{
  int d, m, y;
 public:
  void init(int dd, int mm, int yy);     // initialize

  void add_day(int n);                   // add n days
  void add_mouth(int n);                 // add n mouths
  void add_year(int n);                  // add n years
};


inline void Date::add_day(int n) {
  y += n;
}

/*
void timewrap(Date &d) {
  d.y -= 200;                            // date.y is private
}
*/

int main() {
  // ...
  return 0;
}
