#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>

using namespace std;

const int dx[] = {0, 0, 1, -1, 1, -1, 1, -1};
const int dy[] = {1, -1, 0, 0, 1, -1, -1, 1};

void input(vector<string>& matriz) {
    ifstream file("input.txt"); // Abrir el archivo de entrada
    if (!file) {
        cerr << "Error: No se pudo abrir el archivo 'input.txt'" << endl;
        return;
    }

    string line; // Almacena cada línea del archivo
    while (getline(file, line)) { // Lee línea por línea
        stringstream ss(line); // Utiliza stringstream para dividir la línea
                matriz.push_back(line);
    }
}

bool BuscarPalabra(const vector<string>& matriz, int x, int y, const string& palabra, int dir) {
    int n = (int)matriz.size(), m = (int)matriz[0].size(); //n = filas, m = columnas
    int lon = (int)palabra.size();
    for (int i = 0; i < lon; i++) {
        int nx = x + (dx[dir] * i);
        int ny = y + (dy[dir] * i);
        // Verificar si nx y ny están dentro de los límites antes de acceder a la matriz
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
            return false;
        }
        if (matriz[static_cast<size_t>(nx)][static_cast<size_t>(ny)] != palabra[static_cast<size_t>(i)]) {
            return false;
        }
    }  
    return true;
}

int Contar(const vector<string>& matriz, const string& palabra, int x1, int y1, int x2, int y2) {
    int cont = 0;;
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            for (int dir = 0; dir < 8; dir++) {
                if (BuscarPalabra(matriz, i, j, palabra, dir)) {
                    cont++;
                }
            }
        }
    }
    return cont;
}
int DivideyVenceras(const vector<string>& matriz, const string& palabra, int x1, int y1, int x2, int y2) {
    int k =(int) palabra.size();

    // Caso base: si la submatriz es pequeña
    if ((x2 - x1 + 1) <= k || (y2 - y1 + 1) <= k) {
        return Contar(matriz, palabra, x1, y1, x2, y2);
    }
    // Dividimos la matriz en 4 submatrices
    int midX = (x1 + x2) / 2;
    int midY = (y1 + y2) / 2;
    // Consideramos bordes superpuestos de longitud k-1
    int topLeft = DivideyVenceras(matriz, palabra, x1, y1, midX, midY);
    int topRight = DivideyVenceras(matriz, palabra, x1, midY+1,midX, y2);
    int bottomLeft = DivideyVenceras(matriz, palabra, midX+1, y1, x2, midY);
    int bottomRight = DivideyVenceras(matriz, palabra, midX+1, midY+1, x2, y2);

    return topLeft + topRight + bottomLeft + bottomRight;
}
int main(){
    vector<string> matriz;
    input(matriz);
    string palabra = "XMAS";
    int n = (int) matriz.size();
    int m = n > 0 ? (int) matriz[0].size() : 0;
    cout << "La matriz es de " << n << "x" << m << endl;
    int result = DivideyVenceras(matriz, palabra, 0, 0, n - 1, m - 1);
    cout << "La palabra " << palabra << " aparece " << result << " veces en la matriz." << endl;
}
