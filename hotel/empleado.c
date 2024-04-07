#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "../sqlite3.h"


void imprimirEmpleadoLargo(Empleado e){
	printf("Empleado número %i:\n- Nombre: %s\n- Apellido: %s\n- Salario: %.2f\n- Puesto: %s\n- Telefono: %i\n- Sexo: %s\n- Nombre de usuario: %s\n- Contraseña: %s\n", e.id, e.nombre, e.apellido, e.salario, e.puesto, e.telefono, e.sexo, e.nombreUsuario, e.contrasena);
}

int loginEmpleado(Empleado* empleados, int tamanyo){
	int resultado = 0;
	char nombreUsuario[10];
	char contrasena[10];
	printf("\n----------------------------\n\n");
	printf("INICIO DE SESIÓN\n");
	printf("Nombre de usuario: ");
	scanf("%s", nombreUsuario);
	printf("Contraseña: ");
	scanf("%s", contrasena);

	for (int i = 0; i < tamanyo; ++i) {
		if(strcmp(empleados[i].nombreUsuario, nombreUsuario) == 0 && strcmp(empleados[i].contrasena, contrasena) == 0){
			printf("\nLogin correcto!\n");
			resultado = 1;
			break;
		} else if (strcmp(empleados[i].nombreUsuario, nombreUsuario) == 0 && strcmp(empleados[i].contrasena, contrasena) != 0){
			printf("\nHa introducido mal la contraseña\n");
			resultado = 0;
			break;
		} else {
			printf("\nLos datos introducidos son erroneos\n");
			resultado = 0;
			break;
		}
	}
	return resultado;
}


