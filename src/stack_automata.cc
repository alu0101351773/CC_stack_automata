#include "stack_automata.h"

StackAutomata::StackAutomata(
    const set<string>& automata_states,
    const set<char>& alphabet_symbols,
    const set<char>& stack_symbols,
    const string& initial_state,
    const char& stack_initial_symbol,
    const set<string>& final_states,
    const vector<Transition>& transition_list
) :
    automata_states_(automata_states),
    alphabet_symbols_(alphabet_symbols),
    stack_symbols_(stack_symbols),
    initial_state_(initial_state),
    stack_(stack_initial_symbol),
    final_states_(final_states),
    transition_list_(transition_list)
{ }


const bool StackAutomata::isAccepted(const string& word) {
    char starting_symbol = word[0];
    if (alphabet_symbols_.find(starting_symbol) == alphabet_symbols_.end()) {
        return false;
    }
    // 1º paso: Introducir el estado inicial en la pila
    FirstStep(word);

    // 2º paso: Recorrer la cola de transiciones
    // while (!automata_queue_.empty()) {
    //     // TODO: do stuff here
    // }

    // ...
    return false;
}


void StackAutomata::FirstStep(const string& word) {
    char starting_symbol = word[0];
    vector<Transition> possible_transitions;
    for (size_t i = 0; i < transition_list_.size(); i++) {
        if (transition_list_[i].get_actual_state() == initial_state_ &&
            transition_list_[i].get_input_symbol() == starting_symbol &&
            transition_list_[i].get_stack_symbol() == stack_.Top())
        {
            possible_transitions.push_back(transition_list_[i]);
        }
    }
    automata_queue_.push(State(
        initial_state_,
        word,
        stack_.Top(),
        possible_transitions
    ));
}

