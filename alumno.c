#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"



Alumno crearAlumno(int dniN, char nombreN[60], int esAll) {

    Alumno alumno = malloc(sizeof(struct EstructuraAlumno));
    alumno->dni = dniN;
    alumno->esAlumno = esAll;
    int len = strlen(nombreN);
    if (len > 0 && nombreN[len-1] == '\n') nombreN[len-1] = '\0';
    strcpy(alumno->nombre, nombreN);

    return alumno;

}

void mostrarAlumno(Alumno p) {
    printf("\n\n%d --- %s", p->dni, p->nombre);
}


int getDni(Alumno p){
    return p->dni;
}

char *getNombre(Alumno p){
    return p->nombre;
}

int getEsAlumno(Alumno p) {
    return p->esAlumno;
}

void setDni(Alumno p, int nuevoDNI){
    p->dni = nuevoDNI;
}

void setNombre(Alumno p, char nuevoNombre[20]){
    strcpy(p->nombre, nuevoNombre);
}

void setEsAlumno(Alumno p, int n) {
    p->esAlumno = n; 
}

void destruirAlumno(Alumno p){
    free(p);
}

// 
// ARCHIVOS
//

int regAlumno(int dniN, char nombreN[60],int materia, int esAll) {

    // Retorna 1 si se escribió el alumno satisfactoriamente.

    FILE * salida;
    salida = fopen("bbdd.txt", "a");
    int m = fprintf(salida, "\n%s,%d,%d,%d", nombreN, dniN, materia, esAll);
    fclose(salida);

    if (m > 0) {
        return 1;
    }

    else {
        return 0;
    }

}

void mostrarAlumnosPorMateria(int materia) {

    // Va a mostrar todos los alumnos registrados en una materia dada.

    FILE *archivo2;
	char caracter;
    char arche[9000];
    int i = 0;
	
	archivo2 = fopen("bbdd.txt","r");
	
	if (archivo2 == NULL) {
        printf("\nError de apertura del archivo. \n\n");
    }
    else {
        while((caracter = fgetc(archivo2)) != EOF) {
            arche[i] = caracter;
            i++;
        }
    }

    fclose(archivo2);

    // A partir de acá cargo los alumnos por materia DESDE el vector.

    char nomAlu[60];
    char dniAlu[12];
    char codMat[3];
    char esAlu[2];
    int c = 0; // contador
    int k = 0; // otro contador para almacenar el nombre
    int cambiar = 0;
    // printf("---------\n");
    while (c < i) {

        // printf("%c", arche[c]);

        if (arche[c] == '\n' || arche[c] == '\0' || c+1 == i) {
            // printf("___%d___", atoi(codMat));
            // printf("___%d___", atoi(codMat));
            if (materia == atoi(codMat)) {
                printf("%s", nomAlu);
                // printf("\n%s", dniAlu);
                // printf("\n%s", codMat);
                // printf("\n%d\n", atoi(esAlu));
            }
            k = 0;
            cambiar = 0;
            memset(nomAlu, 0, 60);
            memset(dniAlu, 0, 12);
            memset(codMat, 0, 3);
            memset(esAlu, 0, 2);
            strcpy(dniAlu, "");
            strcpy(codMat, "");
        }  

        if (arche[c] == ',') {
            cambiar++;
            k = 0;
            c++;
            continue;
        }

        if (cambiar == 0) {
            nomAlu[k] = arche[c];
            k++;
        }

        if (cambiar == 1) {
            dniAlu[k] = arche[c];
            k++;
        }

        if (cambiar == 2) { 
            codMat[k] = arche[c];
            k++;
        }

        if (cambiar == 3) { 
            esAlu[0] = arche[c];
        }

        // if (c+1 == i) {
        //     printf("___%d___%d____", i, c);
        //     if (materia == atoi(codMat)) {
        //         printf("\n%sbbb", nomAlu);
        //         printf("\n%s", dniAlu);
        //         printf("\n%s", codMat);
        //         printf("\n%c\n", esAlu);
        //     }
        // }   

        c++;
    }
    // printf("___%d___%d____", i, c);
    // printf("\n---------\n");


    
}

int * mostrarMateriasPorAlumno(int dni) {

    // Esta función va a retornar un vector en donde van a estar almacenados
    // los codigos de materias del alumno que se solicita.

    FILE *archivo2;
	char caracter;
    char arche[9000];
    int i = 0;
	
	archivo2 = fopen("bbdd.txt","r");
	
	if (archivo2 == NULL) {
        printf("\nError de apertura del archivo. \n\n");
    }
    else {
        while((caracter = fgetc(archivo2)) != EOF) {
            arche[i] = caracter;
            i++;
        }
    }

    fclose(archivo2);

    // A partir de acá cargo los alumnos por materia DESDE el vector.

    static int codMaterias[20]; // --- Vector de retorno!!!

    for (int h = 0; h < 20 ; h++) {
        codMaterias[h] = -1;
    }

    int codIndex = 0;

    char nomAlu[60];
    char dniAlu[12];
    char codMat[3];
    char esAlu[2];
    int c = 0; // contador
    int k = 0; // otro contador para almacenar el nombre
    int cambiar = 0;

    while (c < i) {

        if (arche[c] == '\n' || arche[c] == '\0' || c+1 == i) {

            if (dni == atoi(dniAlu)) {
                // printf("%s\n", codMat);
                if (strlen(nomAlu) > 10) {
                    codMaterias[codIndex] = atoi(codMat);
                }
                else {
                    printf("asdasd");
                    codMaterias[codIndex] = 99;
                }
                codIndex++;
            }

            k = 0;
            cambiar = 0;
            memset(nomAlu, 0, 60);
            memset(dniAlu, 0, 12);
            memset(codMat, 0, 3);
            memset(esAlu, 0, 2);
            strcpy(dniAlu, "");
            strcpy(codMat, "");
        }  

        if (arche[c] == ',') {
            cambiar++;
            k = 0;
            c++;
            continue;
        }

        if (cambiar == 0) {
            nomAlu[k] = arche[c];
            k++;
        }

        if (cambiar == 1) {
            dniAlu[k] = arche[c];
            k++;
        }

        if (cambiar == 2) { 
            codMat[k] = arche[c];
            k++;
        }

        if (cambiar == 3) { 
            esAlu[0] = arche[c];
        }

        c++;
    }

    // Ordeno el vector

    int ce, j, aux, n = 20;

    for (ce = 0; ce <= n; ce++) {

        for (j = 0; j < n-1; j++){

            if (codMaterias[j] > codMaterias[j+1]) {
                aux = codMaterias[j];
                codMaterias[j] = codMaterias[j+1];
                codMaterias[j+1] = aux;
            }
         
      }

   }
    

    return codMaterias;
    
}

