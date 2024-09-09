#include <iostream>
#include "Cola/Cola.h"
using namespace std; 

int suma (Cola<int> &cola1, int n){
    Cola<int> colaAux; 
    int resultado = 0; 
    bool encontrado = false;
    while (!cola1.esVacia()){
        int valor = cola1.desencolar();
        if (valor == n){
            encontrado = true;
            colaAux.encolar(valor);
        }
        else {
            resultado += valor;
            colaAux.encolar(valor);
        }
    }
     while (!colaAux.esVacia()) {
        cola1.encolar(colaAux.desencolar());
    }

    if (!encontrado) {
        int sumaTotal = 0;

        while (!cola1.esVacia()) {
           sumaTotal += cola1.desencolar();
        }

        while (!colaAux.esVacia()) {
            cola1.encolar(colaAux.desencolar());
        }

        return sumaTotal;
    }

    return resultado;
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
    Cola<int> cola1;
    int n; 
    cout << "Ingrese los valores de la cola (termine en -1): "<<endl;
    int input;
    while (cin >> input && input != '-1'){
        cola1.encolar(input);
    }
    cout << "Ingrese un entero: ";
    cin >> n;

    cout << "Cola original: "<<endl;
    mostrarCola(cola1);

    suma(cola1, n);
    cout << "La cuma de los elementos hasta el numero ingresado es: "<<suma(cola1,n)<<endl;
    return 0;
}