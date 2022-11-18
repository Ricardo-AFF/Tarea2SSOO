#include <pthread.h>
#include <iostream>
#include <stdlib.h> // atoi
#include <unistd.h> // sleep
#include <fstream>
#include <string.h>
using namespace std;


int main(/*int argc, char *argv[]*/){
//    pthread_t hebra; //almacena el identificador de la hebra

    ifstream archivo;
    string texto;

    archivo.open("listadoIp.txt",ios::in);

    if (archivo.fail()){
        cout<<"No se pudo abrir el archivo";
        exit(1);
    }

    while(!archivo.eof()){ //mientras no acabe el archivo, hacer..
        getline(archivo,texto); // Copia lo del archivo en la variable texto
        cout<<texto<<endl;
    }

    archivo.close();
}

