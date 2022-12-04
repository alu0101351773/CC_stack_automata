#include "file_handler.h"

FileHandler::FileHandler(const string& file_name) : file_name_(file_name) {

}


StackAutomata FileHandler::GetAutomata(void){
    std::ifstream file;
    file.open(file_name_);

    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file");
    }
    string buffer;
    do { getline(file, buffer); } while(buffer[0] == '#');
    
    set<string> states = ParseStringSet(buffer);

    getline(file, buffer);
    set<char> alphabet = ParseCharSet(buffer);

    getline(file, buffer);
    set<char> stack_alphabet = ParseCharSet(buffer);

    getline(file, buffer);
    string initial_state = buffer;

    getline(file, buffer);
    if (buffer.length() != 1) { throw std::runtime_error("Invalid stack symbol"); }
    char stack_initial_symbol = buffer[0];

    getline(file, buffer);
    set<string> final_states = ParseStringSet(buffer);

    vector<Transition> transition_list;
    while (getline(file, buffer)) {
        transition_list.push_back(ParseTransition(buffer));
    }

    return StackAutomata(
        states,
        alphabet,
        stack_alphabet,
        initial_state,
        stack_initial_symbol,
        final_states,
        transition_list
    );
}


set<string> FileHandler::ParseStringSet(const string& buffer){
    set<string> parsed_set;
    string new_buffer;
    std::stringstream token(buffer);
    while (token >> new_buffer) {
        parsed_set.insert(new_buffer);
    }
    return parsed_set;
}


set<char> FileHandler::ParseCharSet(const string& buffer){
    set<char> parsed_set;
    string new_buffer;
    std::stringstream token(buffer);
    while (token >> new_buffer) {
        parsed_set.insert(new_buffer[0]);
    }
    return parsed_set;
}


Transition FileHandler::ParseTransition(const string& buffer) {
    string element;
    std::stringstream token(buffer);
    
    token >> element;
    string actual_state = element;

    token >> element;
    char input_symbol = element[0];

    token >> element;
    char stack_symbol = element[0];

    token >> element;
    string next_state = element;
    
    vector<char> stack_action;
    while (token >> element) {
        if (element == string(1, EPSILON_SYMBOL)) {
            stack_action.resize(0);
            break;
        }
        stack_action.push_back(element[0]);
    }
    return Transition(
        actual_state,
        input_symbol,
        stack_symbol,
        next_state,
        stack_action
    );

}