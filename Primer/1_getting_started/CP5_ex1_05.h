// Copyright [2018] <HankDaly>
// ex1_05.h

void foo_05() {
  /*
  std::cout << "Enter two numbers:" << std::endl;
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "The sum of ";
  std::cout << v1;
  std::cout << " and ";
  std::cout << v2;
  std::cout << " is ";
  std::cout << v1 + v2 << std::endl;
  */
  std::cout << "Enter two numbers:\n";
  int v1 = 0, v2 = 0;
  std::cin >> v1 >> v2;
  std::cout << "The sum of " << v1 << " and " << v2
            << " is " << v1 + v2 << std::endl;
}
