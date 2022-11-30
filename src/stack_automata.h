#ifndef STACK_AUTOMATA_H
#define STACK_AUTOMATA_H

#include <vector>
#include <string>
#include <set>
#include <queue>

#include "transition.h"
#include "stack.h"
#include "state.h"

using std::vector;
using std::string;
using std::set;
using std::queue;

class StackAutomata {
    private:
        set<string> automata_states_;

        set<char> alphabet_symbols_;

        set<char> stack_symbols_;

        string initial_state_;

        set<string> final_states_;

        vector<Transition> transition_list_;

        queue<State> automata_queue_;

        bool is_accepted_;

        Stack stack_;

    public:
        StackAutomata(
            const set<string>& automata_states,
            const set<char>& alphabet_symbols,
            const set<char>& stack_symbols,
            const string& initial_state,
            const char& stack_initial_symbol,
            const set<string>& final_states,
            const vector<Transition>& transition_list
        );

        const bool isAccepted(const string& word);
    
    private:
        void FirstStep(const string& word); 
};

#endif