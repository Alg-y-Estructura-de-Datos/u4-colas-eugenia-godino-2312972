#include <iostream>
#include "Cola/Cola.h"
#include "Pila/Pila.h"
using namespace std; 

void separar (Cola<int> &cola, Pila<int> pila){
    Cola<int> colaAux;
    while (!cola.esVacia()){
        int valor = cola.desencolar();
        if (valor % 2 == 0){
            colaAux.encolar(valor);
        } else {
            pila.push(valor);
        }
    }
    while (!colaAux.esVacia()){
        cola.encolar(colaAux.desencolar());
    }
}

void mostrarCola(Cola<int> &cola) {
    Cola<int> colaAux;

    while (!cola.esVacia()) {
        int dato = cola.desencolar();
        cout << dato << " ";
        colaAux.encolar(dato);
    }
    cout << endl;

    while (!colaAux.esVacia()) {
        cola.encolar(colaAux.desencolar());
    }
}

int main (){
    Cola<int> cola;
    Pila<int> pila;
    cout << "Ingrese los valores de la cola (termine en -1): "<<endl;
    int input;
    while (cin >> input && input != '-1'){
        cola.encolar(input);
    }
    separar(cola, pila);

    cout << "Cola despues de quitar numeros impares: ";
    mostrarCola(cola);

    cout << "Pila con elementos impares (orden inverso): ";
    while (!pila.esVacia()) {
        cout << pila.pop() << " ";
    }
    cout << endl;

    return 0;
}
