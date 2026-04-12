/*
--------------------------------------------------------------------------------
NOMBRE: RAFAEL MARTINEZ JR

CODIGO: 221699977

FECHA: 02/03/2026

PROPOSITO: Conversion numerica de base
--------------------------------------------------------------------------------
*/

#include <iostream>
#include <sstream>
#include <limits>
using namespace std;

//---Variables------------------------------------------------------------------
const int MAX = 7; // máximo de discos
int torreA[MAX], torreB[MAX], torreC[MAX];
int topeA, topeB, topeC;

//Declaracion de funciones------------------------------------------------------
void Hanoi();
void inicializar(int n);
void mostrar();
bool mover(int &topeOrigen, int origen[], int &topeDestino, int destino[], int pasos);
void juego(int n);
void reglas();
int dificultad ();
bool entradaInvalida();
int salir (int out);

//main--------------------------------------------------------------------------
int main() {
    Hanoi();
    return 0;
}

void Hanoi() {
    int opcion, discos=3, out=0;

    do {
        cout << "\n***Torres de Hanoi***" << endl;
        cout << "***Menu de Opciones***" << endl;
        cout << "1 <- Jugar" << endl;
        cout << "2 <- Reglas" << endl;
        cout << "3 <- Dificultad" << endl;
        cout << "Cualquier otro <- Salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                if (discos <= 0 || discos > MAX) {
                    cout << "Primero selecciona la dificultad (opcion 3)." << endl;
                } else {
                    juego(discos);
                }
                out = salir(out);
                break;
            case 2:
                reglas ();
                break;
            case 3:
                discos = dificultad ();
                break;
            default:
                out = salir(out);
        }//fin switch
    }while (out == 0);

}//fin hanoi

void inicializar(int n) {
    topeA = n;// Inicializar torre A con n discos
    topeB = 0;
    topeC = 0;
    for (int i = 0; i < n; i++) {
        torreA[i] = n - i; //grande abajo, pequeño arriba
    }//fin for
}//fin inicializar

void mostrar() {//mostrar torres de hanoi
    cout << "\nA: ";
    for (int i = 0; i < topeA; i++) cout << torreA[i] << " ";
    cout << "\nB: ";
    for (int i = 0; i < topeB; i++) cout << torreB[i] << " ";
    cout << "\nC: ";
    for (int i = 0; i < topeC; i++) cout << torreC[i] << " ";
    cout << "\n";
}//fin mostrar

bool mover(int &topeOrigen, int origen[], int &topeDestino, int destino[], int pasos) {// Función recursiva para validar y mover discos

    if (pasos == 0) {// Caso base: si no hay discos que mover
        return true;
    }//fin if

    if (topeOrigen == 0) {// Intentar mover el disco superior
        cout << "La torre de origen esta vacia.\n";
        return false;
    }//fin if

    if (topeDestino > 0 && origen[topeOrigen - 1] > destino[topeDestino - 1]) {//validacion de movimiento
        cout << "Movimiento invalido: disco grande sobre uno pequenio.\n";
        return false;
    }//fin if

    //Hace el cambio
    destino[topeDestino] = origen[topeOrigen - 1];
    topeDestino++;
    topeOrigen--;

    return true;
}//fin mostrar

// Juego interactivo con recursividad en la validación
void juego(int n) {
    inicializar(n);
    mostrar();

    while (topeC != n) {
        char o, d;
        cout << "\nMover de (A/B/C): ";
        cin >> o;
        cout << "Mover a (A/B/C): ";
        cin >> d;

        int *origen, *destino;
        int *topeOrigen, *topeDestino;

        if (o == 'A' || o =='a') {
            origen = torreA; topeOrigen = &topeA;
        }else if (o == 'B' || o == 'b') {
            origen = torreB; topeOrigen = &topeB;
        }else {
            origen = torreC; topeOrigen = &topeC;
        }//fin if else

        if (d == 'A' || d == 'a') {
            destino = torreA; topeDestino = &topeA;
        }else if (d == 'B' || d == 'b') {
            destino = torreB; topeDestino = &topeB;
        }else {
            destino = torreC; topeDestino = &topeC;
        }//fin if else

        mover(*topeOrigen, origen, *topeDestino, destino, 1);//validar movimiento

        mostrar();
    }//fin while
    cout << "\n¡Felicidades! Has completado las Torres de Hanoi.\n";
}//fin juego

void reglas() {
    cout << "\t***Bienvenido a las torres de Hanoi***" << endl;
    cout << "El juego consiste en trasladar los discos ( en este caso numeros ) de dicho eje (A) a la torre (C)" << endl;
    cout << "con movimientos sucesivos, pero teniendo en cuenta que solamente debera moverse un numero por vez," << endl;
    cout << "estando prohibido colocar un numero de mayor cantidad sobre uno de menor cantidad." << endl;
    cout << "\nBuena suerte :) "<< endl;
}//fin reglas

int dificultad () {
    int d, a = 0;
    do {
        while (true) {
            cout << "Ingrese el numero de discos (max " << MAX << "): ";
            cin >> d;

            if (d <= 0 || d > MAX) {
                cout << "ERROR. fuera de limite" << endl;
            }else {
                a=1;
            }//fin if else
            if (entradaInvalida()) {
                cout<<"ERROR. Debe ser numero \n"<<endl;
                continue;
            }//fin if
            break;
        }//fin while
    }while (a==0);
    return d;
}//fin dificultad

bool entradaInvalida() {
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true; // Sí, la entrada es inválida
    }//fin if
    return false; // No, la entrada es correcta
}//fin verificacion

int salir (int out) {
    if (out == 0) {
        cout << "\nDeseas salir del programa? (1/0)" << endl;
        cout << "1 <- si" << endl;
        cout << "0 <- no" << endl;
        cin >> out;
        if (entradaInvalida()) {
            out =0;
        }//fin if validacion
    }//fin if
    return out;
}//fin salir