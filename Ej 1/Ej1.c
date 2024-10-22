/*
 * main.c
 *
 *  Created on: Oct 16, 2024
 *      Author: amilani
 */

#include <stdio.h>

typedef struct {
	char nombre[20];
	char apellido[20];
	float promedio;
} alumno_t;

#define N 2	//Tamaño a bubblesortear

void strcopy (char*, const char*);
void swap (alumno_t*, alumno_t*);
void bubblesort (alumno_t[N]);

int main(void) {


	alumno_t a[N];
	alumno_t *pAlumno = a;

	strcopy(pAlumno->nombre, "Juan");
	strcopy((*pAlumno).apellido, "Perez");
	pAlumno->promedio = 2.3;

	pAlumno++;

	strcopy(pAlumno->nombre, "Tomás");
	strcopy((*pAlumno).apellido, "Rodríguez");
	pAlumno->promedio = 8.9;

	bubblesort(a);

	pAlumno = a;
	printf("%s %s, %f\n", pAlumno->nombre, pAlumno->apellido, (*pAlumno).promedio);
	pAlumno++;
	printf("%s %s, %f\n", pAlumno->nombre, pAlumno->apellido, (*pAlumno).promedio);
	return 0;
}

void strcopy (char* s1, const  char* s2) {
	do {
		*s1++ = *s2;
	} while(*s2++);
}

void swap(alumno_t* s1, alumno_t* s2) {
	alumno_t aux;

	strcopy(aux.nombre, s1->nombre);
	strcopy(aux.apellido, s1->apellido);
	aux.promedio = s1->promedio;
	printf("%s %s\n", aux.nombre, s1->nombre);

	strcopy(s1->nombre, s2->nombre);
	strcopy(s1->apellido, s2->apellido);
	s1->promedio = s2->promedio;
	printf("%s %s\n", s1->nombre, s2->nombre);


	strcopy(s2->nombre, aux.nombre);
	strcopy(s2->apellido, aux.apellido);
	s2->promedio = aux.promedio;
}

void bubblesort(alumno_t a[N]) {
	alumno_t* pAlumno = &a[0];
	int i, j;
	for (i=1 ; i<N ; i++) {
		*pAlumno = a[i];
		if (pAlumno->promedio < (pAlumno-1)->promedio) {
			swap(pAlumno, pAlumno-1);
		}

		else if (pAlumno->promedio == (pAlumno-1)->promedio) {
			for(j=0 ; pAlumno->apellido[j] != '\0' && (pAlumno-1)->apellido[j] != '\0' ; j++) {
				if (pAlumno->apellido[j] < (pAlumno-1)->apellido[j]) {
					swap(pAlumno, pAlumno-1);	//Nota: No importan mayúsculas.
				}
			}
		}
	}
}









