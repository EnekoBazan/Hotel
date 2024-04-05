#include <stdlib.h>
#include <stdio.h>
#include "admin.c"

int main(void){

	menuPrincipal();

	return 0;
}

void menuPrincipal()
{
	int seleccion;

		printf("== Menu Principal==\n");
		printf("1- Iniciar Sesion Administrador\n");
		printf("2- Iniciar Sesion Usuario\n");
		printf("2- Registrarse \n");
		printf("3- Salir \n");
		fflush(stdout);
		scanf("%d",&seleccion);

		switch(seleccion){

	    case 1:
	         iniciarSesionAdmin();
	         break;
	     case 2:
	    	 iniciarSesionUsuario();
	         break;
	     case 3:
	    	 registrarse();
	         break;
	     case 4:
	         printf("Saliendo...\n");
	         break;
	     default:
	         printf("Opción no válida\n");
	         break;
		}
}

void iniciarSesionAdmin()
{
	char nombreAdmin;
	char* aux= (char*)malloc(sizeof(char)*100);

	printf("== Iniciar Sesion administrador==\n");
	printf("Introduce el nombre de administrador: ");
	fflush(stdout);
	scanf("%s",&nombreAdmin);
	printf("Introduce la contrasena: ");
	fflush(stdout);
	scanf("%s",aux);

	deustoBookingAdmin();

}

void deustoBookingAdmin(){
	int seleccion;

	printf("== Deusto Booking==\n");
	printf("1-Buscar Hoteles\n");
	printf("2-Hacer una reserva \n");
	printf("3-Cancelar una reserva \n");
	printf("4-Ver mis reservas\n");
	printf("5-Cerrar Sesion \n");
	fflush(stdout);
	scanf("%d",&seleccion);
}

void iniciarSesionUsuario(){
	char nombreUsuario;
	char contrasena;

	printf("== Iniciar Sesion usuario==\n");
	printf("Introduce el nombre de usuario :\n");
	fflush(stdout);
	scanf("%s",&nombreUsuario);
	printf("Introduce la contrasena:\n");
	fflush(stdout);
	scanf("%s",&contrasena);
	printf("0. Atras \n");

	deustoBooking();


}

void registrarse(){
	char nombre;
	char nombreUsuario;
	char contrasena;
	int numeroTelefono;
	char direccionResidencia;

	printf("== Registrarse==\n");
	printf("Introduce el nombre :\n");
	fflush(stdout);
	scanf("%s",&nombre);
	printf("Introduce el nombre de usuario :\n");
	fflush(stdout);
	scanf("%s",&nombreUsuario);
	printf("Introduce la contrasena:");
	fflush(stdout);
	scanf("%s",&contrasena);
	printf("Introduce el numero de telefono:");
	fflush(stdout);
	scanf("%d",&numeroTelefono);
	printf("Introduce la direccion de residencia:");
	fflush(stdout);
	scanf("%s",&direccionResidencia);
	printf("0. Atras \n");

}


void deustoBooking(){
	int seleccion;

	printf("== Deusto Booking==\n");
	printf("1-Buscar Hoteles\n");
	printf("2-Hacer una reserva \n");
	printf("3-Cancelar una reserva \n");
	printf("4-Ver mis reservas\n");
	printf("5-Cerrar Sesion \n");
	fflush(stdout);
	scanf("%d",&seleccion);
}

void reservar(){
	char pais;
	char hotel;
	char ciudad;
	int piso;
	char tipoHabitacion;
	char fechaE;
	char fechaS;
	int numeroPersonas;

	printf("== Reservar==\n");
	printf("Introduce el pais :\n");
	fflush(stdout);
	scanf("%s",&pais);
	printf("Introduce el nombre del hotel :\n");
	fflush(stdout);
	scanf("%s",&hotel);
	printf("Introduce la ciudad:");
	fflush(stdout);
	scanf("%s",&ciudad);
	printf("Introduce el piso:");
	fflush(stdout);
	scanf("%d",&piso);
	printf("Introduce el tipo de habitacion:");
	fflush(stdout);
	scanf("%s",&tipoHabitacion);
	printf("Introduce la fecha de entrada:");
	fflush(stdout);
	scanf("%s",&fechaE);
	printf("Introduce la fecha de salida:");
	fflush(stdout);
	scanf("%s",&fechaS);
	printf("Introduce el numero de personas:");
	fflush(stdout);
	scanf("%d",&numeroPersonas);
	printf("0. Atras \n");



}

void cancelarReserva(){

	int codigoReserva;

	printf("== Cancelar Reservar==\n");
	printf("Introduce el codigo de la reserva :\n");
	fflush(stdout);
	scanf("%s",&codigoReserva);
	printf("0. Atras \n");

}


