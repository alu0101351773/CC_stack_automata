#include "transition.h"

Transition::Transition(const string& actual_state, const char& input_symbol,
    const char& stack_symbol,
    const string& next_state,
    const vector<char>& stack_action
) : actual_state_(actual_state), input_symbol_(input_symbol),
    stack_symbol_(stack_symbol),
    next_state_(next_state),
    stack_action_(stack_action) {}


Transition::~Transition() {}


const string& Transition::get_actual_state(void) const {
    return actual_state_;
}


const char& Transition::get_input_symbol(void) const {
    return input_symbol_;
}


const char& Transition::get_stack_symbol(void) const {
    return stack_symbol_;
}


const string& Transition::get_next_state(void) const {
    return next_state_;
}


const vector<char>& Transition::get_stack_action(void) const {
    return stack_action_;
}


const string Transition::ToString(void) const {
    string vector_representation = "[";
    for (size_t i = 0; i < stack_action_.size(); i++)
    {
        vector_representation += stack_action_[i];
        if (i != stack_action_.size() - 1)
        {
            vector_representation += ", ";
        }
    }
    vector_representation += "]";
    
    return "{ " + actual_state_ + 
        " (" + input_symbol_ + ", " + stack_symbol_ +
        ") → " + next_state_ + " " + vector_representation + " }";
}