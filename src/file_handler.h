#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include <string>
#include <vector>
#include <fstream>
#include <stdexcept>

#include <iomanip>
#include <sstream>

#include "stack_automata.h"

using std::string;
using std::vector;

class FileHandler {
    private:
        string file_name_;

    public:
        FileHandler(const string& file_name);

        StackAutomata GetAutomata(void);

    private:
        set<string> ParseStringSet(const string& buffer);

        set<char> ParseCharSet(const string& buffer);

        Transition ParseTransition(const string& buffer);
};

#endif