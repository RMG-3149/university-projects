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
int tam, opcion, matriz[10][10];//tamaño de la matriz maxima [10][10]

//Declaracion de funciones------------------------------------------------------
void start ();
void RestAl(int x);
void manual (int x);
void aleatorio (int x);
void mostrar (int x);
void propiedades (int x);
bool reflexivo (int x);
bool simetrico (int x);
bool antisimetrico (int x);
bool transitiva (int x);
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
    int out=0;

    do {
        cout << "***Como deseas llenar la mastriz?***" << endl;
        <cout << "1 <- Llenar matriz de manera maunal" << endl;
        cout << "2 <- Llenar matriz de manera aleatoria" << endl;
        cout << "3 <- Mostrar matriz" << endl;
        cout << "4 <- Propiedades" << endl;
        cout << "Cualquier otro <- Salir" << endl;
        cin >> opcion;>

        if (opcion == 2 || opcion == 1) {
            do {
                while (true) {
                    cout << "Ingresa un rango de matriz (Minimo [3] Maximo [10])" << endl;
                    cin >> tam;//esta variable limita un rango de la matriz x*x

                    if (entradaInvalida()) {
                        cout<<"ERROR. Debe ser numero \n"<<endl;
                        continue;
                    }//fin if
                    break;
                }//fin verificacion

                if (tam > 10 || tam < 3) {
                    cout << "ERROR. Rango fuera de limite \n" << endl;
                }//fin if
            }while (tam > 10 || tam < 3);

            cout << "Tu Matriz sera de ["<< tam <<"]["<< tam <<"]" << endl;
            cout << "con " << tam*tam << " espacios\n" <<endl;
        }

        switch (opcion) {
            case 1:
                manual(tam);
                break;
            case 2:
                aleatorio(tam);
                break;
            case 3:
                mostrar(tam);
                break;
            case 4:
                propiedades(tam);
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
}//fin start

// ingresar matriz manualmente -------------------------------------------------
void manual (int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            while (true){
                cout << "Ingresa el valor (0 o 1) para el espacio ["<< i+1 <<"]["<< j+1 <<"]" << endl;
                cout << "Ingresa 8 en cualquier momento para llenar el resto aleatoriamente" << endl;
                cin >> matriz[i][j];

                if (entradaInvalida()) {
                    cout<<"ERROR. Debe ser numero\n"<<endl;
                    continue;
                }//fin verificacion

                if (matriz[i][j] == 8) {
                    // llenar el resto de la matriz aleatoriamente
                    for (int a = i; a < x; a++) {// a es para que se quede en la posicion donde se quedo i
                        for (int b = (a == i ? j : 0); b < x; b++) {//el "?" es un valor ternario si a == i es verdadero inicia en j si es falso inicia en 0 esta es de la ia no sabia como hacerla :(
                            matriz[a][b] = rand() % 2;
                        }//fin for b
                    }//fin for a
                    mostrar(x);
                    return; // salir de la función manual
                }//fin if

                if (matriz[i][j] != 0 && matriz[i][j] != 1) {
                    cout<<"ERROR. Solo se permite 0, 1 (u 8 para llenado aleatorio)\n"<<endl;
                    continue;
                }//fin if
                break;
            }//fin llenado
        }//fin for j
    }//fin for i
    mostrar(x);
}//fin manual

void aleatorio (int x) {
    // Llenar la matriz con valores aleatorios
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            matriz[i][j] = rand() % 2; // valores entre 0 y 1
        }//fin for j
    }//fin for i

    mostrar (x);
    // Mostrar la matriz 1
}

void mostrar (int x) {

        for (int i = 0; i < x; i++) {
            cout << "| ";
            for (int j = 0; j < x; j++) {
                cout << matriz[i][j] << " | ";
            }//fin for j
            cout << endl;
        }// fin for i
}//fin mostrar

void propiedades (int x) {
    cout << "Estas son las propiedades de tu matriz: " << endl;
    //para saber reflexividad
    if (reflexivo(x)) {
        cout << "Es Reflexiva" << endl;
    }else {
        cout << "no es Reflexiva" << endl;
    }//fin if

    //para saber simetria
    if (simetrico(x)) {
        cout << "Es Simetrica" << endl;
    }else {
        cout << "no es Simetrica" << endl;
    }//fin if

    //para saber antisimetria
    if (antisimetrico(x)) {
        cout << "Es Antisimetrico" << endl;
    }else {
        cout << "no es Antisimetrico" << endl;
    }//fin if

    //para saber transitibidad
    if (transitiva(x)) {
        cout << "Es Transitiva" << endl;
    }else {
        cout << "no es Transitiva" << endl;
    }//fin if

    if (reflexivo(x) && simetrico(x) && antisimetrico(x) && transitiva(x)) {
        //por si es ambas (ejemplo una matriz donde solo tiene la diagonal en 1 y el resto es 0)
        cout << "Es Equivalente y de Orden Parcial" << endl;
    }else if (reflexivo(x) && simetrico(x) && transitiva(x)) {
        //para decir que es de equivalencia
        cout << "\n***Es una matriz de Equivalencia***" << endl;
    }else if (reflexivo(x) && antisimetrico(x) && transitiva(x)) {
        //para decir que es de orden parcial
        cout << "\n***Es una matriz de Orden Parcial***" << endl;
    }else {
        //si no es nada saltara este mensaje
        cout << "No es ni de Orden parcial ni de equivalencia" << endl;
    }//fin if
}//fin propiedades

bool reflexivo (int x) {
    for (int i = 0; i < x; i++) {
        if (matriz[i][i] != 1) {
            return false; // Si la diagonal no es 1, no es reflexiva
        }//fin if
    }//fin for
    return true;//si ninguno es 0 sera reflexiva
}//fin refelxivo

bool simetrico (int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (matriz[i][j] != matriz[j][i]) {
                return false; // Si [i][j] y [j][i] no son iguales, no es simétrica
            }//fin if condicional
        }//fin for j
    }//fin for i
    return true; // si son iguales es verdadero
}//fin simetrico

bool antisimetrico (int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (i != j && matriz[i][j] == 1 && matriz[j][i] == 1) {
                return false; // Si hay simetria en elementos distintos, no es antisimetrica
            }//fin if condicional
        }//fin for j
    }//fin for i
    return true;
}//fin antisimetrico

bool transitiva (int x) {
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < x; j++) {
            if (matriz[i][j] == 1) { //si existe un 1 en un punto i, j, entra al siguiente for para buscar un j, k->
                for (int k = 0; k < x; k++) {
                    if (matriz[j][k] == 1 && matriz[i][k] != 1) {// lo evalua y si resulta que el valor resultante de esas matrces anteriores no existe ->
                        return false; // Se rompe la transitividad
                    }//fin if
                }//fin for k
            }//fin if de primera condicion
        }//fin for j
    }//fin for i
    return true;
}//fin transitividad

//verifica que cin este bien----------------------------------------------------
bool entradaInvalida() {
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true; // Sí, la entrada es inválida
    }
    return false; // No, la entrada es correcta
}