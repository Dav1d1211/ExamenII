#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fstream>
using namespace std;

void escribir()
{
    ofstream archivo;
    string texto;

    archivo.open("C:\\Users\\LabP3411\\Documents\\Examen2\\src\\Ciudades.txt", ios::out);

    if (archivo.fail())
    {
        cout<<"No se puede crear el archivo .txt";
        exit(1);
    }
    cout<<"digite el texto que desea ingresar: ";
    getline(cin, texto);

    archivo<<texto;
    archivo.close();
}
void lectura()
{
    ifstream archivo;
    string texto;

    archivo.open("c:\\Examen\\Ciudades.txt", ios::in);

    if (archivo.fail())
    {
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

        while (!archivo.eof())
        {
            getline(archivo, texto);
            cout<<texto<<endl;
        }
        
        archivo.close();
    
    
}
void aniadir()
{
    ofstream archivo;
    string texto;

    archivo.open("C:\\Users\\LabP3411\\Documents\\Examen2\\src\\Ciudades.txt", ios::app);
    if (archivo.fail())
    {
        cout<<"No se Pudo escribir en el archivo";
        exit(1);
    }

    cout<<"Digite el texto que desea ingresar: ";
    getline(cin, texto);

    archivo<<texto<<endl;

    archivo.close();
}

int main ()
{
    //lectura ();
    //escribir();
    aniadir();
    system ("pause");
    return 0;
}