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

		printf("\n== Menu Principal==\n");
		printf("1- Iniciar Sesion Administrador\n");
		printf("2- Iniciar Sesion Usuario\n");
		printf("3- Registrarse \n");
		printf("4- Salir \n");
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
	sqlite3 *db;
	char nombreAdmin;
	char contrasena;

	printf("== Iniciar Sesion administrador==\n");
	printf("Introduce el nombre de administrador: ");
	fflush(stdout);
	scanf("%s",&nombreAdmin);
	printf("Introduce la contrasena: ");
	fflush(stdout);
	scanf("%s",contrasena);

	  if (verificarAdmin(nombreAdmin, contrasena, db)) {

		  printf("Inicio de sesion exitoso!\n");
	      deustoBookingAdmin();

	    } else {

	    	printf("Nombre de administrador o contrasena incorrectos.\n");

	    }

	  sqlite3_close(db);

}

void deustoBookingAdmin(){
	int seleccion;

	printf("== Deusto Booking==\n");
	printf("1-Buscar Hoteles\n");
	printf("2-Borrar Hoteles \n");
	printf("3-Buscar reservas\n");
	printf("4-Cancelar una reserva \n");
	printf("5-Buscar usuario\n");
	printf("6-Cerrar Sesion \n");
	fflush(stdout);
	scanf("%d",&seleccion);
}

void iniciarSesionUsuario(sqlite3* bd){
	char nombreUsuario;
	char contrasena;
	int verificar;

	printf("== Iniciar Sesion usuario==\n");
	printf("Introduce el nombre de usuario :\n");
	fflush(stdout);
	scanf("%s",&nombreUsuario);
	printf("Introduce la contrasena:\n");
	fflush(stdout);
	scanf("%s",&contrasena);
	//verificar = verificarUsuario(nombreUsuario,contrasena,bd);
	//if(verificar == 1){
		//deustoBooking();
	//}else{
		//printf("Usuario o contrasena no validos,vuelvelo a intentar o registrate\n");
		//menuPrincipal();
		//fflush(stdout);
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

	switch(seleccion){

		    case 1:
		         //cargarHoteles();
		         break;
		     case 2:
		    	 reservar();
		         break;
		     case 3:
		    	 cancelarReserva();
		         break;
		     case 4:
		    	 //Ver mis reservas
		         printf("Saliendo...\n");
		         break;
		     case 5:
		   		    menuPrincipal();
		   		     printf("Saliendo...\n");
		   		      break;
		     default:
		         printf("Opción no válida\n");
		         break;
			}
}

void reservar(sqlite3* bd){
	char pais;
	char hotel;
	char ciudad;
	int piso;
	char tipoHabitacion;
	char fechaE;
	char fechaS;
	int numeroPersonas;
	int atras;

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
	printf("Reserva Realizada\n");
	fflush(stdout);
	deustoBooking(bd);





}

void cancelarReserva(){

	int codigoReserva;

	printf("== Cancelar Reservar==\n");
	printf("Introduce el codigo de la reserva :\n");
	fflush(stdout);
	scanf("%s",&codigoReserva);
	printf("0. Atras \n");

}


