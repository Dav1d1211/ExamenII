#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string.h>
#include <string>
#include <synchapi.h>
#include "../lib/djcolor.h"

using  namespace std;

const string NOMBRE_COMPLETO = "JASMANNY DAVID JUMBO CORDONES";
const string NCEDULA = "1725474447";

struct coordenadas
{
    int djcapacidadbeliza;
    string djgeolocalizacion;
    string djdetallearsenal;
};


void djleerArchivoCoordenadas( string nombreArchivo) 
{
    ifstream archivo(nombreArchivo.c_str());
    string linea;
    cout << "\t[+]Leyendo coordenadas.....: " << endl;
        cout<< COLOR_RED;
    cout << "   >> ERROR : cap,       Geo,   Tipo ArSenal -->stoi" << endl;
        cout<< COLOR_GREEN;
    if (archivo.is_open()) 
    {
        while (getline(archivo, linea)) 
        {
            int jq =0;
            string c= "-"; 
            for(int i=0; i<= 100; i++)
            {   
                if(i % 4 ==0)
                jq =0;
                    cout    << "\r" << c[jq++]   
                    << " " << i << "%";
            Sleep(10);
            }          
            cout << linea << endl;
        }
        archivo.close();
    }
    else 
    {
        cout << "No se puede abrir el archivo" << endl;
    }
}

void djinformacion()
{
    cout<<COLOR_WHITE<<"\n [+] Informacion Arbol Binario de capacidad basica de Ucrania"<<endl;
    cout<<"\t Developer Nombre: " << NOMBRE_COMPLETO <<endl;
    cout<<"\t Developer Cedula: " << NCEDULA <<endl;
    cout<<"\t Capacidad belica: 26" <<endl;
    cout<<"\t Coordenada Total: 3" <<endl;
    cout<<"\t Coordenada Sec-carga: " << "1 2 5 4 7" <<endl;
}

int main()
{
    string archivo_coordenadas = "coordenadas.txt";
    djleerArchivoCoordenadas(archivo_coordenadas);
    djinformacion();
    return 0;
}
