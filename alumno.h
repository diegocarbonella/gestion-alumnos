#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED



struct EstructuraAlumno{

    int dni;
    char nombre[60];
    int esAlumno;

};

typedef struct EstructuraAlumno * Alumno;

Alumno crearAlumno(int dniN, char nombreN[60], int esAll);

void mostrarAlumno(Alumno p);

char *getNombre(Alumno p);

int getDni(Alumno p);

int getEsAlumno(Alumno p);

void setNombre(Alumno p, char nuevoNombre[20]);

void setDni(Alumno p, int nuevoDNI);

void setEsAlumno(Alumno p, int);

void destruirAlumno(Alumno p);

//
// ARCHIVOS
// 

// Va a registrar un alumno en bbdd.txt recibe como parametros nombre dni materia y si es o no alumno.
// lo unico que hace esta funcion es guardar el alumno en el archivo de texto.
int regAlumno(int dniN, char nombreN[60],int materia, int esAll);

// Muestra todos los alumnos de la base de datos.
void mostrarAlumnos();

// Muestra todos los alumnos por materia. Recibe como parametro el codigo de materia.
void mostrarAlumnosPorMateria(int materia);

// Muestra las materias en las que esta anotado un alumno, recibe DNI 
int * mostrarMateriasPorAlumno(int dni);

// Elimina un alumno registrado en alguno materia
int eliminarAlumnoEnMateria(int dni, int codigoMateria);

// Muestra todos los profesores de la UNLA.
int mostrarProfesores();

#endif // ALUMNO_H_INCLUDED
