#include <iostream>
#include "transition.h"
#include "stack.h"

int main() {
    Transition pepe("q0", "a", "S", "q1", {"0", "S"});
    std::cout << pepe.ToString() << std::endl;
    std::cout << "Hello, World!" << std::endl;
    return 0;
}