#include "stack.h"

AutomataStack::AutomataStack(const vector<string>& input_symbols_set):
    stack_(input_symbols_set) {}


AutomataStack::AutomataStack(const string& input_symbol):
    stack_({input_symbol}) {}


AutomataStack::AutomataStack(void) {}

const AutomataStack AutomataStack::Push(const vector<string>& input_symbols_set) {
    vector<string> updated_stack(stack_);
    for (int i = input_symbols_set.size() - 1; i >= 0; i--) {
        updated_stack.push_back(input_symbols_set[i]);
    }
    return AutomataStack(updated_stack);
}


const AutomataStack AutomataStack::Push(const string& input_symbol) {
    vector<string> updated_stack(stack_);
    updated_stack.push_back(input_symbol);
    return AutomataStack(updated_stack);
}


const string AutomataStack::Top(void) const {
    return stack_.back();
}


const AutomataStack AutomataStack::Pop(void) {
    if (IsEmpty()) {
        throw std::logic_error("Cannot pop from empty stack");
    }
    vector<string> updated_stack(stack_); 
    updated_stack.pop_back();
    return AutomataStack(updated_stack);
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