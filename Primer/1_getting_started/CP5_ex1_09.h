// Copyright [2018] <HankDaly>
// ex1_09.h

#include <iostream>
int foo_09() {
    int sum = 0, val = 50;
    while (val <= 100) {
        sum += val;
        ++val;
    }
    std::cout<< "Sum of 50 to 100 inclusive is "
             << sum << std::endl;
    return 0;
}
