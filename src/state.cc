#include "state.h"

State::State(const string& actual_state, const string& actual_string,
    const Stack actual_stack,
    const vector<Transition>& possible_transitions
) : actual_state_(actual_state), actual_string_(actual_string),
    actual_stack_(actual_stack),
    possible_transitions_(possible_transitions) {}


const string& State::GetActualState(void) const {
    return actual_state_;
}


const string& State::GetActualString(void) const {
    return actual_string_;
}


Stack State::GetActualStack(void){
    return actual_stack_;
}


const vector<Transition>& State::GetPossibleTransitions(void) const {
    return possible_transitions_;
}