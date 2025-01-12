#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "tabla_hash.h" // Implementación de la tabla hash
using namespace std;

// Función para leer datos de un archivo de entrada y almacenar en dos vectores
void input(vector<int> &columna1, vector<int> &columna2) {
    ifstream file("input.txt"); // Abrir el archivo "input.txt" en modo lectura
    if (!file) { // Verificar si el archivo no pudo abrirse
        cerr << "Error: No se pudo abrir el archivo 'input.txt'" << endl;
        return;
    }

    string line; // Variable para almacenar cada línea del archivo
    while (getline(file, line)) { // Lee cada línea del archivo
        stringstream ss(line); // Crear un stringstream para procesar la línea
        string col1, col2; // Variables para almacenar las dos columnas de cada línea

        // Extraer las dos columnas y convertirlas en enteros
        if (ss >> col1 >> col2) { // Si la línea tiene dos valores separados por espacio
            columna1.push_back(stoi(col1)); // Agrega el primer valor al vector columna1
            columna2.push_back(stoi(col2)); // Agrega el segundo valor al vector columna2
        } else { // Si la línea tiene un formato incorrecto
            cerr << "Error: Formato incorrecto en la línea: " << line << endl;
        }
    }
}

// Función para calcular la similitud entre dos listas de enteros
int calcularSimilitud(const vector<int>& listaIzquierda, const vector<int>& listaDerecha) {
    // Crear una tabla hash para contar las ocurrencias en la lista derecha
    TablaHash tabla(1000); // Tamaño inicial de la tabla hash: 1000

    int similitudTotal = 0; // Inicializar la similitud total en 0

    // Recorrer la lista derecha y almacenar las ocurrencias en la tabla hash
    for (int num : listaDerecha) { 
        int aux = 0; // Almacena el valor actual asociado al número en la tabla hash
        if (tabla.buscar(num, aux)) { // Si el número ya existe en la tabla hash
            tabla.insertar(num, ++aux); // Incrementar su contador y actualizarlo en la tabla
        } else { // Si el número no existe en la tabla hash
            tabla.insertar(num, 1); // Insertar el número con un contador inicial de 1
        }
    }

    // Recorrer la lista izquierda para calcular la similitud con la lista derecha
    for (int num : listaIzquierda) { 
        int aux = 0; // Almacena el valor actual asociado al número en la tabla hash
        if (tabla.buscar(num, aux)) { // Si el número existe en la tabla hash
            similitudTotal += num * aux; // Agregar el producto del número y su contador a la similitud total
        }
    }

    return similitudTotal; // Retornar la similitud calculada
}

int main() {
    // Declarar vectores para almacenar las listas leídas del archivo
    vector<int> listaIzquierda;
    vector<int> listaDerecha;

    // Llamar a la función input para leer las listas desde el archivo
    input(listaIzquierda, listaDerecha);

    // Calcular la similitud entre las dos listas
    int similitud = calcularSimilitud(listaIzquierda, listaDerecha);

    // Mostrar el resultado de la similitud
    cout << "La similitud entre las dos listas es: " << similitud << endl;

    return 0; // Indicar que el programa terminó correctamente
}
