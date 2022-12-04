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
    int param_start = 2;
    bool verbose = false;
    if (string(argv[2]) == "-v" || string(argv[2]) == "--verbose") { 
        param_start = 3;
        verbose = true;
    }
    
    FileHandler input(argv[1]);
    StackAutomata solver(input.GetAutomata());
    
    for (int i = param_start; i < argc; i++) {
        string result = (solver.IsAccepted(argv[i], verbose) ? "yes" : "no");
        std::cout << "[" + string(argv[i]) + "]: " + result << "\n\n";
    }

    return 0;
}