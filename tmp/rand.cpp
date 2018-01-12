/*  ------------------------------
    Copyright <2018> [Tim Hu]
    email: timtingwei@hotamail.com    
   ------------------------------
   File:rand.cpp
   Date:Fri Jan 12 20:17:37 CST 2018
   -----------------------------
*/
// #include <cstdlib>
#include <iostream>
#include <ctime>

int main() {
  // std::srand(std::time(0));
  int random_variable = std::rand();
  std::cout << "Random value on [0, " << RAND_MAX << "]: "
            << random_variable << '\n';
}
