#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_PAGES = 1000; // Número máximo de páginas para la implementación.

// Función para analizar la entrada y extraer reglas y actualizaciones.
void parseInput(vector<pair<int, int>>& rules, vector<vector<int>>& updates) {
    ifstream file("input.txt"); // Abre el archivo "input.txt".
    string line;
    bool readingRules = true; // Parametro para indicar si se están leyendo las reglas (true) o las actualizaciones (false).

    while (getline(file, line)) {
        if (line.empty()) { // Si se encuentra una línea vacía, cambia a leer actualizaciones.
            readingRules = false;
            continue;      // Intrucción para saltarse la linea en blanco.
        }
        if (readingRules) {
            int X, Y;
            replace(line.begin(), line.end(), '|', ' '); // Reemplaza '|' por espacios para facilitar el análisis.
            stringstream ruleStream(line);
            ruleStream >> X >> Y; // Extrae una regla (X -> Y).
            rules.push_back({X, Y}); // Añade la regla al vector de reglas.
        } else {
            vector<int> update;
            replace(line.begin(), line.end(), ',', ' '); // Reemplaza ',' por espacios.
            stringstream updateStream(line);
            int page;
            while (updateStream >> page) { // Lee páginas de la actualización.
                update.push_back(page);
            }
            updates.push_back(update); // Añade la actualización al vector de actualizaciones.
        }
    }
}

bool Orden(const vector<int>& paginas, const vector<pair<int, int>>& reglas) {
    vector<vector<int>> grafo(MAX_PAGES); // Representación del grafo: lista de adyacencias.
    vector<int> vertices(MAX_PAGES, 0);  // Arreglo para el grado de entrada de cada nodo.
    vector<bool> pag_presentes(MAX_PAGES, false); // Marca las páginas presentes en el conjunto dado.

    for (int pagina : paginas) {
        pag_presentes[(size_t)pagina] = true; // Marca las páginas relevantes.
    }

    // Construcción del grafo y cálculo del grado de entrada solo para las páginas relevantes.
    for (const auto& regla : reglas) {
        int X = regla.first, Y = regla.second;
        if (pag_presentes[(size_t)X] && pag_presentes[(size_t)Y]) {
            grafo[(size_t)X].push_back(Y); // Añade la arista X -> Y al grafo.
            vertices[(size_t)Y]++;        // Incrementa el grado de entrada del nodo Y.
        }
    }

    // Cola para realizar el ordenamiento topológico.
    queue<int> f;
    for (int pagina : paginas) {
        if (vertices[(size_t)pagina] == 0) { // Si el grado de entrada es 0, añade a la cola.
            f.push(pagina);
        }
    }

    vector<int> orden_topologico;
    while (!f.empty()) { // Algoritmo de ordenamiento topológico.
        int aux = f.front();
        f.pop();
        orden_topologico.push_back(aux); // Añade la página al orden topológico.
        for (int vecino : grafo[(size_t)aux]) {
            vertices[(size_t)vecino]--; // Disminuye el grado de entrada de los vecinos.
            if (vertices[(size_t)vecino] == 0) {
                f.push(vecino); // Añade vecinos con grado de entrada 0 a la cola.
            }
        }
    }

    // Comprueba si el orden topológico coincide con el orden de entrada de las páginas.
    return orden_topologico == paginas;
}

// Función para encontrar el elemento medio de un vector.
int mitad(const vector<int>& paginas) {
    return paginas[paginas.size() / 2]; // Devuelve el elemento central.
}

int main() {
    vector<pair<int, int>> reglas;      // Vector para almacenar las reglas (X -> Y).
    vector<vector<int>> paginas;       // Vector de vectores para las actualizaciones de páginas.
    parseInput(reglas, paginas);       // Llama a la función para procesar el archivo de entrada.

    int total = 0;                     // Acumulador para el resultado final.
    for (const auto& pag : paginas) {  // Itera sobre cada conjunto de páginas.
        if (Orden(pag, reglas)) {      // Comprueba si el orden es válido según las reglas.
            total += mitad(pag);       // Suma el elemento central si es válido.
        }
    }

    cout << total << endl; // Muestra el resultado final.
    return 0;
}
