#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

// Constantes para representar los movimientos en las 8 direcciones posibles.
const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1}; // Movimientos en filas.
const int dy[] = {1, -1, 0, 0, 1, -1, -1, 1}; // Movimientos en columnas.

// Función para leer la matriz desde un archivo.
void input(vector<string>& matriz) {
    ifstream file("input.txt"); // Abrir el archivo "input.txt".
    if (!file) { // Verificar si el archivo se abrió correctamente.
        cerr << "Error: No se pudo abrir el archivo 'input.txt'" << endl;
        return;
    }

    string line; // Variable para almacenar cada línea del archivo.
    while (getline(file, line)) { // Leer línea por línea.
        stringstream ss(line); // Crear un stringstream para procesar la línea.
        matriz.push_back(line); // Añadir la línea como una fila de la matriz.
    }
}

// Función para buscar si una palabra existe en una dirección específica desde una posición.
bool BuscarPalabra(const vector<string>& matriz, int x, int y, const string& palabra, int dir) {
    int n = (int)matriz.size(), m = (int)matriz[0].size(); // Dimensiones de la matriz.
    int lon = (int)palabra.size(); // Longitud de la palabra a buscar.

    for (int i = 0; i < lon; i++) { // Recorrer cada carácter de la palabra.
        int nx = x + (dx[dir] * i); // Calcular nueva posición en filas.
        int ny = y + (dy[dir] * i); // Calcular nueva posición en columnas.
        
        // Verificar que la nueva posición esté dentro de los límites de la matriz.
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            return false; // Si sale de los límites, la palabra no está presente.
        }
        
        // Comparar el carácter actual con el carácter correspondiente de la palabra.
        if (matriz[static_cast<size_t>(nx)][static_cast<size_t>(ny)] != palabra[static_cast<size_t>(i)]) {
            return false; // Si no coincide, la palabra no está en esta dirección.
        }
    }  
    return true; // Si se recorrió toda la palabra sin errores, está presente.
}

// Función para contar cuántas veces aparece una palabra en un área definida de la matriz.
int Contar(const vector<string>& matriz, const string& palabra, int x1, int y1, int x2, int y2) {
    int cont = 0; // Contador de apariciones de la palabra.
    
    // Recorrer cada posición en el área definida.
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            for (int dir = 0; dir < 8; dir++) { // Probar las 8 direcciones desde la posición actual.
                if (BuscarPalabra(matriz, i, j, palabra, dir)) { // Si se encuentra la palabra.
                    cont++; // Incrementar el contador.
                }
            }
        }
    }
    return cont; // Devolver el número total de apariciones.
}

// Función recursiva que implementa el algoritmo de Divide y Vencerás.
int DivideyVenceras(const vector<string>& matriz, const string& palabra, int x1, int y1, int x2, int y2) {
    int k = (int)palabra.size(); // Longitud de la palabra a buscar.

    // Caso base: si la submatriz es más pequeña o igual que la longitud de la palabra.
    if ((x2 - x1 + 1) <= k || (y2 - y1 + 1) <= k) {
        return Contar(matriz, palabra, x1, y1, x2, y2); // Usar la función de conteo directo.
    }

    // Calcular los puntos medios para dividir la matriz en 4 submatrices.
    int midX = (x1 + x2) / 2; // Punto medio de las filas.
    int midY = (y1 + y2) / 2; // Punto medio de las columnas.

    // Llamadas recursivas para las 4 submatrices.
    int topLeft = DivideyVenceras(matriz, palabra, x1, y1, midX, midY); // Submatriz superior izquierda.
    int topRight = DivideyVenceras(matriz, palabra, x1, midY+1, midX, y2); // Submatriz superior derecha.
    int bottomLeft = DivideyVenceras(matriz, palabra, midX+1, y1, x2, midY); // Submatriz inferior izquierda.
    int bottomRight = DivideyVenceras(matriz, palabra, midX+1, midY+1, x2, y2); // Submatriz inferior derecha.

    // Sumar los resultados de las submatrices y devolver el total.
    return topLeft + topRight + bottomLeft + bottomRight;
}

int main(){
    vector<string> matriz; // Matriz donde se buscará la palabra.
    input(matriz); // Llamada a la función para cargar la matriz desde el archivo.
    
    string palabra = "XMAS"; // Palabra a buscar.
    int n = (int)matriz.size(); // Número de filas de la matriz.
    int m = n > 0 ? (int)matriz[0].size() : 0; // Número de columnas de la matriz.

    cout << "La matriz es de " << n << "x" << m << endl; // Imprimir dimensiones de la matriz.

    // Llamada inicial a la función de Divide y Vencerás para buscar la palabra en toda la matriz.
    int result = DivideyVenceras(matriz, palabra, 0, 0, n - 1, m - 1);

    // Imprimir el resultado.
    cout << "La palabra " << palabra << " aparece " << result << " veces en la matriz." << endl;
}
