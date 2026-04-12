/*
--------------------------------------------------------------------------------
NOMBRE: RAFAEL MARTINEZ JR

CODIGO: 221699977

FECHA: 04/02/2026

PROPOSITO: PROGRAMA CON CARACTERES ESPECIALES
--------------------------------------------------------------------------------
*/

#include <chrono>
#include <iostream>
#include <limits>
using namespace std;

// Variables globales-----------------------------------------------------------

//declaracion de funciones------------------------------------------------------
bool rango (int n);
bool entradaInvalida();
void collatz (int n, int cont);

//main--------------------------------------------------------------------------
int main() {
    int n, out, cont=0;
    do {

        while (true) {
			cout << "Bienvenido a la conjetura de collatz" << endl;

            cout<<"Ingresa un numero: \n";
            cin>>n;

            if (entradaInvalida()) {
                cout<<"ERROR. Debe ser numero"<<endl;
                continue;
            }//fin if

            if (!rango(n)) {
                cout << "ERROR. Numero invalido\n" << endl;
                continue;
            }//fin if rango

            break;//salir del bucle post validacion

        }// fin while

        auto inicio = chrono::high_resolution_clock::now();//marca de inicio
        collatz(n, cont);
        auto fin = chrono::high_resolution_clock::now();//marca de fin

    	chrono::duration<double> duracion = fin - inicio;// Calcula la duració
    	cout << "\nEl proceso tardo " << duracion.count() << " segundos en ejecutarse.\n";

        cout << "\nDeseas salir del programa? (1/0)" << endl;
        cout << "1 <- si" << endl;
        cout << "0 <- no" << endl;
        cin >> out;
        if (entradaInvalida()) {
            out =0;
        }//fin if validacion
    }while (out == 0);
}//fin main

//definicion de funciones-------------------------------------------------------

//delimita un rango-------------------------------------------------------------
bool rango (int n) {
    return (n>=1 && n<=1000000);
}//fin rango

//verifica que cin este bien----------------------------------------------------
bool entradaInvalida() {
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true; // Sí, la entrada es inválida
    }
    return false; // No, la entrada es correcta
}

//conjetura de collatz-----------------------------------------------------------
void collatz (int n, int cont) {
	cout << n;
    while (n != 1) {
		cont++;

		if (n % 2 != 0) {
			n = (n*3) + 1;
		}else {
			n = n / 2;
			if (n == 1) {
			    cout << ", 1" << endl;
				break;
			}
		}
	    cout << ", " << n;
	}
	cout << "\nTiene  " << cont << " procesos para llegar a 1" << endl;
}
