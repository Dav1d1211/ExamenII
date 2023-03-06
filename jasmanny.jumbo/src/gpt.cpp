#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <chrono>
#include <thread>
using namespace std;

// Función para mostrar una barra de progreso
void show_progress(int percentage) {
    cout << "[";
    for (int i = 0; i < 50; i++) {
        if (i < percentage / 2) cout << "=";
        else cout << " ";
    }
    cout << "] " << percentage << "%" << endl;
}

// Función para verificar si una cadena es un número
bool is_number(const string& s) {
    return !s.empty() && all_of(s.begin(), s.end(), ::isdigit);
}

int main() {
    // Abrir el archivo de texto
    ifstream archivo("coordenadas.txt");
    if (!archivo) {
        cout << "Error al abrir el archivo." << endl;
        return 1;
    }

    // Vector para almacenar las coordenadas únicas
    vector<string> coordenadas;

    // Mostrar encabezado
    string encabezado;
    getline(archivo, encabezado);
    cout << encabezado << endl;

    // Leer cada línea del archivo
    string linea;
    int num_linea = 1;
    while (getline(archivo, linea)) {
        // Mostrar barra de progreso
        show_progress((num_linea * 100) / 11);
        // Incrementar número de línea
        num_linea++;
        // Separar la línea en campos
        string cap, geo, tipo_arsenal;
        size_t pos1 = 0, pos2 = 0;
        pos2 = linea.find(",");
        cap = linea.substr(pos1, pos2 - pos1);
        pos1 = pos2 + 1;
        pos2 = linea.find(",", pos1);
        geo = linea.substr(pos1, pos2 - pos1);
        pos1 = pos2 + 1;
        pos2 = linea.length();
        tipo_arsenal = linea.substr(pos1, pos2 - pos1);
        // Verificar si los campos son válidos
        bool es_valido = true;
        if (!is_number(cap) || !is_number(geo) || tipo_arsenal.length() != 7) {
            cout << "\033[1;31mError en la línea " << num_linea << ".\033[0m" << endl;
            es_valido = false;
        }
        // Verificar si la coordenada ya existe en el vector
        string coordenada = cap + "," + geo + "," + tipo_arsenal;
        bool es_repetida = (find(coordenadas.begin(), coordenadas.end(), coordenada) != coordenadas.end());
        // Si la coordenada es válida y no está repetida, agregarla al vector y mostrarla en verde
        if (es_valido && !es_repetida) {
            coordenadas.push_back(coordenada);
            cout << "\033[1;32m" << linea << "\033[0m" << endl;
        }
    }

    // Cerrar el archivo de texto
    archivo.close();

    return 0;
}