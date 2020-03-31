////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
// INICIO CÓDIGO ///////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string.h>
#include "alumno.h"




/// Creación de los structs (globales) /////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

typedef struct {
    char nombre[60];
    int codigo;
} Materia;

typedef struct {
    char nombre[60];
    Materia materias[40];
} Carrera;

typedef struct {
    char nombre[60];
    Carrera carreras[60];
} Departamento;

typedef struct {
    char nombre[60];
    char direccion[60];
    Departamento departamentos[4];
} Universidad;




/// Funciones //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

void mostrarDepartamentos(Universidad uni){

    // Funcion que muestra los departamentos recibiendo un objeto de tipo Universidad.

    int j = 0;
    while (strlen(uni.departamentos[j].nombre) > 10) {
        printf("%d %s\n", j, uni.departamentos[j].nombre);
        j++;
    }
}

void mostrarCarreras(Departamento dpto){

    // Funcion que muestra las carreras recibiendo un objeto de tipo Departamento.

    int j = 0;
    while (strlen(dpto.carreras[j].nombre) > 10) {
        printf("%d %s\n", j, dpto.carreras[j].nombre);
        j++;
    }
}

int mostrarMaterias(Carrera car){

    // Función que muestra las materias recibiendo un objeto de tipo Carrera.

    int j = 0;
    while (strlen(car.materias[j].nombre) > 10) {
        printf("%d %s\n",car.materias[j].codigo, car.materias[j].nombre);
        j++;
    }
    if (j == 0) {
        printf("No se registraron materias todavía.");
        return 0;
    }
    else {
        return 1;
    }

}

void cargarUniversidad(Universidad *objUniversidad){

    // Funcion para llenar todos los departamentos y materias de la UNLA.

    strcpy(objUniversidad->nombre, "Universidad Nacional de Lanús");
    strcpy(objUniversidad->direccion, "29 de Septiembre 3901, B1832 Remedios de Escalada, Buenos Aires");

    // Cargo los departamenos y las carreras de cada uno de ellos.

    strcpy(objUniversidad->departamentos[0].nombre, "Departamento Humanidades");
        strcpy(objUniversidad->departamentos[0].carreras[0].nombre, "Licenciatura en Audiovisión");
        strcpy(objUniversidad->departamentos[0].carreras[1].nombre, "Licenciatura en Diseño Industrial");
        strcpy(objUniversidad->departamentos[0].carreras[2].nombre, "Licenciatura en Diseño y Comunicación Visual");
        strcpy(objUniversidad->departamentos[0].carreras[3].nombre, "Traductorado Público en Idioma Inglés");
        strcpy(objUniversidad->departamentos[0].carreras[4].nombre, "Ciclo de Licenciatura en Música de Cámara y Sinfónica ");

    strcpy(objUniversidad->departamentos[1].nombre, "Departamento Planificacion y Politicas Publicas");
        strcpy(objUniversidad->departamentos[1].carreras[0].nombre, "Ciclo de Licenciatura en Seguridad Ciudadana");
        strcpy(objUniversidad->departamentos[1].carreras[1].nombre, "Licenciatura en Ciencia Política y Gobierno");
        strcpy(objUniversidad->departamentos[1].carreras[2].nombre, "Ciclo de Licenciatura en Gestión Educativa");
        strcpy(objUniversidad->departamentos[1].carreras[3].nombre, "Licenciatura en Justicia y Derechos Humanos");
        strcpy(objUniversidad->departamentos[1].carreras[4].nombre, "Licenciatura en Relaciones Internacionales");
        strcpy(objUniversidad->departamentos[1].carreras[5].nombre, "Ciclo de Licenciatura en Tecnologías Digitales para la Educación ");

    strcpy(objUniversidad->departamentos[2].nombre, "Departamento Desarrollo Productivo y Tecnologico");
        strcpy(objUniversidad->departamentos[2].carreras[0].nombre, "Licenciatura en Gestión Ambiental Urbana");
        strcpy(objUniversidad->departamentos[2].carreras[1].nombre, "Licenciatura en Economía Empresarial");
        strcpy(objUniversidad->departamentos[2].carreras[2].nombre, "Licenciatura en Economía Política");
        strcpy(objUniversidad->departamentos[2].carreras[3].nombre, "Licenciatura en Ciencia y Tecnología de los Alimentos");
        strcpy(objUniversidad->departamentos[2].carreras[4].nombre, "Licenciatura y Ciclo de Licenciatura en Turismo");
        strcpy(objUniversidad->departamentos[2].carreras[5].nombre, "Licenciatura en Sistemas");
        strcpy(objUniversidad->departamentos[2].carreras[6].nombre, "Licenciatura en Tecnologías Ferroviarias");
        strcpy(objUniversidad->departamentos[2].carreras[7].nombre, "Licenciatura y Ciclo de Licenciatura en Planificación Logística");

    strcpy(objUniversidad->departamentos[3].nombre, "Departamento Salud");
        strcpy(objUniversidad->departamentos[3].carreras[0].nombre, "Licenciatura en Enfermería");
        strcpy(objUniversidad->departamentos[3].carreras[1].nombre, "Ciclo de Licenciatura en Trabajo Social");
        strcpy(objUniversidad->departamentos[3].carreras[2].nombre, "Licenciatura en Nutrición");
        strcpy(objUniversidad->departamentos[3].carreras[3].nombre, "Ciclo de Licenciatura en Educación Física ");
}

