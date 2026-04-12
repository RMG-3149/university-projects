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
int tam, opcion, modif=0;
double matriz1[10][10], matriz2[10][10], matriz3[10][10];//tamaño de la matriz maxima [10][10]

//Declaracion de funciones------------------------------------------------------
void start ();
void manual (int x);
void aleatorio (int x);
void pregunta ();
void mostrar (int x);
void operar (int x);
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
        cout << "***Menu de opciones***" << endl;
        cout << "1 <- Llenar matriz de manera maunal" << endl;
        cout << "2 <- Llenar matriz de manera aleatoria" << endl;
        cout << "3 <- Mostrar matriz" << endl;
        cout << "4 <- operar" << endl;
        cout << "Cualquier otro <- Salir" << endl;// x es cualquier caracter u otro numero
        cin >> opcion;

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
                pregunta();
                mostrar(tam);
                break;
            case 4:
                operar(tam);
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

    modif = 1;
    pregunta ();
    modif = 0;

    if (opcion == 1) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                while (true){
                    cout << "ingresa el valor para el espacio ["<< i+1 <<"]["<< j+1 <<"]" << endl;
                    cin >> matriz1[i][j];
                    if (entradaInvalida()) {
                        cout<<"ERROR. Debe ser numero \n"<<endl;
                        continue;
                    }//fin if
                    break;
                }//fin verificacion
            }//fin for j
        }//fin for i

        mostrar (x);
    }else if (opcion == 2) {
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                while (true){
                    cout << "ingresa el valor para el espacio ["<< i+1 <<"]["<< j+1 <<"]" << endl;
                    cin >> matriz2[i][j];
                    if (entradaInvalida()) {
                        cout<<"ERROR. Debe ser numero \n"<<endl;
                        continue;
                    }//fin if
                    break;
                }//fin verificacion
            }//fin for j
        }//fin for i

        mostrar (x);
    }else {
        cout << "ERROR. Opcion invalida \n" << endl;
    }//fin if de opcion
}//fin manual

void aleatorio (int x) {
    modif = 1;
    pregunta ();
    modif = 0;

    if (opcion == 1) {
        // Llenar la matriz con valores aleatorios
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                matriz1[i][j] = rand() % 100 + 1; // valores entre 1 y 100
            }//fin for j
        }//fin for i

        mostrar (x);
        // Mostrar la matriz 1
    } else if (opcion == 2) {
        // Llenar la matriz con valores aleatorios
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < x; j++) {
                matriz2[i][j] = rand() % 100 + 1; // valores entre 1 y 100
            }//fin for j
        }//fin for i
        mostrar (x);
    }else {
        cout << "ERROR. Opcion invalida \n" << endl;
    }//fin if de opcion
}//fin aleatorio

void pregunta () {
    while (true) {
        if (modif==1) {
            cout << "***Que matriz deseas modificar***" << endl;
        } else {
            cout << "***Que matriz deseas mostrar***" << endl;
        }
        cout << "1 <- Matriz 1" << endl;
        cout << "2 <- matriz 2" << endl;
        cin >> opcion;
        if (entradaInvalida()) {
            cout<<"ERROR. Debe ser numero \n"<<endl;
            continue;
        }//fin if
        break;
    }//fin verificacion


}//fin pregunta

void mostrar (int x) {

    if (opcion == 1) {
        for (int i = 0; i < x; i++) {
            cout << "| ";
            for (int j = 0; j < x; j++) {
                cout << matriz1[i][j] << " | ";
            }//fin for j
            cout << endl;
        }// fin for i
    }else if (opcion == 2) {
        for (int i = 0; i < x; i++) {
            cout << "| ";
            for (int j = 0; j < x; j++) {
                cout << matriz2[i][j] << " | ";
            }//fin for j
            cout << endl;
        }// fin for i
    }else if (opcion == 3) {
        for (int i = 0; i < x; i++) {
            cout << "| ";
            for (int j = 0; j < x; j++) {
                cout << matriz3[i][j] << " | ";
            }//fin for j
            cout << endl;
        }// fin for i
    }else{
        cout << "ERROR. Opcion invalida \n" << endl;
    }//fin if de opcion
}//fin mostrar

void operar (int x) {
    double div;

    while (true) {
        cout << "***Que operacion deseas realizar***" << endl;
        cout << "1 <- Suma" << endl;
        cout << "2 <- Resta" << endl;
        cout << "3 <- Multiplicacion" << endl;
        cout << "4 <- Division" << endl;
        cin >> opcion;
        if (entradaInvalida()) {
            cout<<"ERROR. Debe ser numero \n"<<endl;
            continue;
        }//fin if
        break;
    }

    switch (opcion) {
        case 1:
            opcion = 3;
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < x; j++) {
                    matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
                }//fin for j
            }//fin for i

            //mostrar matriz
            opcion = 3;
            mostrar(x);
            break;

        case 2:
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < x; j++) {
                    matriz3[i][j] = matriz1[i][j] - matriz2[i][j];
                }//fin for j
            }//fin for i

            //mostrar matriz 3
            opcion = 3;
            mostrar(x);
            break;

        case 3:
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < x; j++) {
                    matriz3[i][j] = matriz1[i][j] * matriz2[i][j];
                }//fin for j
            }//fin for i

            //mostrar matriz 3
            opcion = 3;
            mostrar(x);
            break;

        case 4:
            pregunta();

            while (true) {
                cout << "entre que numero" << endl;
                cin >> div;

                if (entradaInvalida()) {
                    cout<<"ERROR. Debe ser numero \n"<<endl;
                    continue;
                }//fin if
                break;
            }//fin verificacion

            if (opcion == 1) {
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < x; j++) {
                        matriz3[i][j] = matriz1[i][j] / div;
                    }
                }
            }else if (opcion == 2) {
                for (int i = 0; i < x; i++) {
                    for (int j = 0; j < x; j++) {
                        matriz3[i][j] = matriz2[i][j] / div;
                    }
                }
            } else {
                cout << "ERROR. Opcion invalida \n" << endl;
            }

            //mostrar matriz
            opcion = 3;
            mostrar(x);

            break;
        default:
            cout << "ERROR. Opcion invalida \n" << endl;
            break;
    }//fin switch
}//fin operar

//verifica que cin este bien----------------------------------------------------
bool entradaInvalida() {
    if (cin.fail()){
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return true; // Sí, la entrada es inválida
    }
    return false; // No, la entrada es correcta
}






