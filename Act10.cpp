/*
--------------------------------------------------------------------------------
NOMBRE: RAFAEL MARTINEZ JR

CODIGO: 221699977

FECHA: 11/02/2026

PROPOSITO:
--------------------------------------------------------------------------------
*/

#include <iostream>
#include <limits>
using namespace std;

// Variables globales-----------------------------------------------------------
int a;
//declaracion de funciones------------------------------------------------------
bool rango (int num);
bool entradaInvalida();
void secuencia (int num);

//main--------------------------------------------------------------------------
int main() {
    int out=0, num;
    do {
        while (true) {
            cout<<"Ingresa un numero entre el 0 y el 1000"<<endl;
            cin >> num;

            if (entradaInvalida()) {
                cout<<"ERROR. Debe ser numero"<<endl;
                continue;
            }//fin if

            if (!rango(num)) {
                cout << "ERROR. Numero invalido\n" << endl;
                continue;
            }//fin if rango
            break;//salir del bucle psot validacion
        }

       secuencia(num);

        cout << "Deseas salir del programa? (1/0)" << endl;
        cout << "1 <- si" << endl;
        cout << "0 <- no" << endl;
        cin >> out;
        if (entradaInvalida()) {
            out =0;
        }//fin if validacion
    }while (out == 0);
}
//definicion de funciones-------------------------------------------------------

//delimita un rango-------------------------------------------------------------
bool rango (int num) {
    return (num>=0 && num<=1000);
}//fin rango

bool entradaInvalida() {
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true; // Sí, la entrada es inválida
    }
    return false; // No, la entrada es correcta
}

void secuencia (int num) {
    int sum = 0;
    cout << "multiplos de 3" << endl;
    for (int i=3; i<=num*3; i+=3) {
        if (i==3) {
            cout << i;
        }else {
            cout<<"+"<<i;
        }//fin if
        sum = sum + i;
    }//
    cout << "=" << sum << endl;

    sum = 0;
    cout << "multiplos de 5" << endl;
    for (int i=5; i<=num*5; i+=5) {
        if (i==5) {
            cout << i;
        }else {
            cout<<"+"<<i;
        }//fin if
        sum = sum + i;
    }
    cout << "=" << sum << "\n" << endl;
}

