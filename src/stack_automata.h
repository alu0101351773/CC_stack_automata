#ifndef STACK_AUTOMATA_H
#define STACK_AUTOMATA_H

#include <vector>
#include <string>
#include <set>
#include <queue>

#include "transition.h"
#include "stack.h"
#include "state.h"

using std::vector;
using std::string;
using std::set;
using std::queue;

#define SA_MAX_ITERATIONS 1000

/**
 * @brief Implements a non-deterministic stack automata
 * to recognize strings
 */
class StackAutomata {
    private:
        /**
         * @private
         * @brief Set of states that our automata should recognize
         */
        set<string> automata_states_;

        /**
         * @private
         * @brief Set of symbol that the automata can recognize from input
         */
        set<char> alphabet_symbols_;

        /**
         * @private
         * @brief Set of symbols that the automata can read or store in the stack
         */
        set<char> stack_symbols_;

        /**
         * @private
         * @brief Initial state of our automata
         */
        string initial_state_;

        /**
         * @private
         * @brief Set of final states where the automata finishes and
         * accepts the string 
         */
        set<string> final_states_;

        /**
         * @private
         * @brief List of possible transitions of our automata 
         */
        vector<Transition> transition_list_;

        /**
         * @private
         * @brief Work queue of our automata
         */
        queue<State> automata_queue_;

        /**
         * @private
         * @brief Original stack of our program 
         */
        Stack stack_;

    public:
        // TODO: Comment this
        /**
         * @brief Construct a new Stack Automata object
         * 
         * @param automata_states 
         * @param alphabet_symbols 
         * @param stack_symbols 
         * @param initial_state 
         * @param stack_initial_symbol 
         * @param final_states 
         * @param transition_list 
         */
        StackAutomata(
            const set<string>& automata_states,
            const set<char>& alphabet_symbols,
            const set<char>& stack_symbols,
            const string& initial_state,
            const char& stack_initial_symbol,
            const set<string>& final_states,
            const vector<Transition>& transition_list
        );

        /**
         * @brief Check if the given string is accepted by the automata
         * 
         * @param word string to be parsed
         * @return true if the string is accepted
         * @return false if the string is not accepted OR the automata has
         * reached the max amount of iterations
         */
        const bool isAccepted(const string& word);
    
    private:
        /**
         * @brief Interation zero where we insert the first state in the queue
         * 
         * @param word string which first transitions will be searched
         */
        void FirstStep(const string& word);

        /**
         * @brief Find all possible transitions from a state, a symbol and a
         * stack symbol
         * 
         * @param actual_state initial state
         * @param actual_symbol symbol readed from string
         * @param actual_stack_symbol symbol readed at the top of the stack
         * @return vector<Transition> set of transitions
         */
        vector<Transition> FindTransitions(const string& actual_state,
            const char& actual_symbol,
            const char& actual_stack_symbol
        );

        /**
         * @brief Get all states accessible from the given states
         * 
         * @param front_state given state
         * @return vector<State> List of states
         */
        vector<State> ReachNewStates(State front_state);

        /**
         * @brief Check if all the components of a given states are within the
         * bounds of the autiomata
         * 
         * @param state state to be analyzed
         * @return true if the state, next state, input, stack and so one are
         * valid
         * @return false otherwise 
         */
        const bool VerificateState(const State& state) const;
};

#endif