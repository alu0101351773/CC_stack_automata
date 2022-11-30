#include <iostream>
#include "transition.h"
#include "stack.h"
#include "stack_automata.h"

int main() {
        
    Transition p1("q0", '3', 'S', "q1", {'A', 'M'});
    Transition p2("q0", '3', 'S', "q1", {'A', 'M'});
    Transition p5("q0", '3', 'm', "q1", {'A', 'M'});
    Transition p3("q1", '3', 'S', "q1", {'A', 'M'});
    Transition p4("q2", '3', 'S', "q1", {'A', 'M'});

    vector<Transition> vector_transiciones = {p1, p2, p3, p4, p5};
    set<string> estados_automata;
    set<char> simbolos_alfabeto;
    simbolos_alfabeto.insert('3');
    set<char> simbolos_pila;
    string estado_inicial = "q0";
    char simbolo_inicial_stack = 'S';
    set<string> estados_finales;

    StackAutomata pepe(
        estados_automata,
        simbolos_alfabeto,
        simbolos_pila,
        estado_inicial,
        simbolo_inicial_stack,
        estados_finales,
        vector_transiciones
    );

    pepe.isAccepted("3SAT");

    return 0;
}