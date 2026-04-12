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
using namespace std;

//---Variables------------------------------------------------------------------

//Declaracion de funciones de conversion----------------------------------------
int aDecimal(const string& numero, int base);
string decimalABinario(int n);
string decimalAOctal(int n);
string decimalAHex(int n);

//Declaracion de funciones de verificacion--------------------------------------
bool esBinario(const string& num);
bool esOctal(const string& num);
bool esDecimal(const string& num);
bool esHexadecimal(const string& num);

//main--------------------------------------------------------------------------
int main() {
    int opcion, dec, out=0;
    string num;

    do {
        cout << "***Menu de Opciones" << endl;
        cout << "1 <- Convertir Binario a..." << endl;
        cout << "2 <- Convertir Octal a..." << endl;
        cout << "3 <- Convertir Decimal a..." << endl;
        cout << "4 <- Convertir Hexadecimal a..." << endl;
        cout << "Cualquier otro <- salir" << endl;
        cin >> opcion;

        switch (opcion) {
            case 1:
                while (true) {
                    cout << "Ingrese un numero binario: ";
                    cin >> num;

                    if (!esBinario(num)) {
                        cout << "ERROR. Solo se permiten 0 y 1\n" << endl;
                        continue;
                    }//fin if
                    break;
                }//fin verificacion

            {
                dec = aDecimal(num, 2);
                cout << "Decimal: " << dec << endl;
                cout << "Octal: " << decimalAOctal(dec) << endl;
                cout << "Hexadecimal: " << decimalAHex(dec) << endl;
            }
                break;
            case 2:
                while (true) {
                    cout << "Ingrese un numero octal: ";
                    cin >> num;

                    if (!esOctal(num)) {
                        cout << "ERROR. Solo se permite un rango de 0 a 7\n" << endl;
                        continue;
                    }//fin if
                    break;
                }//fin verificacion
            {
                dec = aDecimal(num, 8);
                cout << "Decimal: " << dec << endl;
                cout << "Binario: " << decimalABinario(dec) << endl;
                cout << "Hexadecimal: " << decimalAHex(dec) << endl;
            }
                break;
            case 3:
                while (true) {
                    cout << "Ingrese un numero decimal: ";
                    cin >> num;

                    if (!esDecimal(num)) {
                        cout << "ERROR. Solo se permite un rango de 0 a 9\n" << endl;
                        continue;
                    }//fin if
                    break;
                }//fin verificacion
            {
                dec = aDecimal(num, 10);
                cout << "Binario: " << decimalABinario(dec) << endl;
                cout << "Octal: " << decimalAOctal(dec) << endl;
                cout << "Hexadecimal: " << decimalAHex(dec) << endl;
            }
                break;
            case 4:
                while (true) {
                cout << "Ingrese un numero hexadecimal: ";
                cin >> num;
                    if (!esHexadecimal(num)) {
                        cout << "ERROR. Solo se permite un rango de 0 a 9 y A a F\n" << endl;
                        continue;
                    }//fin if
                    break;
                }//fin verificacion
            {
                dec = aDecimal(num, 16);
                cout << "Decimal: " << dec << endl;
                cout << "Binario: " << decimalABinario(dec) << endl;
                cout << "Octal: " << decimalAOctal(dec) << endl;
            }
                break;
            default:
                cout << "Saliendo..." << endl;
                out=0;
                break;

        }
        if (out == 0) {
            cout << "\nDeseas salir del programa? (1/0)" << endl;
            cout << "1 <- si" << endl;
            cout << "0 <- no" << endl;
            cin >> out;
            if (out != 1 || out != 0) {
                cout << "Opcion no valida se saldra automaticamente" << endl;
                cout << "Saliendo..." << endl;
                out =0;
            }//fin if validacion
        }//fin if
    }while (out == 0);//fin do
}//fin main

//Declaracion de funciones de conversion----------------------------------------

// Convierte un número en cadena (binario, octal, hex) a decimal
int aDecimal(const string& num, int base) {
    int valor = 0;
    int potencia = 1;

    // Recorremos de derecha a izquierda
    for (int i = num.length() - 1; i >= 0; i--) {
        char c = num[i];
        int digito;

        if (c >= '0' && c <= '9') digito = c - '0';
        else if (c >= 'A' && c <= 'F') digito = 10 + (c - 'A');
        else if (c >= 'a' && c <= 'f') digito = 10 + (c - 'a');
        else digito = 0; // carácter inválido

        valor += digito * potencia;
        potencia *= base;
    }//fin for
    return valor;
}//fin aDecimal

// Convierte decimal a binario
string decimalABinario(int n) {
    if (n == 0) return "0";
    string resultado;
    while (n > 0) {
        resultado = char('0' + (n % 2)) + resultado;
        n = n / 2;
    }//fin while
    return resultado;
}//fin decimalABinario

// Convierte decimal a octal
string decimalAOctal(int n) {
    if (n == 0) return "0";
    string resultado;
    while (n > 0) {
        resultado = char('0' + (n % 8)) + resultado;
        n = n / 8;
    }//fin while
    return resultado;
}//fin decimalAOctal

// Convierte decimal a hexadecimal
string decimalAHex(int n) {
    if (n == 0) return "0";
    string resultado;
    const char * hexChars = "0123456789ABCDEF";
    while (n > 0) {
        resultado = string(1, hexChars[n % 16]) + resultado;

        n = n / 16;
    }//fin while
    return resultado;
}// fin decimalAHex

//Declaracion de funciones de verificacion--------------------------------------

// Verifica que la cadena sea binaria (solo 0 y 1)
bool esBinario(const string& num) {
    for (char c : num) {
        if (c != '0' && c != '1') return false;
    }//fin for
    return true;
}//fin verificacion binaria

// Verifica que la cadena sea octal (solo 0-7)
bool esOctal(const string& num) {
    for (char c : num) {
        if (c < '0' || c > '7') return false;
    }//fin for
    return true;
}//fin verificacion Octal

// Verifica que la cadena sea decimal (solo 0-9)
bool esDecimal(const string& num) {
    for (char c : num) {
        if (c < '0' || c > '9') return false;
    }//fin for
    return true;
}//fin verificacion decimal

// Verifica que la cadena sea hexadecimal (0-9, A-F, a-f)
bool esHexadecimal(const string& num) {
    for (char c : num) {
        if (!((c >= '0' && c <= '9') ||
              (c >= 'A' && c <= 'F') ||
              (c >= 'a' && c <= 'f'))) {
            return false;
        }//fin if
    }//fin for
    return true;
}//fin verificacion hexadecimal