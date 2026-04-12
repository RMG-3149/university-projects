/*
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Mostrar el estado actual de las torres
void mostrarTorres(vector<stack<int>> &torres) {
    cout << "\nEstado actual de las torres:\n";
    for (int i = 0; i < 3; i++) {
        cout << "Torre " << char('A' + i) << ": ";
        stack<int> copia = torres[i];
        vector<int> discos;
        while (!copia.empty()) {
            discos.push_back(copia.top());
            copia.pop();
        }
        for (int j = discos.size() - 1; j >= 0; j--) {
            cout << discos[j] << " ";
        }
        cout << endl;
    }
}

// Validar y ejecutar un movimiento
bool moverDisco(vector<stack<int>> &torres, int origen, int destino) {
    if (torres[origen].empty()) {
        cout << "La torre de origen está vacía.\n";
        return false;
    }
    if (!torres[destino].empty() && torres[origen].top() > torres[destino].top()) {
        cout << "Movimiento inválido: no puedes poner un disco grande sobre uno pequeño.\n";
        return false;
    }
    torres[destino].push(torres[origen].top());
    torres[origen].pop();
    return true;
}

int main() {
    int discos;
    cout << "Ingrese el número de discos: ";
    cin >> discos;

    // Inicializar torres
    vector<stack<int>> torres(3);
    for (int i = discos; i >= 1; i--) {
        torres[0].push(i);
    }

    mostrarTorres(torres);

    // Juego interactivo
    while (torres[2].size() != discos) {
        char o, d;
        cout << "\nMover de (A/B/C): ";
        cin >> o;
        cout << "Mover a (A/B/C): ";
        cin >> d;

        int origen = o - 'A';
        int destino = d - 'A';

        if (origen < 0 || origen > 2 || destino < 0 || destino > 2) {
            cout << "Entrada inválida.\n";
            continue;
        }

        moverDisco(torres, origen, destino);
        mostrarTorres(torres);
    }

    cout << "\n¡Felicidades! Has completado las Torres de Hanoi.\n";
    return 0;
}
*/
/*
#include <iostream>
using namespace std;

const int MAX = 10; // máximo de discos

// Cada torre será un arreglo y un contador de discos
int torreA[MAX], torreB[MAX], torreC[MAX];
int topeA, topeB, topeC;

// Inicializar torre A con n discos
void inicializar(int n) {
    topeA = n;
    topeB = 0;
    topeC = 0;
    for (int i = 0; i < n; i++) {
        torreA[i] = n - i; // disco más grande abajo
    }
}

// Mostrar estado actual
void mostrar() {
    cout << "\nA: ";
    for (int i = topeA - 1; i >= 0; i--) cout << torreA[i] << " ";
    cout << "\nB: ";
    for (int i = topeB - 1; i >= 0; i--) cout << torreB[i] << " ";
    cout << "\nC: ";
    for (int i = topeC - 1; i >= 0; i--) cout << torreC[i] << " ";
    cout << "\n";
}

// Función auxiliar para mover discos entre torres
bool mover(int &topeOrigen, int origen[], int &topeDestino, int destino[]) {
    if (topeOrigen == 0) {
        cout << "La torre de origen está vacía.\n";
        return false;
    }
    if (topeDestino > 0 && origen[topeOrigen - 1] > destino[topeDestino - 1]) {
        cout << "Movimiento inválido: no puedes poner un disco grande sobre uno pequeño.\n";
        return false;
    }
    destino[topeDestino] = origen[topeOrigen - 1];
    topeDestino++;
    topeOrigen--;
    return true;
}

// Juego interactivo
void jugar(int n) {
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

        if (o == 'A') { origen = torreA; topeOrigen = &topeA; }
        else if (o == 'B') { origen = torreB; topeOrigen = &topeB; }
        else { origen = torreC; topeOrigen = &topeC; }

        if (d == 'A') { destino = torreA; topeDestino = &topeA; }
        else if (d == 'B') { destino = torreB; topeDestino = &topeB; }
        else { destino = torreC; topeDestino = &topeC; }

        mover(*topeOrigen, origen, *topeDestino, destino);
        mostrar();
    }

    cout << "\n¡Felicidades! Has completado las Torres de Hanoi.\n";
}

int main() {
    int discos;
    cout << "Ingrese el número de discos (máx " << MAX << "): ";
    cin >> discos;
    jugar(discos);
    return 0;
}
*/
/*
#include <iostream>
using namespace std;

// Función recursiva para resolver las Torres de Hanoi
void hanoi(int n, char origen, char destino, char auxiliar) {
    // Caso base: si solo hay un disco, se mueve directamente
    if (n == 1) {
        cout << "Mover disco 1 de " << origen << " a " << destino << endl;
        return;
    }

    // Paso 1: mover n-1 discos de la torre origen a la torre auxiliar
    hanoi(n - 1, origen, auxiliar, destino);

    // Paso 2: mover el disco más grande al destino
    cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;

    // Paso 3: mover los n-1 discos del auxiliar al destino
    hanoi(n - 1, auxiliar, destino, origen);
}
*/

int main() {
    int discos;
    cout << "Ingrese el número de discos: ";
    cin >> discos;

    cout << "\nSecuencia de movimientos:\n";
    hanoi(discos, 'A', 'C', 'B'); // A = origen, C = destino, B = auxiliar

    return 0;
}
