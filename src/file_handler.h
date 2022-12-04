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

/**
 * @brief Read the content of a file and return an automata
 */
class FileHandler {
    private:
        /**
         * @private
         * @brief Name of the file to be parsed
         */
        string file_name_;

    public:
        /**
         * @brief Construct a new File Handler object
         * 
         * @param file_name name of the file
         */
        FileHandler(const string& file_name);

        /**
         * @brief Get the Automata object
         * 
         * @return StackAutomata Automata contained within the file
         */
        StackAutomata GetAutomata(void);

    private:
        /**
         * @private
         * @brief Parse a string as a set of strings
         * 
         * @param buffer selected string
         * @return set<string> parsed set of strings
         */
        set<string> ParseStringSet(const string& buffer);

        /**
         * @private
         * @brief Parse a string as a set of characters
         * 
         * @param buffer selected string
         * @return set<char> parsed set of chars
         */
        set<char> ParseCharSet(const string& buffer);

        /**
         * @private
         * @brief Parse a string as a transition
         * 
         * @param buffer selected string
         * @return Transition parsed transition
         */
        Transition ParseTransition(const string& buffer);
};

#endif