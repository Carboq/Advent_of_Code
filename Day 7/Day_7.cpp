#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
using namespace std;

//Declaracion de la clase TreeNode (arbol)
struct TreeNode {
    long long value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(long long val) : value(val), left(nullptr), right(nullptr) {}
};

//Funcion para pasar el input a 2 vectores, v1 en el que se guardan las soluciones a alcanzar y v2 donde se guardan los numeros a usar
void Input(vector<long long> &v1, vector<vector<int>> &v2) {
    ifstream file("input7.txt");
    string linea;
    while (getline(file, linea)) {
        stringstream iss(linea);
        string num;

        if (getline(iss, num, ':')) {
            v1.push_back(stoll(num));

            while (iss.peek() == ' ')
                iss.get();

            vector<int> tempVec;
            while (getline(iss, num, ' ')) {
                if (!num.empty()) {
                    tempVec.push_back(stoll(num));
                }
            }

            v2.push_back(tempVec);
        }
    }
    file.close();
}

//Para cada resultado, esta funcion genera un arbol con las posibles operaciones
bool buildTree(TreeNode* root, long long target, const vector<int>& v2, int index) {
    if (root->value == target) return true;
    if (index >= v2.size() || root->value > target) return false;

    // Crear hijos
    root->left = new TreeNode(root->value + v2[index]);
    root->right = new TreeNode(root->value * v2[index]);

    // Recursión sobre los hijos
    bool leftResult = buildTree(root->left, target, v2, index + 1);
    bool rightResult = buildTree(root->right, target, v2, index + 1);

    // Liberar memoria de nodos no utilizados
    if (!leftResult) delete root->left;
    if (!rightResult) delete root->right;

    return leftResult || rightResult;
}

//Funcion encargada de llamar a la funcion anterior para cada resultado a obtener
long long result(vector<long long> v1, vector<vector<int>> v2) {
    long long count = 0;
    for (int i = 0; i < v1.size(); i++) {
        TreeNode* root = new TreeNode(0);  // Nodo raíz con valor inicial 0
        if (buildTree(root, v1[i], v2[i], 0)) {
            count += v1[i];
        }
        delete root;  // Liberar memoria del árbol
    }
    return count;
}

int main() {
    vector<long long> v1;
    vector<vector<int>> v2;
    Input(v1, v2);

    long long total = 0;
    total = result(v1, v2);
    cout << total << endl;

    return 0;
}
