/*
--------------------------------------------------------------------------------
NOMBRE: RAFAEL MARTINEZ JR

CODIGO: 221699977

FECHA: 02/03/2026

PROPOSITO: Conversion numerica de base
--------------------------------------------------------------------------------
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

//---Variables------------------------------------------------------------------

//Declaracion de funciones------------------------------------------------------
bool juego(const string& palabra);
bool letraYaIntentada(char letra, const char arr[], int n);
void mostrarAhorcado(int intentos);
void mostrarProg(const string& palabra, const char letrasAdivinadas[], int numAdivinadas);
bool entradaInvalida();
int salir(int out);
bool verificarLetra(char& letra);
bool verificarPalabra (const string& palabra);

//main--------------------------------------------------------------------------
int main() {
    srand(time(0));
    const string listapal[] = {"computadora", "programacion", "ahorcado", "matriz", "teclado"};
    int numpal = 5, out=0;

    do {
        cout << "***Juego del Ahorcado***" << endl;
        cout << "1 <- Jugar contra la computadora" << endl;
        cout << "2 <- Jugar contra otro usuario" << endl;
        cout << "Cualquier otro <- Salir" << endl;
        int opcion;
        cin >> opcion;

        string palabra;
        if (opcion == 1) {
            palabra = listapal[rand() % numpal];
        } else if (opcion == 2) {
            cout << "Usuario 1, ingresa la palabra secreta: ";
            cin >> palabra;

            if (!verificarPalabra(palabra)) {
                cout << "La palabra debe contener solo letras, sin numeros ni smbolos." << endl;
                continue; // vuelve al menú si es inválida
            }

            // Convertir a minúsculas
            for (size_t i = 0; i < palabra.size(); i++) {
                palabra[i] = tolower(palabra[i]);
            }
            cout << string(50, '\n'); // limpiar pantalla
        }
        else {
            out = 1;
        }//fin if

        juego(palabra);
        out = salir(out);
    }while (out == 0);
    return 0;
}
void mostrarProg(const string& palabra, const char letrasAdivinadas[], int numAdivinadas) {
    for (size_t i = 0; i < palabra.size(); i++) {
        bool encontrada = false;
        for (int j = 0; j < numAdivinadas; j++) {
            if (palabra[i] == letrasAdivinadas[j]) {
                encontrada = true;
                break;
            }//fin if
        }//fin for j
        if (encontrada) cout << palabra[i] << " ";
        else cout << "_ ";
    }//fin for i
    cout << endl;
}//fin mostrarProg

void mostrarAhorcado(int intentos) {
    const char* estados[] = {
        "  +---+\n      |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n      |\n      |\n     ===",
        "  +---+\n  O   |\n  |   |\n      |\n     ===",
        "  +---+\n  O   |\n /|   |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n      |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n /    |\n     ===",
        "  +---+\n  O   |\n /|\\  |\n / \\  |\n     ==="
    };
    cout << estados[intentos] << endl;
}//fin mostrarAhorcado

bool letraYaIntentada(char letra, const char arr[], int n) {//muestra las letras con las que te equivocaste
    for (int i = 0; i < n; i++) {
        if (arr[i] == letra) return true;
    }//fin for
    return false;
}//fin errores

bool juego(const string& palabra) {
    char letrasAdivinadas[50];
    char letrasErradas[50];
    int numAdivinadas = 0, numErradas = 0;
    int intentosFallidos = 0;
    const int MAX_INTENTOS = 6;

    while (intentosFallidos <= MAX_INTENTOS) {
        mostrarAhorcado(intentosFallidos);
        mostrarProg(palabra, letrasAdivinadas, numAdivinadas);

        cout << "Equivocaciones: ";
        for (int i = 0; i < numErradas; i++) cout << letrasErradas[i] << " ";
        cout << endl;

        char letra;
        cout << "Ingresa una letra: ";
        if (!verificarLetra(letra)) {
            continue; // vuelve al inicio del ciclo si la entrada no es válida
        }//fin if
        letra = tolower(letra);

        if (letraYaIntentada(letra, letrasAdivinadas, numAdivinadas) ||
            letraYaIntentada(letra, letrasErradas, numErradas)) {
            cout << "Ya intentaste esa letra." << endl;
            continue;
        }//fin if

        bool acierto = false;
        for (size_t i = 0; i < palabra.size(); i++) {
            if (palabra[i] == letra) {
                acierto = true;
                break;
            }//fin if
        }//fin for

        if (acierto) {
            letrasAdivinadas[numAdivinadas++] = letra;
        } else {
            letrasErradas[numErradas++] = letra;
            intentosFallidos++;
        }//fin if

        bool completa = true;
        for (size_t i = 0; i < palabra.size(); i++) {
            if (!letraYaIntentada(palabra[i], letrasAdivinadas, numAdivinadas)) {
                completa = false;
                break;
            }//fin if
        }//fin for

        if (completa) {
            cout << "Felicidades! Adivinaste la palabra: " << palabra << endl;
            return true;
        }//fin if
    }//fin while

    mostrarAhorcado(intentosFallidos);
    cout << "Has perdido. La palabra era: " << palabra << endl;
    return false;
}//fin juego

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

// Verifica que la entrada sea válida (una sola letra)
bool verificarLetra(char& letra) {
    if (!(cin >> letra)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Entrada inválida. Intenta de nuevo." << endl;
        return false;
    }//fin if
    letra = tolower(letra);
    if (!isalpha(letra)) {//isalpha funcion de cctype para verificafr que sean una letra del abcedario
        cout << "Debes ingresar solo letras." << endl;
        return false;
    }//fin if
    return true;
}//fin bool

bool verificarPalabra (const string& palabra) {
    for (char c : palabra) {
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))) {
            return false; // encontró un carácter inválido
        }//fin if
    }//fin for
    return true;
}//fin bool

