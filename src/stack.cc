#include "stack.h"

AutomataStack::AutomataStack(const vector<string>& input_symbols_set) {
    Push(input_symbols_set);
}


AutomataStack::AutomataStack(const string& input_symbol) {
    Push(input_symbol);
}


void AutomataStack::Push(const vector<string>& input_symbols_set) {
    for (int i = input_symbols_set.size() - 1; i >= 0; i--) {
        stack_.push_back(input_symbols_set[i]);
    }
}


void AutomataStack::Push(const string& input_symbol) {
    stack_.push_back(input_symbol);
}


const string AutomataStack::Pop(void) {
    if (IsEmpty()) {
        throw std::logic_error("Cannot pop from empty stack");
    } 
    string extracted_value = stack_.back();
    stack_.pop_back();
    return extracted_value;
}


const bool AutomataStack::IsEmpty(void) const {
    return stack_.empty();
}


const string AutomataStack::ToString(void) const {
    if (stack_.size() == 0) return "[]";
    else if (stack_.size() == 1) return "[" + stack_[0] + "]";
    string stack_repr = "[" + stack_[0] + ": ";
    for (size_t i = 1; i < stack_.size(); i++) {
        stack_repr += stack_[i];
        if (i != stack_.size() - 1) stack_repr += ", ";
    }
    stack_repr += "]";
    return stack_repr;
}