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


//declaracion de funciones------------------------------------------------------
bool esPrimo(int n);
bool entradaInvalida();

//main--------------------------------------------------------------------------
int main() {
    int limite, suma = 0, out=0;

    do{
    cout <<"Hasta que numero quieres hacer la sucecion: "<< endl;
    cin >> limite;

    if (entradaInvalida()) {
        cout<<"ERROR. Debe ser numero"<<endl;
        continue;
    }//fin if

    suma = 0;
    cout<<"Los numeros primos son: "<< endl;
    for (int i = 2; i <= limite; i++) {
        if (esPrimo(i)) {
            cout << i << ",";
            suma += i;
        }//fin if
    }//fin for

    cout<<"\nLa suma total es: "<< suma << endl;

        cout << "\nDeseas salir del programa? (1/0)" << endl;
        cout << "1 <- si" << endl;
        cout << "0 <- no" << endl;
        cin >> out;
        if (entradaInvalida()) {
            out =0;
        }//fin if validacion
    }while (out == 0);
    return 0;
}//fin main


//definicion de funciones-----------------------------------------------------
//verificacion de primo-------------------------------------------------------
bool esPrimo(int n) {
    if (n < 2) return false;
    for (int d = 2; d < n; d++) {
        if (n % d == 0) {
            return false; // Encontró divisor
        }
    }
    return true;
}
bool entradaInvalida() {
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true; // Sí, la entrada es inválida
    }
    return false; // No, la entrada es correcta
}