int eliminarAlumnoEnMateria(int materia, int dni) {

    // Va a eliminar un alumno dada una materia y dado un dni.

    FILE *archivo2;
	char caracter;
    char arche[9000];
    int i = 0;
	
	archivo2 = fopen("bbdd.txt", "r");
	
	if (archivo2 == NULL) {
        printf("\nError de apertura del archivo. \n\n");
    }
    else {
        while((caracter = fgetc(archivo2)) != EOF) {
            arche[i] = caracter;
            i++;
        }
    }

    fclose(archivo2);

    // A partir de acá cargo los alumnos por materia DESDE el vector.

    char nomAlu[60];
    char dniAlu[12];
    char codMat[3];
    char esAlu[2];
    int c = 0; // contador
    int k = 0; // otro contador para almacenar el nombre
    int cambiar = 0;
    int eliminados = 0;

    FILE * salida;
    salida = fopen("bbdd.txt", "w");

    while (c < i) {

        if (arche[c] == '\n' || arche[c] == '\0' || c+1 == i) {

            if (materia == atoi(codMat) && dni == atoi(dniAlu)) {
                // printf("Eliminado!");
                eliminados++;
            }

            else {

                int m = fprintf(salida, "%s,%s,%s,%s", nomAlu, dniAlu, codMat, esAlu); // -----

                // printf("%s,%s,%s,%s", nomAlu, dniAlu, codMat, esAlu); // -----
                if (i-10 < c) {
                    // printf("%c", arche[c]); // -----
                    m = fprintf(salida, "%c", arche[c]); // -----
                }
            }

            k = 0;
            cambiar = 0;
            memset(nomAlu, 0, 60);
            memset(dniAlu, 0, 12);
            memset(codMat, 0, 3);
            memset(esAlu, 0, 2);
            strcpy(dniAlu, "");
            strcpy(codMat, "");

        }  

        if (arche[c] == ',') {
            cambiar++;
            k = 0;
            c++;
            continue;
        }

        if (cambiar == 0) {
            nomAlu[k] = arche[c];
            k++;
        }

        if (cambiar == 1) {
            dniAlu[k] = arche[c];
            k++;
        }

        if (cambiar == 2) { 
            codMat[k] = arche[c];
            k++;
        }

        if (cambiar == 3) { 
            esAlu[0] = arche[c];
        }

        c++;
    }

    fclose(salida);

    return eliminados;
    
}

int mostrarProfesores() {

    // Va a mostrar todos los profesores del departamento.

    FILE *archivo2;
	char caracter;
    char arche[9000];
    int i = 0;
	
	archivo2 = fopen("bbdd.txt","r");
	
	if (archivo2 == NULL) {
        printf("\nError de apertura del archivo. \n\n");
    }
    
    else {
        while((caracter = fgetc(archivo2)) != EOF) {
            arche[i] = caracter;
            i++;
        }
    }

    fclose(archivo2);

    // A partir de acá cargo los alumnos por materia DESDE el vector.

    char nomAlu[60];
    char dniAlu[12];
    char codMat[3];
    char esAlu[2];
    int c = 0; // contador
    int k = 0; // otro contador para almacenar el nombre
    int cambiar = 0;
    int mostrados = 0;

    while (c < i) {


        if (arche[c] == '\n' || arche[c] == '\0' || c+1 == i) {
            if (atoi(esAlu) == 1) {
                printf("%s - %s", nomAlu, codMat);
                mostrados++;
            }
            k = 0;
            cambiar = 0;
            memset(nomAlu, 0, 60);
            memset(dniAlu, 0, 12);
            memset(codMat, 0, 3);
            memset(esAlu, 0, 2);
            strcpy(dniAlu, "");
            strcpy(codMat, "");
        }  

        if (arche[c] == ',') {
            cambiar++;
            k = 0;
            c++;
            continue;
        }

        if (cambiar == 0) {
            nomAlu[k] = arche[c];
            k++;
        }

        if (cambiar == 1) {
            dniAlu[k] = arche[c];
            k++;
        }

        if (cambiar == 2) { 
            codMat[k] = arche[c];
            k++;
        }

        if (cambiar == 3) { 
            esAlu[0] = arche[c];
        } 

        c++;

    }

    return mostrados;

}



