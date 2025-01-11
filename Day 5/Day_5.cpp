#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX_PAGES = 1000; // Maximum number of pages for array-based implementation

// Function to parse input and extract rules and updates
void parseInput(vector<pair<int, int>>& rules, vector<vector<int>>& updates) {
    ifstream file("input.txt");
    string line;
    bool readingRules = true;

    while (getline(file, line)) {
        if (line.empty()) {
            readingRules = false;
            continue;
        }
        if (readingRules) {
            int X, Y;
            replace(line.begin(), line.end(), '|', ' ');
            stringstream ruleStream(line);
            ruleStream >> X >> Y;
            rules.push_back({X, Y});
        } else {
            vector<int> update;
            replace(line.begin(), line.end(), ',', ' ');
            stringstream updateStream(line);
            int page;
            while (updateStream >> page) {
                update.push_back(page);
            }
            updates.push_back(update);
        }
    }
}


bool Orden(const vector<int>& paginas, const vector<pair<int, int>>& reglas) {
    vector<vector<int>> grafo(MAX_PAGES);
    vector<int> vertices(MAX_PAGES, 0);   
    vector<bool> pag_presentes(MAX_PAGES, false);

    
    for (int pagina : paginas) {
        pag_presentes[(size_t)pagina] = true;
    }

    // Build graph and in-degree array only for relevant pages
    for (const auto& regla : reglas) {
        int X = regla.first, Y = regla.second;
        if (pag_presentes[(size_t)X] && pag_presentes[(size_t)Y]) {
            grafo[(size_t)X].push_back(Y); // Add edge X -> Y
            vertices[(size_t)Y]++;
        }
    }

    // Topological sort using Kahn's algorithm
    queue<int> f;
    for (int pagina : paginas) {
        if (vertices[(size_t)pagina] == 0) {
            f.push(pagina);
        }
    }

    vector<int> orden_topologico;
    while (!f.empty()) {
        int aux = f.front();
        f.pop();
        orden_topologico.push_back(aux);
        for (int vecino : grafo[(size_t)aux]) {
            vertices[(size_t)vecino]--;
            if (vertices[(size_t)vecino] == 0) {
                f.push(vecino);
            }
        }
    }

    // Check if the topological order matches the input order
    return orden_topologico == paginas;
}

// Function to find the middle element of a vector
int mitad(const vector<int>& paginas) {
    return paginas[paginas.size() / 2];
}

int main() {
    
    vector<pair<int, int>> reglas;
    vector<vector<int>> paginas;
    parseInput(reglas, paginas);

    int total = 0;
    for (const auto& pag : paginas) {
        if (Orden(pag, reglas)) {
            total += mitad(pag);
        }
    }

    cout << total << endl; // Expected output: 143
    return 0;
}
