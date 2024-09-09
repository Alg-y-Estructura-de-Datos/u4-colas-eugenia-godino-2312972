#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void eliminar (Cola<int> &cola1, int lim){
    Cola<int> colaAux; 

    while (!cola1.esVacia()){
        int valor = cola1.desencolar();
        if (valor <= lim){
            colaAux.encolar(valor);
        }
    }

    while (!colaAux.esVacia()){
        cola1.encolar(colaAux.desencolar());
    }
}

int main() {
    Cola<int> cola1;
    int lim;
    cout << "Ingrese los elementos de la cola (ingrese -1 para terminar)" << endl;
    int input;
    while (cin >> input && input != -1){
        cola1.encolar(input);
    }
    cout << "Ingrese un valor limite: ";
    cin>> lim;

    eliminar(cola1, lim);
    cout << "La cola quedaría: "<<endl;
    while (!cola1.esVacia()){
        cout << cola1.desencolar() << " ";
    }
    cout << endl;
    
    return 0;
}
