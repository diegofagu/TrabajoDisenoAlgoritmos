#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct nodo {
    int info;
    struct nodo *sig; // Puntero al siguiente nodo
};

typedef struct nodo tNodo;
typedef tNodo *Lista;

Lista creaNodo(int dato) {
    Lista p;

    p= malloc(sizeof(tNodo));
    if(p==NULL) {
        printf("No hay memoria suficiente. Este programa se cerrar%c.",160);
        exit(0);
    }
    p->info=dato;
    p->sig=NULL;
    return p;
}

Lista insertaFinal(Lista L, int dato) {
    Lista nuevo = creaNodo(dato);
    if (L == NULL) {
        return nuevo;
    }

    Lista aux = L;
    while (aux->sig != NULL) {
        aux = aux->sig;
    }
    aux->sig = nuevo;
    return L;
}

Lista leeArchivo(char nombreArchivo[50]) {
    FILE *archivo;
    Lista L;
    int dato;

    L=NULL;
    archivo=fopen(nombreArchivo,"r");
    if(archivo==NULL) {
        printf("No se puede abrir el archivo. Revisa su ubicaci%cn",163);
        exit(0);
    }

    while(feof(archivo) == false) {
        fscanf(archivo,"%i\n",&dato);
        L= insertaFinal(L,dato);
    }
    fclose(archivo);
    return L;
}



int promedio(Lista L){
    Lista aux = L;
    int suma ,contador;
    suma = 0;
    contador = 0;
    while(aux != NULL) {
        suma += aux->info;
        contador++;
        aux = aux->sig;
    }
    int valorPromedio = suma / contador;
    return valorPromedio;
}

void imprimeLista(Lista L) {
    Lista aux = L;
    while (aux != NULL) {
        printf("%d ", aux->info);
        aux = aux->sig;
    }
    printf("\n");
}

int main() {

    char nombreArchivo1[50];
    Lista L;
    int promedioTemperaturas;

    printf("Nombre primer archivo: ");
    scanf("%s", &nombreArchivo1);
    L = leeArchivo(nombreArchivo1);
    printf("datos del archivo: \n");
    imprimeLista(L);

    promedioTemperaturas = promedio(L);
    printf("\nPromedio de Temperaturas: \n");
    printf("%d grados\n", promedioTemperaturas);
    printf("\n\n");
    system("pause");
    printf("\n");
    return 0;
}

