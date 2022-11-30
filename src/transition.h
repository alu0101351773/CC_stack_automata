#ifndef TRANSITION_H
#define TRANSITION_H

#include <string>
#include <vector>

using std::string;
using std::vector;

/**
 * @brief Represents a transition in a nondeterministic automata
 */
class Transition {
    private:
        /**
         * @private
         * @brief State where the transition starts
         */
        string actual_state_;

        /**
         * @private
         * @brief Symbol read from the input string in the actual state
         */
        string input_symbol_;

        /**
         * @private
         * @brief Symbol read from the top of the stack in the actual state
         */
        string stack_symbol_;

        /**
         * @private
         * @brief Next state to transition if the input symbol and the stack
         * symbol are read while in the actual state
         */
        string next_state_;

        /**
         * @private
         * @brief Sequence of symbols to write at the top of the stack
         */
        vector<string> stack_action_;

    public:
        /**
         * @brief Construct a new Transition object
         * 
         * @param actual_state State where the transition starts
         * @param input_symbol Symbol read from the input string
         * in the actual state
         * @param stack_symbol Symbol read from the top of the stack
         * in the actual state
         * @param next_state Next state to transition if the input symbol
         * and the stack symbol are read while in the actual state
         * @param stack_action Sequence of symbols to write at the top
         * of the stack
         */
        Transition(
            const string& actual_state,
            const string& input_symbol,
            const string& stack_symbol,
            const string& next_state,
            const vector<string>& stack_action
        );

        /**
         * @brief Destroy the Transition object
         */
        ~Transition();

        /**
         * @brief Get the state where the transition starts
         * @return const string& 
         */
        const string& get_actual_state(void) const;

        /**
         * @brief Get the symbol read from the input string in the actual state
         * @return const string& 
         */
        const string& get_input_symbol(void) const;

        /**
         * @brief Get the symbol read from the top of the stack
         * in the actual state
         * @return const string& 
         */
        const string& get_stack_symbol(void) const;

        /**
         * @brief Get the next state to transition if the input symbol and
         * the stack symbol are read while in the actual state
         * @return const string& 
         */
        const string& get_next_state(void) const;

        /**
         * @brief Get the sequence of symbols to write at the top of the stack
         * @return const vector<string>& 
         */
        const vector<string>& get_stack_action(void) const;

        /**
         * @brief Get the string representation of a transition
         * 
         * @return const string transition in string format
         */
        const string ToString(void) const;
};

#endif