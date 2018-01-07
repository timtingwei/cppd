/*
-------------------------------
  Copyright <2018>[Tim Hu]
  file:swtich.cpp
  Date:Sun Jan  7 22:01:41 CST 2018
------------------------------ 
*/

#include <iostream>
enum Camera_Movement {
  FORWARD,
  BACKWARD,
  LEFT,
  RIGHT
};

int main() {
  //..

  int i = 3;
  switch (i) {
    case 1: std::cout << "1" << std::endl;
      break;
    case 2: std::cout << "2" << std::endl;
      break;
    case 3: std::cout << "3" << std::endl;
      break;
    case 4:
      break;
    case 5: std::cout << "5" << std::endl;
      break;
    case 6: std::cout << "6" << std::endl;
      break;
    default: std::cout << "default" << std::endl;
      break;
  }
  Camera_Movement direction;
  direction = BACKWARD;
  switch (direction) {
    case FORWARD: std::cout << "FORWARD" << std::endl;
      break;
    case BACKWARD: std::cout << "BACKWARD" << std::endl;
      break;
    default: std::cout << "default" << std::endl;
  }
}
