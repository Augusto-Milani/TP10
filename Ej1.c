/*
 * main.c
 *
 *  Created on: Oct 16, 2024
 *      Author: amilani
 */

#include <stdio.h>

void strcopy (char*, const char*);

int main(void) {
	typedef struct {
		char nombre[20];
		char apellido[20];
		float promedio;
	} alumno_t;

	alumno_t a[3];
	alumno_t *pAlumno = a;

	strcopy(pAlumno->nombre, "Juan");
	strcopy((*pAlumno).apellido, "Perez");
	pAlumno->promedio = 2.3;
	printf("%s %s, %f\n", pAlumno->nombre, pAlumno->apellido, (*pAlumno).promedio);
	return 0;
}

void strcopy (char* s1, const  char* s2) {
	do {
		*s1++ = *s2;
	} while(*s2++);
}
