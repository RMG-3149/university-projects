/*
--------------------------------------------------------------------------------
NOMBRE: RAFAEL MARTINEZ JR

CODIGO: 221699977

FECHA: 22/02/2026

PROPOSITO: PROGRAMA CON CARACTERES ESPECIALES
--------------------------------------------------------------------------------
*/


#include <iostream>
#include <string>
#include <cctype>
#include <limits>
using namespace std;

// Variables globales-----------------------------------------------------------

//declaracion de funciones------------------------------------------------------
bool entradaInvalida();
bool esVocal(char c);
bool esConso(char c);
bool esNum(char c);
int contVocal(const string &frase);
int contConso(const string &frase);
int contNum(const string &frase);
int contEsp(const string &frase);
int contPal(const string &frase);

//main--------------------------------------------------------------------------
int main() {
    int out = 0;
    string txt;

    cout << "Ingrese una frase: \n";
    getline(cin, txt);

    cout << "Vocales: " << contVocal(txt) << endl;
    cout << "Consonantes: " << contConso(txt) << endl;
    cout << "Numeros: " << contNum(txt) << endl;
    cout << "Espacios: " << contEsp(txt) << endl;
    cout << "Palabras: " << contPal(txt) << endl;

    do {
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

//definicion de funciones-------------------------------------------------------
bool entradaInvalida() {
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true; // Sí, la entrada es inválida
    }
    return false; // No, la entrada es correcta
}

// Función para verificar si un carácter es vocal
bool esVocal(char c) {
    c = tolower(c);//tolower hace que se vuelvan minusculas
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}//fin funcion

// Función para verificar si un carácter es consonante
bool esConso(char c) {
    c = tolower(c);
    return (isalpha(c) && !esVocal(c));//isalpha(c) verifica que la frase se encuentre en el alfabeto ((a-z)(A-Z))
}//fin funcion

// Función para verificar si un carácter es número
bool esNum(char c) {
    return isdigit(c);
}//fin funcion

// Contar vocales
int contVocal(const string &frase) {
    int contador = 0;
    for (char c : frase) {
        if (esVocal(c)) contador++;
    }
    return contador;
}//fin funcion

// Contar consonantes
int contConso(const string &frase) {
    int contador = 0;
    for (char c : frase) {
        if (esConso(c)) contador++;
    }
    return contador;
}//fin funcion

// Contar números
int contNum(const string &frase) {
    int contador = 0;
    for (char c : frase) {
        if (esNum(c)) contador++;
    }
    return contador;
}//fin funcion

// Contar espacios
int contEsp(const string &frase) {
    int contador = 0;
    for (char c : frase) {
        if (isspace(c)) contador++;
    }
    return contador;
}//fin funcion

// Contar palabras (separadas por espacios)
int contPal(const string &frase) {
    int contador = 0;
    bool dentroPalabra = false;

    for (char c : frase) {
        if (isspace(c)) {
            dentroPalabra = false;
        } else {
            if (!dentroPalabra) {
                contador++;
                dentroPalabra = true;
            }
        }
    }
    return contador;
}//fin funcion