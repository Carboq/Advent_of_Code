#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "tabla_hash.h"
using namespace std;


void input(vector<int> &columna1, vector<int> &columna2) {
    ifstream file("input.txt"); // Abrir el archivo de entrada
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo 'input.txt'" << endl;
        return;
    }

    string line; // Almacena cada línea del archivo
    while (getline(file, line)) { // Lee línea por línea
        stringstream ss(line); // Utiliza stringstream para dividir la línea
        string col1, col2;

        // Extraer las dos columnas de cada línea
        if (ss >> col1 >> col2) { // Lee las columnas separadas por espacio
                columna1.push_back(stoi(col1));
                columna2.push_back(stoi(col2)); // Guarda en el segundo vector
        } else {
            cerr << "Error: Formato incorrecto en la línea: " << line << endl;
        }
    }
}


int calcularSimilitud(const vector<int>& listaIzquierda, const vector<int>& listaDerecha) {
    // Crear una tabla hash (unordered_map) para contar las ocurrencias en la lista derecha
    TablaHash tabla(1000);

    int similitudTotal = 0;
    // Recorremos la lista izquierda y calculamos la similitud
     for (int num : listaDerecha) {
        int aux = 0;
        if (tabla.buscar(num, aux)) {
            tabla.insertar(num, ++aux);
        } else {
            tabla.insertar(num, 1);
        }
    }

    for (int num : listaIzquierda) {
        int aux = 0;
        if (tabla.buscar(num, aux)) {
            similitudTotal += num * aux;
        }
    }

    return similitudTotal;
}

int main() {
    // Listas de ejemplo
    vector<int> listaIzquierda;
    vector<int> listaDerecha;
    input(listaIzquierda, listaDerecha);

    // Calculamos la similitud
    int similitud = calcularSimilitud(listaIzquierda, listaDerecha);

    // Mostramos el resultado
    cout << "La similitud entre las dos listas es: " << similitud << endl;

    return 0;
}
