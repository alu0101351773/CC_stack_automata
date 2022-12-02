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
    while (!automata_queue_.empty()) {
        // Extraemos el estado del frente de la cola
        State front_state = automata_queue_.front();
        automata_queue_.pop();
        // TODO: Esta comprobacion no es, es solo comprobar si la cadena esta vacia
        if (front_state.GetActualString() == ".") {
            if (final_states_.find(front_state.GetActualState()) != final_states_.end()) {
                return true;
            }
            // NOTE: Este continue estrictamente no va
            // continue;
        }
        vector<Transition> possible_transition = front_state.GetPossibleTransitions();
        for (size_t i = 0; i < possible_transition.size(); i++)
        {
            string new_state = possible_transition[i].get_next_state();
            string new_string;
            if (front_state.GetActualString().size() == 1) {
                new_string = ".";
            } else {
                new_string = front_state.GetActualString().substr(1);
            }
            vector<char> stack_action = possible_transition[i].get_stack_action();
            Stack new_stack = front_state
                .GetActualStack()
                .Pop()
                .Push(stack_action);
            vector<Transition> new_transitions = FindTransitions(
                new_state,
                new_string[0],
                new_stack.Top()
            );
            automata_queue_.push(State(
                new_state,
                new_string,
                new_stack,
                new_transitions
            ));
        }
    }
    return false;
}


void StackAutomata::FirstStep(const string& word) {
    char starting_symbol = word[0];
    vector<Transition> possible_transitions = FindTransitions(
        initial_state_,
        starting_symbol,
        stack_.Top()
    );
    automata_queue_.push(State(
        initial_state_,
        word,
        stack_.Top(),
        possible_transitions));
}


vector<Transition> StackAutomata::FindTransitions(const string& actual_state,
    const char& actual_symbol,
    const char& actual_stack_symbol) {
    vector<Transition> possible_transitions;
    for (size_t i = 0; i < transition_list_.size(); i++)
    {
        if (transition_list_[i].get_actual_state() == actual_state &&
                (transition_list_[i].get_input_symbol() == actual_symbol ||
                 transition_list_[i].get_input_symbol() == EPSILON_SYMBOL) &&
            transition_list_[i].get_stack_symbol() == actual_stack_symbol)
        {
            possible_transitions.push_back(transition_list_[i]);
        }
    }
    return possible_transitions;
}
