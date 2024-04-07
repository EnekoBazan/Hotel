#ifndef EMPLEADO_H_
#define EMPLEADO_H_

#include "sqlite3.h"

typedef struct{
	int id;
	char* nombre;
	char* apellido;
	float salario;
	char* puesto;
	int telefono;
	char* sexo;
	char* nombreUsuario;
	char* contrasena;
}Empleado;

void imprimirEmpleado(Empleado e);

int loginEmpleado(Empleado* empleados, int tamanyo);


#endif /* EMPLEADO_H_ */
