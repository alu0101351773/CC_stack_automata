#ifndef STACK_AUTOMATA_H
#define STACK_AUTOMATA_H

#include <vector>
#include <string>
#include <set>

#include "transition.h"
#include "stack.h"
#include "state.h"

using std::vector;
using std::string;
using std::set;

class StackAutomata {
    private:
        set<string> automata_states_;

        set<string> alphabet_symbols_;

        set<string> stack_symbols_;

        string initial_state_;

        set<string> final_states_;

        vector<Transition> transition_list_;

        vector<State> automata_queue_;

        string actual_string_;

        bool is_accepted_;

        Stack stack_;

    public:
        StackAutomata(
            const set<string>& automata_states,
            const set<string>& alphabet_symbols,
            const set<string>& stack_symbols,
            const string& initial_state,
            const char& stack_initial_symbol,
            const set<string>& final_states,
            const vector<Transition>& transition_list
        );

        void InsertString(const string& new_string);

        void Step(void);

        const bool HasFinished(void) const;

        const bool isAccepted(void) const;
};

#endif