#include <iostream>
#include "transition.h"
#include "stack.h"
#include "stack_automata.h"
#include "file_handler.h"

int main(int argc, char *argv[]) {
    FileHandler pepito("input/APf.txt");
    StackAutomata manolo = pepito.GetAutomata();
    string test_string = std::string(argv[1]);
    std::cout << test_string + " es reconocido? " << (manolo.IsAccepted(test_string) ? "yes": "no") << std::endl;

    return 0;
}