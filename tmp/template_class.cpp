/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:template_class.cpp
   Date:Mon Jan  8 20:51:05 CST 2018
   -----------------------------
*/
/*
  template和class或者template之间的组合
 */

template <typename T> class Vector {
};
class BinTree {
};
template <typename T> class Tree {
};

int main() {
  // ..
  Vector<int> myVector;    // Right

  Vector<float> myfVector;

  Vector<BinTree> binForest;       // Combine with other class;
  Vector<Tree<int>> binForest;     // Combine with template;
  return 0;
}