void cargarMaterias(char f[60], Universidad *objUniversidad, int objDepartamento, int objCarrera) {

    // Funcion que carga las materias a partir de un archivo, recibe como parametros el nombre del archivo y
    // los datos para acceder a la carrera.

    // Primero cargo TODO el archivo en un vector.

    FILE *archivo;
	char caracter;
    char arch[9000];
    int i = 0;
	
	archivo = fopen(f,"r");
	
	if (archivo == NULL) {
        printf("\nError de apertura del archivo. \n\n");
    }
    else {
        while((caracter = fgetc(archivo)) != EOF) {
            arch[i] = caracter;
            i++;
        }
    }

    fclose(archivo);

    // A partir de acá cargo las materias en la carrera DESDE el vector.

    int posMateria = 0;
    int esCodigo = 0;
    int auxCodigo = 0;
    char cod[3];

    char nombreMateria[60];
    int auxNombreMateria = 0;

    for (int i = 0; i < 9000; i++) {

        if (arch[i] == '&') {
            break;
        }

        if (esCodigo == 0) {
            cod[auxCodigo] = arch[i];
            auxCodigo++;
        }

        if (esCodigo == 1 && arch[i] != ',' && arch[i] != '\n') {
            nombreMateria[auxNombreMateria] = arch[i];
            auxNombreMateria++; 
        }

        if (arch[i] == ',') {
            esCodigo = 1;
            auxCodigo = 0;
        }

        if (arch[i] == '\n') {

            strcpy(objUniversidad->departamentos[objDepartamento].carreras[objCarrera].materias[posMateria].nombre, nombreMateria);
            objUniversidad->departamentos[objDepartamento].carreras[objCarrera].materias[posMateria].codigo = atoi(cod);
            posMateria++;
            strcpy(cod, "");
            esCodigo = 0;
            auxNombreMateria = 0;

            for (int r = 0; r < 60; r++) {
                nombreMateria[r] = '\0';
            }
        }

    }

}

