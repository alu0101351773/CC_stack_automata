#ifndef STACK_H
#define STACK_H

#include <string>
#include <vector>
#include <stdexcept>

using std::string;
using std::vector;

/**
 * @brief Represents the stack used by a nondeterministic automata
 */
class AutomataStack {
    private:
        /**
         * @private
         * @brief Structure to store symbols (strings) at
         */
        vector<string> stack_;
    public:
        /**
         * @brief Construct a new Automata Stack object
         * 
         * @param input_symbols_set Sequence of symbols to store
         */
        AutomataStack(const vector<string>& input_symbols_set);

        /**
         * @brief Construct a new Automata Stack object
         * 
         * @param input_symbol Unique symbol to store 
         */
        AutomataStack(const string& input_symbol);

        /**
         * @brief Push a sequence of symbols to the stack in order
         * 
         * @param input_symbols_set Sequence of symbols
         * @details The order of the symbols matters, since the first symbols in
         * the vector will be at the top of the stack
         */
        void Push(const vector<string>& input_symbols_set);

        /**
         * @brief Push a unique symbol to the stack
         * 
         * @param input_symbol Unique symbol to store
         */
        void Push(const string& input_symbol);

        /**
         * @brief Extract a symbol from the top of the stack 
         * 
         * @return const string& Extracted symbol 
         */
        const string Pop(void);
        
        /**
         * @brief Check if the stack is empty or not
         * 
         * @return true If the stack is empty
         * @return false If the stack has stuff
         */
        const bool IsEmpty(void) const;

        const string ToString(void) const;
};

#endif