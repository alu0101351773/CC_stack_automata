#ifndef STATE_H
#define STATE_h

#include <string>
#include <vector>

#include "stack.h"
#include "transition.h"

/**
 * @brief Represents the possible state of an automata, a stack and
 * the possible transitions 
 */
class State {
    private:
        /**
         * @private
         * @brief Actual state in the automata
         */
        string actual_state_;

        /**
         * @private 
         * @brief Actual string at this moment
         */
        string actual_string_;

        /**
         * @private
         * @brief Status of the stack at this moment
         */
        Stack actual_stack_;

        /**
         * @private
         * @brief Possible transitions of the automata given the:
         *  - actual state
         *  - actual string
         *  - stack
         */
        vector<Transition> possible_transitions_;
    
    public:

        /**
         * @brief Construct a new State object
         * 
         * @param actual_state Actual state in the automata
         * @param actual_string Actual string at this moment
         * @param actual_stack Status of the stack at this moment
         * @param possible_transitions Possible transitions of the automata
         * given the actual state, actual string and stack
         */
        State(const string& actual_state, const string& actual_string,
            const Stack actual_stack,
            const vector<Transition>& possible_transitions
        );

        /**
         * @brief Get the Actual State object
         * 
         * @return const string& 
         */
        const string& GetActualState(void) const;

        /**
         * @brief Get the Actual String object
         * 
         * @return const string& 
         */
        const string& GetActualString(void) const;

        /**
         * @brief Get the Actual Stack object
         * 
         * @return const Stack& 
         */
        Stack GetActualStack(void);

        /**
         * @brief Get the Possible Transitions object
         * 
         * @return const vector<Transition>& 
         */
        const vector<Transition>& GetPossibleTransitions(void) const;
};

#endif