void registrarAlumno(Alumno objAlumno, Universidad objUniversidad, int objDepartamento, int objCarrera) {

    // Función que registra alumno en una materia y guarda en bbdd.txt, recibe como parametro un objeto
    // de tipo Alumno, obj tipo Universidad, un entero para seleccionar el departamento y un entero para seleccionar la carrera.

    int objMaterias;
    char nombreAlumno[60];
    char dniAlumno[20];
    char esAlu[10];
    char seleccion[10];
    int seguir = 1; // Variable que me permite elegir muchas materias.

    printf("Ingrese el nombre del alumno: ");
    fgets(nombreAlumno, 60, stdin);
    printf("Ingrese el DNI del alumno: ");
    fgets(dniAlumno, 20, stdin);
    printf("Es alumno o docente? <alumno = 0, docente = 1> : ");
    fgets(esAlu, 20, stdin);
    int a = atoi(dniAlumno);
    int b = atoi(esAlu);
    objAlumno = crearAlumno(a, nombreAlumno, b);

    while (seguir == 1) {

        // Bucle que va a repetirse para que la misma persona pueda anotarse a varias materias sin 
        // tener que escribir su nombre y dni mas de una vez.

        system("clear"); 

        if (mostrarMaterias(objUniversidad.departamentos[objDepartamento].carreras[objCarrera]) == 1) {
            printf("\nIngresá el código de materia: ");
            fgets(seleccion, 10, stdin);
            system("clear"); 
            printf("\nSeleccionaste: %s", objUniversidad.departamentos[objDepartamento].carreras[objCarrera].materias[atoi(seleccion)].nombre);

            if (regAlumno(getDni(objAlumno), getNombre(objAlumno), objUniversidad.departamentos[objDepartamento].carreras[objCarrera].materias[atoi(seleccion)].codigo, b) == 1 ){
                printf("\nRegistrado correctamente.");
            }
            else {
                printf("\nNo ha podido registrarse");
            }
            
            printf("\nQuerés anotarte en otra materia? (s/n): ");

            fgets(seleccion, 10, stdin);

            if (seleccion[0] == 's' || seleccion[0] == 'S') {
                seguir = 1;
            }

            else {
                seguir = 0;
            }

        }

        else {
            seguir = 0;
        }

    }

}




/// Main ///////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////

