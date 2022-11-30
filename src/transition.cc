#include "transition.h"

Transition::Transition(
    const string& actual_state,
    const string& input_symbol,
    const string& stack_symbol,
    const string& next_state,
    const vector<string>& stack_action
) : actual_state_(actual_state),
    input_symbol_(input_symbol),
    stack_symbol_(stack_symbol),
    next_state_(next_state),
    stack_action_(stack_action) {}


Transition::~Transition() {}


const string& Transition::get_actual_state(void) const {
    return actual_state_;
}


const string& Transition::get_input_symbol(void) const {
    return input_symbol_;
}


const string& Transition::get_stack_symbol(void) const {
    return stack_symbol_;
}


const string& Transition::get_next_state(void) const {
    return next_state_;
}


const vector<string>& Transition::get_stack_action(void) const {
    return stack_action_;
}