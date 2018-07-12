// Copyright [2018] <HankDaly>
// ex1_10.h

#include <iostream>
int foo_10() {
    int val = 10;
    while (val >= 0) {
        std::cout<< val << std::endl;
        --val;
    }
    return 0;
}
