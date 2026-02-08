/*
--------------------------------------------------------------------------------
NOMBRE: RAFAEL MARTINEZ JR

CODIGO: 221699977

FECHA: 09/02/2026

PROPOSITO: ESTE PROGRAMA ES UN FIBONACCI
--------------------------------------------------------------------------------
*/

#include <iostream>
using namespace std;

//---Variables------------------------------------------------------------------
int T, t1= 0, t2= 1, nfijo=0;

void fibo ();// calcula los terminos
void verif ();// verifica que no halla un valor negativo

//---Main-----------------------------------------------------------------------
int main () {
	int opcion, cont=0;

    cout << "Bienvenido al Fibonacci" << endl;

	cout << "Cuantas terminos deseas en tu fibonacci" << endl;
	cin >> T;

    cout << "***Menu de eleccion***" << endl;
    cout << "1 <- While" << endl;
    cout << "2 <- Do-While" << endl;
    cout << "3 <- For" << endl;

	cin >> opcion;

	switch (opcion){
		case 1: {
			cout << "Estas usando la secuencia \"while\" \n" << endl;
			verif ();
			while (cont < T) {
				cout << t1 << ", ";
				fibo ();
				cont++;
			}
			break;

		}
		case 2: {
			cout << "Estas usando la secuencia \"do-while\" \n" << endl;
			verif ();
			do{
				cout << t1 << ", ";
				fibo ();
				cont++;
			} while(cont < T);
			break;
		}
		case 3: {
			cout << "Estas usando la secuencia \"For\" \n" << endl;
			verif ();
			for (int i = 1; i <= T; i++) {
				if(i == 1) { //muestra el primer termino
					cout << t1 << ", ";
					continue;
				}
				if(i == 2) { // muestra el segundo termino
					cout << t2 << ", ";
					continue;
				}
				fibo ();
				cout << nfijo << (i == T ? "" : ", ");
			}
			break;
		default: {
				cout << "Valor incorrecto" << endl;
				break;
			}
		}
	}
	return 0;
}//Fin main

//---Funciones------------------------------------------------------------------
void fibo () {
	nfijo = t1 + t2;
	t1 = t2;
	t2 = nfijo;
}

void verif () {
	int verif=0;
	if (verif<T) {
		cout << "No existe, Fibonacci de terminos negativos" << endl;
	}
}