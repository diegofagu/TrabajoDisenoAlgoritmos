#include <stdio.h>
#include <stdlib.h>

int main(void) {

    char nombreArchivo1[50];
    Lista L;

    printf("Nombre primer archivo: ");
    scanf("%s", &nombreArchivo1);
    L = leeArchivo(nombreArchivo1);
    printf("\nPromedio de Temperaturas: ");

    printf("\n\n");
    system("pause");
    printf("\n");
    return 0;
}

struct nodo {
    int info;
    struct nodo *sig;
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

Lista leeArchivo(char nombreArchivo[50]) {
    File *archivo;
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