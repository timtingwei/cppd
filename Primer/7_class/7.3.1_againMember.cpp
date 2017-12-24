#include <iostream>

class Screen{
public:
  typedef std::string::size_type pos;
  //using pos = std::string::size_type
  Screen() = default;    //because there ara another function
                         //so this function is neccessary
  Screen(pos ht, pos wd, char c):height(ht), width(wd), contents( ht* wd,c) { }
  char get() const {return contents[cursor]; }          //implicitly inline
  inline char get(pos ht, pos wd) const;                //explicitly inline
  Screen &move(pos r, pos c);                           //can be made inline later

  
  char Screen::get(pos r, pos c) const  //declared as inline in the class
  {
    pos row = r * width;      //compute row location
    return contents[row + c]  //return character at the given column
  }
  
  
private:
  pos cursor;
  pos height, width;
  std::string contents;
  
};

inline &Screen::move(pos r, pos c)
{
  pos row = r * width;       //compute the row location
  cursor = row + c;          //move cursor to the column within that row
  return *this;              //return this object as an value
}



int main(){
  return 0;
}
