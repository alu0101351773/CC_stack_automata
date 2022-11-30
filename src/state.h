#ifndef STATE_H
#define STATE_h

#include <string>
#include <vector>

#include "stack.h"
#include "transition.h"

class State {
    private:
        string actual_state_;

        string actual_string_;

        Stack actual_stack_;

        vector<Transition> possible_transitions_;
    
    public:

        State(
            const string& actual_state,
            const string& actual_string,
            const Stack& actual_stack,
            const vector<Transition>& possible_transitions
        );

        const string& GetActualState(void) const;

        const string& GetActualString(void) const;

        const Stack& GetActualStack(void) const;

        const vector<Transition>& GetPossibleTransitions(void) const;
};

#endif