int main(){

    // Creo una instancia de Universidad llamado UNLA y luego le cargo los datos.

    Universidad UNLA;
    cargarUniversidad(&UNLA);

    // Cargo el archivo que tiene las materias de Lic. en Sistemas en un vector.

    cargarMaterias("mat.sistemas.txt", &UNLA, 2, 5);

    // Creo una instancia de Alumno para ir registrando lo que el usuario haga en el programa.

    Alumno alumnoLocal;

    // Muestro el menú, el string opción va a almacenar la opción que el usuario vaya ingresando a lo largo del programa.

    system("clear"); 
    char opcion[10];
    int a = 1; // condición para que el while siga abierto y se llame a si mismo.
    char depto[10]; // almacena el departamento.

    while (a == 1) {

        // Lo primero que se pide es que se elija un departamento.

        if (opcion[0] == '0' || opcion[0] == '1' || opcion[0] == '2' || opcion[0] == '3') {
            strcpy(depto, opcion);
            a = 0;
        }

        else {
            system("clear"); 
            printf("Bienvenido al SIU de la UNLA.\n");
            mostrarDepartamentos(UNLA);
            printf("Seleccioná el Departamento para continuar: ");
            fgets(opcion, 10, stdin);
        }

    }

    a = 1; // esta variable la uso como condicion para que el while siga abierto y se llame a si mismo.
    opcion[0] = '\0'; // borro el contenido que esta en el string opcion para que me vuelva a pedir el mismo.
    char carreraSeleccionada[10]; // string donde se va a almacenar la carrera que el usuario elija.

    while (a == 1) {

        // Lo segundo que se pide es que se elija una carrera.

        system("clear"); 
        if (opcion[0] == '0' || opcion[0] == '1' || opcion[0] == '2' || opcion[0] == '3' || opcion[0] == '4' || opcion[0] == '5' || opcion[0] == '6' || opcion[0] == '7' || opcion[0] == '8' || opcion[0] == '9') {
            a = 0;
            strcpy(carreraSeleccionada, opcion);
        }
        else {
            printf("%s\n", UNLA.departamentos[atoi(depto)].nombre);
            mostrarCarreras(UNLA.departamentos[atoi(depto)]);
            printf("Seleccioná la carrera para continuar: ");
            fgets(opcion, 10, stdin);
        }
    }


    while (opcion[0] != '9') {

        // Lo tercero que se pide es qué se quiere hacer con la base de datos.

        system("clear"); 
        printf("Elegí una opción para continuar.");
        printf("\n0 Ver los alumnos de una materia.");
        printf("\n1 Registrar un alumno en una materia.");
        printf("\n2 Eliminar un alumno de una materia.");
        printf("\n3 Ver las materias registradas de un alumno.");
        printf("\n4 Mostrar profesores de la UNLA.");
        printf("\n9 Salir del programa.");
        printf("\nOpción: ");

        fgets(opcion, 10, stdin);   

        if (opcion[0] == '0') {

            // Ver los alumnos de una materia.

            system("clear");

            if (mostrarMaterias(UNLA.departamentos[atoi(depto)].carreras[atoi(carreraSeleccionada)]) == 1) {
                mostrarMaterias(UNLA.departamentos[atoi(depto)].carreras[atoi(carreraSeleccionada)]);
                printf("\nIngrese el codigo de materia: ");
                fgets(opcion, 10, stdin);   
                if (strlen(UNLA.departamentos[atoi(depto)].carreras[atoi(carreraSeleccionada)].materias[atoi(opcion)].nombre) > 6 ) {
                    printf("\nSeleccionastew: %s", UNLA.departamentos[atoi(depto)].carreras[atoi(carreraSeleccionada)].materias[atoi(opcion)].nombre);
                    system("clear");
                    mostrarAlumnosPorMateria(atoi(opcion));
                }
                else {
                    system("clear");
                    printf("No se encontró esa materia.");
                }
            }

            memset(opcion, 0, 10);
            printf("\nPresiona ENTER para continuar.");
            getchar();

        }

        if (opcion[0] == '1') {

            // Registrar un alumno en una materia.

            system("clear");
            registrarAlumno(alumnoLocal, UNLA, atoi(depto), atoi(carreraSeleccionada));
            printf("\nPresiona ENTER para continuar.");
            getchar();

        }

        if (opcion[0] == '2') {

            // Eliminar un alumno de una materia.

            char opcion2[10];
            system("clear");
            printf("\nIngrese el DNI del alumno: ");
            fgets(opcion, 10, stdin);   
            printf("\nIngrese el código de materia: ");
            fgets(opcion2, 10, stdin);
            int eliminados = eliminarAlumnoEnMateria(atoi(opcion2), atoi(opcion));
            system("clear");
            printf("Se han eliminado %d registros.", eliminados);
            memset(opcion, 0, 10);
            printf("\nPresiona ENTER para continuar.");
            getchar();

        }

        if (opcion[0] == '3') {

            // Ver las materias registradas de un alumno.

            system("clear");
            printf("\nIngrese el DNI del alumno: ");
            fgets(opcion, 10, stdin);   
            system("clear");
            int *vectorMaterias;
            vectorMaterias = mostrarMateriasPorAlumno(atoi(opcion));
            int mostrando = 0;

            for ( int l = 0; l < 20; l++ ) {
                if ( * (vectorMaterias + l) > -1) {
                    mostrando++;
                    if (* (vectorMaterias + l) >= 10) {
                        printf("%d - %s\n", * (vectorMaterias + l), UNLA.departamentos[atoi(depto)].carreras[atoi(carreraSeleccionada)].materias[* (vectorMaterias + l)].nombre);
                    }
                    else {
                        printf("0%d - %s\n", * (vectorMaterias + l), UNLA.departamentos[atoi(depto)].carreras[atoi(carreraSeleccionada)].materias[* (vectorMaterias + l)].nombre);
                    }
                }
            }

            if (mostrando == 0) {
                printf("No se han encontrado registros.");
            }

            memset(opcion, 0, 10);
            printf("Presiona ENTER para continuar.");
            getchar();

        }

        if (opcion[0] == '4') {

            // Mostrar profesores de la UNLA.

            system("clear");
            int mostrando = mostrarProfesores();

            if (mostrando == 0) {
                printf("No se encontradon profesores.");
            }

            printf("\nPresiona ENTER para continuar.");
            getchar();

        }

        if (opcion[0] == '9') {

            // Salir.

            printf("Nos vemos!.\n");

        }

        // fin del menú

    }

    return 0; // fin del main

}




////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
// FIN CÓDIGO //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////