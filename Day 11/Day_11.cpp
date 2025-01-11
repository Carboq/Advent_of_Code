#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

//Función para pasar los datos del input a un vector 
void Input(vector<long long> &v1)
{
    ifstream file("input11.txt");
    string linea;

    if (getline(file, linea)) {
        stringstream iss(linea);
        long long num;
        while (iss >> num) {
            v1.push_back(num);
        }
    }
    file.close();
}

//Función implementada con programación dinámica mediante una variable de memoria y recursividad
int predicciones(long long numero, int blinks, unordered_map<string, int> &memoria) {
    if (blinks == 0) return 1; // Caso base: no quedan mas blinks por hacer

    stringstream ss;
    ss << numero << ":" << blinks;  
    string key = ss.str();

    if (memoria.find(key) != memoria.end()) return memoria[key]; //Si ya está calculado, lo devuelve

    int resultado = 0;

    if (numero == 0) {
        resultado = predicciones(1, blinks - 1, memoria);  // 0 pasa a ser 1
    } else {
        string numStr = to_string(numero);
        if (numStr.size() % 2 == 0) { //Divide el numero en dos partes y cada parte llama a la funcion otra vez
            resultado = predicciones(stoi(numStr.substr(0, numStr.size() / 2)), blinks - 1, memoria) + 
                     predicciones(stoi(numStr.substr(numStr.size() / 2)), blinks - 1, memoria);
        } else {
            // Impares: Multiplica por 2024
            resultado = predicciones(numero * 2024, blinks - 1, memoria);
        }
    }

    memoria[key] = resultado; 
    return resultado;
}

int main() {
    vector<long long> registro;
    Input(registro);
    int num = registro.size();
    int blinks = 25; 
    unordered_map<string, int> memoria;

    int total = 0;

    for (int i = 0; i < num; i++) {
        total += predicciones(registro[i], blinks, memoria);
    }

    cout << "Total de piedras tras " << blinks << " blinks: " << total << endl;

    return 0;
}
