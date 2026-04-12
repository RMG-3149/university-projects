/*
--------------------------------------------------------------------------------
NOMBRE: RAFAEL MARTINEZ JR

CODIGO: 221699977

FECHA: 09/02/2026

PROPOSITO: ESTE PROGRAMA ES UN FIBONACCI
--------------------------------------------------------------------------------
*/

#include <iostream>
#include <limits>
using namespace std;

//---Variables------------------------------------------------------------------
char toLowerCase(char c);
void limpstring (const string &txt, string &clean);
string espejo (const string &cadena);
bool polin(const string &cadena);
bool esnum(const string &cadena);

int main() {
    int out = 0;
    string entrada, limpia, in;

    do{
        cout << "Ingresa un digito o texto:\n ";
        getline(cin, entrada);

        limpstring (entrada, limpia);
        in = espejo(limpia);

        cout << "Resultado: " << in << endl;

        if (esnum(limpia)) {
            if (polin(limpia)) {
                cout << "Es Capicua." << endl;
            } else {
                cout << "No es Capicua." << endl;
            }
        } else {
            if (polin(limpia)) {
                cout << "Es Polindromo." << endl;
            } else {
                cout << "No es Polindromo." << endl;
            }
        }

        cout << "\nDeseas salir del programa? (1/0)" << endl;
        cout << "1 <- si" << endl;
        cout << "0 <- no" << endl;
        cin >> out;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    }while (out == 0);
    return 0;
}

//---Funciones------------------------------------------------------------------
// Función para convertir mayúsculas a minúsculas
char toLowerCase(char c) {
    const char mayus[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char minus[] = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < 26; i++) {
        if (c == mayus[i]) {
            return minus[i];
        }//fin if
    }//fin for
    return c; // Si no es mayúscula, se devuelve igual
}

// Función para limpiar la cadena eliminar espacios y pasar a minúsculas (basado en ia :c)
void limpstring (const string &txt, string &clean) {
    clean = "";
    for (char c : txt) {
        if (c != ' ') {
            clean += toLowerCase(c);
        }// fin if
    }///fin void
}//fin void

// Función para invertir la cadena
string espejo (const string &cadena) {
    int len = 0;
    while (cadena[len] != '\0') {
        len++;
    }// fin while

    string invertida = "";
    for (int i = len - 1; i >= 0; i--) {
        invertida += cadena[i];
    }// fin for
    return invertida;
}//fin espejo


// Función para verificar si es palíndromo/capicúa
bool polin(const string &cadena) {
    int len = 0;
    while (cadena[len] != '\0') {// recorre hasta el salto
        len++;
    }//fin while

    int i = 0, j = len - 1;
    while (i < j) {
        if (cadena[i] != cadena[j]) {
            return false;
        }//fin if
        i++;
        j--;
    }// fin while
    return true;
}


// Función para verificar si la entrada es numérica
bool esnum(const string &cadena) {
    for (char c : cadena) {
        if (c < '0' || c > '9') {
            return false;
        }//fin if
    }//fin for
    return true;
}
