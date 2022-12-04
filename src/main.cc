#include <iostream>
#include "transition.h"
#include "stack.h"
#include "stack_automata.h"
#include "file_handler.h"

int main() {

    FileHandler pepito("input/APf.txt");
    StackAutomata manolo = pepito.GetAutomata();

    // Transition p1("q0", '3', 'S', "q1", {'A', 'M'});
    // Transition p2("q0", '5', 'S', "q1", {'A', 'M'});
    // Transition p3("q1", 'S', 'A', "q2", {'P'});
    // Transition p4("q2", '.', 'P', "q3", {});

    // vector<Transition> vector_transiciones = {p1, p2, p3, p4};
    // set<string> estados_automata;
    //     estados_automata.insert("q0");
    //     estados_automata.insert("q1");
    //     estados_automata.insert("q2");
    //     estados_automata.insert("q3");
    // set<char> simbolos_alfabeto;
    //     simbolos_alfabeto.insert('3');
    //     simbolos_alfabeto.insert('5');
    //     simbolos_alfabeto.insert('S');
    // set<char> simbolos_pila;
    //     simbolos_pila.insert('S');
    //     simbolos_pila.insert('A');
    //     simbolos_pila.insert('M');
    //     simbolos_pila.insert('P');
    // string estado_inicial = "q0";
    // char simbolo_inicial_stack = 'S';
    // set<string> estados_finales;
    //     estados_finales.insert("q2");

    // StackAutomata pepe(
    //     estados_automata,
    //     simbolos_alfabeto,
    //     simbolos_pila,
    //     estado_inicial,
    //     simbolo_inicial_stack,
    //     estados_finales,
    //     vector_transiciones
    // );

    // std::cout << (pepe.IsAccepted("3S") ? "YES" : "NO") << std::endl;
    // std::cout << (pepe.IsAccepted("3D") ? "YES" : "NO") << std::endl;
    // std::cout << (pepe.IsAccepted("3S") ? "YES" : "NO") << std::endl;
    // std::cout << (pepe.IsAccepted("5") ? "YES" : "NO") << std::endl;

    return 0;
}