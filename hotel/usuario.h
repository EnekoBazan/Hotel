#ifndef USUARIO_H_
#define USUARIO_H_

typedef struct
{
	int id;
	char* nombre;
	char* apellido;
	char* email;
	char* cotrasena;
	int edad;
	char* sexo;
	int telefono;

}Usuario;

void imprimirUsuario(Usuario u);

#endif /* USUARIO_H_ */
