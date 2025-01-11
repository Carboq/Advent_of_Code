#include <iostream>
#include <list>
#include <vector>
#include <iterator>

using namespace std;


struct NodoHash{ 
    int llave;
    int valor;
    
    NodoHash(int l, int v){
        llave=l;
        valor=v;
    }
};

// Definimos la tabla hash con encadenamiento (usamos listas enlazadas)

class TablaHash {
    private:
        // Tamaño de la tabla hash
        int tamanyo;
    
        // Tabla hash (un array de listas enlazadas)
        vector<list<NodoHash>> tabla;
    
    // Función hash simple: toma el valor de la clave y hace un módulo con el tamaño de la tabla
    int ModuloTabla(int key) {
        return key % tamanyo; // Esto funciona bien para claves enteras
    }

public:
    // Constructor para inicializar la tabla
    TablaHash(int t_tabla) {
        tamanyo = t_tabla;
        tabla.resize((size_t)tamanyo);
    }

    // Inserción de un par clave-valor
    void insertar(int llave, int valor) {
        int index = ModuloTabla(llave);
        // Buscamos si la clave ya existe, si existe la actualizamos
        for (auto& node : tabla[(size_t)index]) {
            if (node.llave == llave) {
                node.valor = valor; // Actualizamos el valor
                return;
            }
        }
        // Si no existe, agregamos un nuevo nodo
        tabla[(size_t)index].push_back(NodoHash(llave, valor));
    }

    // Buscar un valor por su clave
    bool buscar(int llave, int& result) {
        int index = ModuloTabla(llave);
        for (auto& node : tabla[(size_t)index]) {
            if (node.llave == llave) {
                result = node.valor; 
                return true;
            }
        }
        return false; // No se encuentra la clave
    }

    // Eliminar una clave
    void remover(int llave) {
        int index = ModuloTabla(llave);
        tabla[(size_t)index].remove_if([llave](const NodoHash& node) {
            return node.llave == llave;
        });
    }

    // Mostrar tabla (útil para depuración)
    void printTable() {
        for (int i = 0; i < tamanyo; ++i) {
            cout << "Indice " << i << ": ";
            for (auto& node : tabla[(size_t)i]) {
                cout << "(" << node.llave << ", " << node.valor << ") ";
            }
            cout << endl;
        }
    }
};