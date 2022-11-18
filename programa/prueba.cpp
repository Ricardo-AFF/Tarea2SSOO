#include <pthread.h>
#include <iostream>
#include <stdlib.h> // atoi
#include <unistd.h> // sleep


// las hebras
void *sumatoria(void *param);
void *producto(void *param);

int main(int argc, char *argv[]) {
    // el identificador de la hebras
    pthread_t tid, tid2;

    // conjunto de atributos de la hebra
    pthread_attr_t attr;

    if (argc != 2) {
        std::cout << "uso: ./calculos <valor entero>\n";
        return -1;
    }

    if (atoi(argv[1]) <= 0) {
        std::cout << "numero debe ser > 0\n";
        return -1;
    }

  // obtener los atributos predeterminados
    pthread_attr_init (&attr);

  // crear las hebras
    pthread_create (&tid, &attr, sumatoria, argv[1]);
    pthread_create (&tid2, &attr, producto, argv[1]);

  // Para esperar a que la hebras (hijas) terminen.
    pthread_join (tid,NULL);
    pthread_join (tid2,NULL);

    std::cout << "Termina el padre ...\n";
}

// la hebra inicia su ejecución en esta función
void *sumatoria (void *param) {
    int i, upper = atoi((char*) param);
    int sum = 0;

    for (i=1; i<=upper; i++){
        sum += i;
        std::cout << " suma = " << sum << std::endl;
        // espera 1 segundo y luego continua.
        sleep (1);
    }

    pthread_exit(0);
}

// la hebra inicia su ejecución en esta función
void *producto (void *param) {
    int i, upper = atoi((char*) param);
    int prod = 1;

    for (i=1; i<=upper; i++){
        prod *= i;
        std::cout << " producto = " << prod << std::endl;
        // espera 1 segundo y luego continua.
        sleep(1);
    }

    pthread_exit (0);
}


//////////////////////7

/*
void *rutinaPing(void *arg){
    int nr_lineas=((int*)arg);
    int fileDescriptor;
    char buffer[] = "Nueva linea \n";

    printf("El hilo comienza a ejecutarse... \n");
    for(int i=0;i<nr_lineas;i++)
    {
        fileDescriptor = open("/home/rick/ssoo/TareaPing/Tarea2SSOO/programa/assets/listadoIp.txt", 0_WRONLY|0_APPEND);
        write(fileDescriptor, buffer, sizeof(buffer)-1);
        close(fileDescriptor);
    }
}


//int argc = numero de argumentos que paso por terminal de consola
//char *argc[] = vector que contiene los argumentos
*/



/*

    int variable = atoi(argv[1]);
    if(0 != pthread_create(&hebra, NULL, rutinaPing, &variable)){
        return -1;
    }
    pthread_join(hebra, NULL);
    return 0;

//Hebra
void hebraPing(){
    for(int i=0; i<10; i++)
    {
        std::cout << " INGRESO HEBRA PING \n";
    }
    std::cout << " INGRESO HEBRA PING \n";
}

//Main
int main()
{
    //Identificador de la hebra
    pthread_t threadId;

    //inicialización de la hebra
    std::thread hebra(hebraPing);
    return EXIT_SUCCESS;
}
*/