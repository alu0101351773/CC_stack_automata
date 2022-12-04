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
    stack_symbols_(stack_symbols)
{ 
    if (automata_states_.find(initial_state) == automata_states_.end()) {
        throw std::runtime_error("Unrecognized initial states");
    }
    initial_state_ = initial_state;
    if (stack_symbols_.find(stack_initial_symbol) == stack_symbols_.end()) {
        throw std::runtime_error("Unrecognized stack symbol");
    }
    stack_ = Stack(stack_initial_symbol);
    for (set<string>::iterator i = final_states.begin(); i != final_states.end(); i++) {
        if (automata_states_.find(*i) == automata_states_.end()) {
            throw std::runtime_error("Final state not contained within state set");
        }
    }
    final_states_ = final_states;
    for (size_t i = 0; i < transition_list.size(); i++)
    {
        if (!CheckTransition(transition_list[i])) {
            throw std::runtime_error("Invalid transition");
        }
    }
    transition_list_ = transition_list;
}


const bool StackAutomata::IsAccepted(const string& word, const bool verbose) {
    char starting_symbol = word[0];
    // 1º: Insert initial state in the stack
    FirstStep(word);

    int iter_counter = 0;

    // 2º: Explore the transition queue
    while (!automata_queue_.empty()) {
        State front_state = automata_queue_.front();
        automata_queue_.pop();
        if (verbose) std::cout << front_state.ToString() << "\n\n";

        if (alphabet_symbols_.find(front_state.GetActualString()[0]) == alphabet_symbols_.end()) {
            // Epsilon cannot be included in the alphabet since it is not a symbol, so must be
            // checked apart
            if (front_state.GetActualString()[0] != EPSILON_SYMBOL) {
                return false;                                           
            }                                                           
        }
        
        if (iter_counter == SA_MAX_ITERATIONS) break;

        if (front_state.GetActualString() == string(1, EPSILON_SYMBOL)) { // empty string
            if (final_states_.find(front_state.GetActualState()) != final_states_.end()) {
                return true;    // It is contained in the final states
            }
            // If the string would transition to a final state with no transitions asociated
            vector<Transition> last_step = front_state.GetPossibleTransitions(); 
            for (size_t i = 0; i < last_step.size(); i++) {
                if (final_states_.find(last_step[i].get_next_state()) != final_states_.end()) {
                    return true;
                }
            }
            
        }
        vector<State> accessible_states = ReachNewStates(front_state);
        for (size_t i = 0; i < accessible_states.size(); i++) {
            automata_queue_.push(accessible_states[i]);
        }
        iter_counter++;
    }
    return false;
}


void StackAutomata::FirstStep(const string& word) {
    char starting_symbol = word[0];
    vector<Transition> possible_transitions = FindTransitions(initial_state_,
        starting_symbol,
        stack_.Top()
    );
    automata_queue_.push(State(initial_state_,
        word,
        stack_.Top(),
        possible_transitions
    ));
}


vector<Transition> StackAutomata::FindTransitions(const string& actual_state,
    const char& actual_symbol,
    const char& actual_stack_symbol) {
    vector<Transition> possible_transitions;
    for (size_t i = 0; i < transition_list_.size(); i++) {
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


vector<State> StackAutomata::ReachNewStates(State front_state) {
    vector<State> accessible_states;
    vector<Transition> possible_transition = front_state.GetPossibleTransitions();
    for (size_t i = 0; i < possible_transition.size(); i++)
    {
        string new_state = possible_transition[i].get_next_state();
        string new_string;
        if (possible_transition[i].get_input_symbol() == EPSILON_SYMBOL){   // Symbol not consumed
            new_string = front_state.GetActualString();
        } else {    // Symbol consumed
            if (front_state.GetActualString().size() == 1) { // one character to "."
                new_string = string(1, EPSILON_SYMBOL);
            } else {
                new_string = front_state.GetActualString().substr(1);
            }
        }
        vector<char> stack_action = possible_transition[i].get_stack_action();
        Stack new_stack = front_state.GetActualStack()
            .Pop()
            .Push(stack_action);
        vector<Transition> new_transitions = FindTransitions(new_state,
            new_string[0],
            new_stack.Top()
        );
        if (new_transitions.empty()) continue;
        accessible_states.push_back(State(new_state, new_string,
            new_stack,
            new_transitions
        ));
    }
    return accessible_states;
}


const bool StackAutomata::CheckTransition(const Transition& transition) const {
    if (automata_states_.find(transition.get_actual_state()) == automata_states_.end()) {
        return false;
    }
    if (automata_states_.find(transition.get_next_state()) == automata_states_.end()) {
        return false;
    }
    if (alphabet_symbols_.find(transition.get_input_symbol()) == alphabet_symbols_.end()) {
        if (transition.get_input_symbol() != EPSILON_SYMBOL) {
            return false;
        }
    }
    if (stack_symbols_.find(transition.get_stack_symbol()) == stack_symbols_.end()) {
        return false;
    }
    for (size_t i = 0; i < transition.get_stack_action().size(); i++) {
        if (stack_symbols_.find(transition.get_stack_action()[i]) == stack_symbols_.end()) {
            return false;
        }
    }
    return true;
}