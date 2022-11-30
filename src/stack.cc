#include "stack.h"

AutomataStack::AutomataStack(const vector<string>& input_symbols_set) {
    Push(input_symbols_set);
}


AutomataStack::AutomataStack(const string& input_symbol) {
    Push(input_symbol);
}


void AutomataStack::Push(const vector<string>& input_symbols_set) {
    for (int i = input_symbols_set.size() - 1; i >= 0; i--) {
        stack_.push(input_symbols_set[i]);
    }
}


void AutomataStack::Push(const string& input_symbol) {
    stack_.push(input_symbol);
}


const string AutomataStack::Pop(void) {
    string extracted_value = stack_.top();
    stack_.pop();
    return extracted_value;
}


const bool AutomataStack::IsEmpty(void) const {
    return stack_.empty();
}