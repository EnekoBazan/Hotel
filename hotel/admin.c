#include "admin.h"

void iniciarAdmin(sqlite3* bd)
{
	char nombre;
	char* aux= (char*)malloc(sizeof(char)*100);
	printf("Nombre: ");
	fflush(stdout);
	scanf("%s", nombre);
	printf("Contrasena: ");
	fflush(stdout);
	scanf("%s",aux);
	//cargarAdmin(nombre,aux,bd);
}
