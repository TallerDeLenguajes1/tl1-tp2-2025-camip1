#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 5

struct compu{
    int velocidad; // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio; // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu; // Tipo de procesador (apuntador a cadena de caracteres)
}typedef compu;

void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);

int main(){
    compu PCs[5];
    srand(time(NULL)); // Inicializa la semilla para la generación de números aleatorios 
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    for(int i=0; i<5; i++){
        //PCs[i] = (compu*)malloc(sizeof(compu)); // Reserva memoria para cada PC
        PCs[i].velocidad = rand()%3 + 1; // Genera velocidad aleatoria entre 1 y 3 GHz
        PCs[i].anio = rand()%10 + 2015; // Genera año entre 2015 y 2024
        PCs[i].cantidad_nucleos = rand()%8 + 1; // Genera cantidad de núcleos entre 1 y 8
        PCs[i].tipo_cpu = tipos[rand()%6]; // Selecciona un tipo de CPU aleatorio
    }
    listarPCs(PCs,N); // Llama a la función para listar las PCs
    mostrarMasVieja(PCs,N); // Llama a la función para mostrar la PC más vieja
    return 0;
}


void listarPCs(struct compu pcs[], int cantidad){
    printf("\nListado de PCs:\n");
    for (int i = 0; i < cantidad; i++) {
        printf("\nPC %d:\n", i + 1);
        printf(" Velocidad: %d GHz\n Anio: %d\n Nucleos: %d\n Tipo CPU: %s\n", pcs[i].velocidad, pcs[i].anio, pcs[i].cantidad_nucleos, pcs[i].tipo_cpu);
    }
}

void mostrarMasVieja(struct compu pcs[], int cantidad){ 
    int anio_vieja = 2025;
    int indice;
    for (int i = 1; i < cantidad; i++) {
        if (pcs[i].anio < anio_vieja) {
            anio_vieja = pcs[i].anio;
            indice = i;
        }
    }
    printf("\nLa PC mas vieja es la %d del anio %d\n Velocidad: %d GHz\n Nucleos: %d\n Tipo CPU: %s\n", indice + 1, pcs[indice].anio, pcs[indice].velocidad, pcs[indice].cantidad_nucleos, pcs[indice].tipo_cpu);
}