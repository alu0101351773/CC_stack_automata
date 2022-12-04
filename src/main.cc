#include <iostream>
#include <string>

#include "transition.h"
#include "stack.h"
#include "stack_automata.h"
#include "file_handler.h"

using std::string;

int main(int argc, char **argv) {
    if (argc < 3) {
        std::cout << string(argv[0]) + " usage: <input_file_name> <string> [string ...]" << std::endl; 
        return 1;
    }
    FileHandler input(argv[1]);
    StackAutomata solver(input.GetAutomata());

    for (size_t i = 2; i < argc; i++) {
        string result = (solver.IsAccepted(argv[i]) ? "yes" : "no");
        std::cout << "[" + string(argv[i]) + "]: " + result << std::endl;
    }

    return 0;
}