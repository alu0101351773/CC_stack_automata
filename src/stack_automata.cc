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
        // Comprobamos la cadena está vacía y no existen más transiciones
        if (front_state.GetPossibleTransitions().empty()) {
            // si lo está miramos el estado en el que nos encontramos
            // si este estado pertenece a los estados de aceptacion: true
            // si no: descartamos y seguimos por otro camino
            if (final_states_.find(front_state.GetActualState()) != final_states_.end()) {
                return true;
            }
            continue;
        }  
        vector<Transition> possible_transition = front_state.GetPossibleTransitions();
        for (size_t i = 0; i < possible_transition.size(); i++)
        {
            vector<char> stack_action = possible_transition[i].get_stack_action();
            // Metemos en la cola un nuevo estado que sea "what if le aplicamos I transición al estado original"
            // Se cambia de estado
            // Se cambia la string (puede que se reduzca o se quede igual)
            // Se cambia la pila (siempre se va a leer)
            // Se cambia la pila (puede ser que se escriba 1 o más weas en la pila)
            // Se calculan las siguiente transiciones posibles
            automata_queue_.push(State(
                possible_transition[i].get_next_state(),
                front_state.GetActualString().substr(1, front_state.GetActualString().size() - 2),
                front_state.GetActualStack().Pop().Push(stack_action),
                {} // TODO: Aqui hay que guardar las transiciones posibles para este estado
                // no hay función para ello ahora mismo, se lo encasqueto al jorge del futuro
            ));
        }
    }
    // ...
    return false;
}


void StackAutomata::FirstStep(const string& word) {
    char starting_symbol = word[0];
    vector<Transition> possible_transitions;
    for (size_t i = 0; i < transition_list_.size(); i++) {
        if (transition_list_[i].get_actual_state() == initial_state_ &&
                (transition_list_[i].get_input_symbol() == starting_symbol ||
                 transition_list_[i].get_input_symbol() == EPSILON_SYMBOL) &&
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

