#include "stack_automata.h"

StackAutomata::StackAutomata(
    const set<string>& automata_states,
    const set<string>& alphabet_symbols,
    const set<string>& stack_symbols,
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


void StackAutomata::InsertString(const string& new_string) {
    vector<Transition> available_transitions;
    for (size_t i = 0; i < transition_list_.size(); i++)
    {
        // if (transition_list_[i].get_actual_state() == initial_state_ &&
        //     transition_list_[i].get_input_symbol() == new_string[0] &&
        //     )
    }
    
}

void StackAutomata::Step(void) {

}