#ifndef ADMIN_H_
#define ADMIN_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "bd.h"

typedef struct{

	char* nombre;
	char* apellido;
	char* contrasena;
	int id;
	char* email;

}Administrador;


#endif /* ADMIN_H_ */
