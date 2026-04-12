/*
--------------------------------------------------------------------------------
NOMBRE: RAFAEL MARTINEZ JR

CODIGO: 221699977

FECHA: 02/03/2026

PROPOSITO: LLENA MATRICES
--------------------------------------------------------------------------------
*/

#include <iostream>
#include <limits>
#include <cstdlib>   // para rand() y srand()
#include <ctime>     // para time()
using namespace std;

//---Variables------------------------------------------------------------------
int x, matriz[10][10];//tamaño de la matriz maxima
//Declaracion de funciones------------------------------------------------------
void start ();
void manual (int x);
void aleatorio (int x);
void mostrar (int x);
bool entradaInvalida();
//main--------------------------------------------------------------------------
int main() {
    srand(time(nullptr)); //genera la semilla aleatoria
    start();
    return 0;
}//fin main

//definicion de funciones-------------------------------------------------------

//Funcion principal-------------------------------------------------------------
void start () {
    int opcion, out=0;

    do {
        cout << "***Menu de opciones***" << endl;
        cout << "1 <- Llenar matiz de manera maunal" << endl;
        cout << "2 <- Llenar matiz de manera aleatoria" << endl;
        cout << "3 <- Mostrar matriz" << endl;
        cout << "x <- Salir" << endl;// x es cualquier caracter u otro numero
        cin >> opcion;

        if (opcion == 2 || opcion == 1) {
            do {
                while (true) {
                    cout << "Ingresa un rango de matriz (Maximo [10])" << endl;
                    cin >> x;//esta variable limita un rango de la matriz x*x

                    if (entradaInvalida()) {
                        cout<<"ERROR. Debe ser numero \n"<<endl;
                        continue;
                    }//fin if
                    break;
                }//fin verificacion

                if (x > 10 || x < 1) {
                    cout << "ERROR. Rango fuera de limite \n" << endl;
                }//fin if
            }while (x > 10 || x < 1);

            cout << "Tu Matriz sera de ["<< x <<"]["<< x <<"]" << endl;
            cout << "con " << x*x << " espacios\n" <<endl;
        }

        switch (opcion) {
            case 1:
                manual(x);
                break;
            case 2:
                aleatorio(x);
                break;
            case 3:
                mostrar(x);
                break;
            default:
                out=1;
                break;
        }//fin de switch;
        if (out == 0) {
            cout << "\nDeseas salir del programa? (1/0)" << endl;
            cout << "1 <- si" << endl;
            cout << "0 <- no" << endl;
            cin >> out;
            if (entradaInvalida()) {
                out =0;
            }//fin if validacion
        }
    }while (out == 0);
}//fin manual

// ingresar matriz manualmente -------------------------------------------------
void manual (int x) {
    int n=1;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            while (true){
                cout << "ingresa el valor para el espacio ["<< i+1 <<"]["<< j+1 <<"]" << endl;
                cin >> matriz[i][j];
                if (entradaInvalida()) {
                    cout<<"ERROR. Debe ser numero \n"<<endl;
                    continue;
                }//fin if
                break;
            }//fin verificacion
            n++;
        }//fin for j
    }//fin for i

    //Para imprimir la matriz
    for (int i = 0; i < x; i++) {
        cout << "| ";
        for (int j = 0; j < x; j++) {
            cout << matriz[i][j] << " | ";
        }//fin for j
        cout << endl;
    }//fin for i
}//fin manual

void aleatorio (int x) {
    // Llenar la matriz con valores aleatorios
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            matriz[i][j] = rand() % 100 + 1; // valores entre 1 y 100
        }
    }

    // Mostrar la matriz
    for (int i = 0; i < x; i++) {
        cout << "| ";
        for (int j = 0; j < x; j++) {
            cout << matriz[i][j] << " | ";
        }
        cout << endl;
    }
}

void mostrar (int x) {
    for (int i = 0; i < x; i++) {
        cout << "| ";
        for (int j = 0; j < x; j++) {
            cout << matriz[i][j] << " | ";
        }//fin for j
        cout << endl;
    }// fin for i

}

//verifica que cin este bien----------------------------------------------------
bool entradaInvalida() {
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true; // Sí, la entrada es inválida
    }
    return false; // No, la entrada es correcta
}