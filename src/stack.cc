#include "stack.h"

Stack::Stack(const vector<char>& input_symbols_set): stack_(input_symbols_set) {

}


Stack::Stack(const char& input_symbol): stack_({input_symbol}) {

}


Stack::Stack(void) {
    
}

Stack Stack::Push(const vector<char>& input_symbols_set) {
    vector<char> updated_stack(stack_);
    for (int i = input_symbols_set.size() - 1; i >= 0; i--) {
        updated_stack.push_back(input_symbols_set[i]);
    }
    return Stack(updated_stack);
}


Stack Stack::Push(const char& input_symbol) {
    vector<char> updated_stack(stack_);
    updated_stack.push_back(input_symbol);
    return Stack(updated_stack);
}


const char Stack::Top(void) const {
    return stack_.back();
}


Stack Stack::Pop(void) {
    if (IsEmpty()) {
        throw std::logic_error("Cannot pop from empty stack");
    }
    vector<char> updated_stack(stack_); 
    updated_stack.pop_back();
    return Stack(updated_stack);
}


const bool Stack::IsEmpty(void) const {
    return stack_.empty();
}


const string Stack::ToString(void) const {
    if (stack_.size() == 0) return "[]";
    else if (stack_.size() == 1) return "[" + string(1, stack_[0]) + "]";
    string stack_repr = "[" + string(1, stack_[0]) + ": ";
    for (size_t i = 1; i < stack_.size(); i++) {
        stack_repr += stack_[i];
        if (i != stack_.size() - 1) stack_repr += ", ";
    }
    stack_repr += "]";
    return stack_repr;
}