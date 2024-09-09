#include <iostream>
#include "Cola/Cola.h"
using namespace std;

void eliminarNumero (Cola<int> &cola1, int n){
    Cola<int> colaAux;
    bool encontrado = false;
    bool numeroEncontrado = false;
    while (!cola1.esVacia()){
        int valor = cola1.desencolar();
        if (valor == n){
            if (!encontrado){
                colaAux.encolar(valor);
                encontrado = true;
            }
            numeroEncontrado = true;
        } else {
            colaAux.encolar(valor);
        }
    }
    
    if (!numeroEncontrado){
        cout << "Error, el numero no esta presente en la cola"<<endl;
    }
    while (!colaAux.esVacia()){
        cola1.encolar(colaAux.desencolar());
    }
}

int main() {
    Cola<int> cola1;
    int n; 
    cout << "Ingrese los valores de la cola (termine con -1)"<<endl;
    int input;
    while (cin >> input && input !=-1){
        cola1.encolar(input);
    }
    cout << "Ingrese el numero a eliminar de la cola: ";
    cin >> n;

    eliminarNumero (cola1, n);
    cout<<"La cola quedaria: "<<endl;
    while (!cola1.esVacia()){
        cout << cola1.desencolar() << " "<<endl;
    }
    return 0;
}
