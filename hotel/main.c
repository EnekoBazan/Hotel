#include <stdlib.h>
#include <stdio.h>
#include "admin.c"
#include "bd.h"

// Declaraciones de funciones
void menuPrincipal(sqlite3 *db);
void iniciarSesionAdmin(sqlite3 *db);
void deustoBookingAdmin(sqlite3 *db);
void iniciarSesionUsuario(sqlite3 *db);
void registrarse(sqlite3 *db);
void deustoBooking(sqlite3 *db);
void reservar(sqlite3 *db);
void cancelarReserva(sqlite3 *db);

int main(void) {
    sqlite3 *db = cargarBD(); // Cargamos la base de datos al inicio del programa

    if (db == NULL) {
        printf("Error al abrir la base de datos.\n");
        return 1;
    }

    menuPrincipal(db); // Pasamos la base de datos a la función del menú principal

    cerrarBD(db); // Cerramos la base de datos al salir del programa

    return 0;
}

void menuPrincipal(sqlite3 *db) {
    int seleccion;

    do {
        printf("\n== Menu Principal ==\n");
        printf("1- Iniciar Sesion Administrador\n");
        printf("2- Iniciar Sesion Usuario\n");
        printf("3- Registrarse\n");
        printf("4- Salir\n");
        printf("Seleccione una opcion: ");
        fflush(stdout);
        scanf("%d", &seleccion);

        switch (seleccion) {
            case 1:
                iniciarSesionAdmin(db);
                break;
            case 2:
                iniciarSesionUsuario(db);
                break;
            case 3:
                registrarse(db);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida\n");
                break;
        }
    } while (seleccion != 4);
}

void iniciarSesionAdmin(sqlite3 *db) {
    char nombreAdmin[50];
    char contrasena[50];

    printf("\n== Iniciar Sesion administrador ==\n");
    printf("Introduce el nombre de administrador: ");
    fflush(stdout);
    scanf("%s", nombreAdmin);
    printf("Introduce la contrasena: ");
    fflush(stdout);
    scanf("%s", contrasena);

    if (verificarAdmin(nombreAdmin, contrasena, db)) {
        printf("Inicio de sesion exitoso!\n");
        deustoBookingAdmin(db);
    } else {
        printf("Nombre de administrador o contrasena incorrectos.\n");
    }
}

void deustoBookingAdmin(sqlite3 *db) {
	int seleccion;

	    printf("\n== Deusto Booking==\n");
	    printf("1-Visualizar hoteles\n");
	    printf("2-Visualizar usuarios \n");
	    printf("3-Visualizar reservas\n");
	    printf("4-Cancelar una reserva\n");
	    printf("5-Cancelar un hotel\n");
	    printf("6-Eliminar un usuario\n");
	    printf("7-Cerrar Sesion \n");
	    fflush(stdout);
	    scanf("%d", &seleccion);

	    switch (seleccion) {
	        case 1:
	            if (cargarHoteles(db)){
	        		printf("Hoteles cargados correctamente\n");
	        		deustoBookingAdmin(db);
	            }else {
	        		printf("Error al cargar los hoteles\n");
	        		deustoBookingAdmin(db);
	        	}
	            break;
	        case 2:
	            if(cargarUsuarios(db)) {
	        		printf("Usuarios cargados correctamente\n");
	        		deustoBookingAdmin(db);
	            } else {
	        		printf("Error al cargar los usuarios\n");
	        		deustoBookingAdmin(db);
	            }
	            break;
	        case 3:
	        	if(cargarReservas(db)) {
	        		printf("Reservas cargadas correctamente\n");
	        		deustoBookingAdmin(db);
	        	}else {
	        		printf("Error al cargar las reservas\n");
	        		deustoBookingAdmin(db);
	        	}
	            break;
	        case 4:
	            cancelarReserva(db);
	            break;
	        case 5:
	        	cancelarHotel(db);
	            break;
	        case 6:
	        	cancelarUsuario(db);
	            break;
	        case 7:
	            menuPrincipal(db);
	            printf("Saliendo...\n");
	            break;
	        default:
	            printf("Opción no válida\n");
	            deustoBookingAdmin(db);
	            break;
	    }
}

void iniciarSesionUsuario(sqlite3 *bd) {
    char usuario[50]; // Ajustar el tamaño según la longitud máxima esperada del nombre de usuario
    char contrasena[50]; // Ajustar el tamaño según la longitud máxima esperada de la contraseña

    printf("\n== Iniciar Sesión usuario ==\n");
    printf("Introduce el nombre de usuario: ");
    fflush(stdout);
    scanf("%s", usuario); // Leemos el nombre de usuario
    printf("Introduce la contraseña: ");
    fflush(stdout);
    scanf("%s", contrasena); // Leemos la contraseña

    if (verificarUsuario(usuario, contrasena, bd)) { // Verificamos las credenciales
        printf("Inicio de sesión exitoso!\n");
        deustoBooking(bd); // Llamamos a la función deustoBooking para continuar con las opciones de reserva
    } else {
        printf("Nombre de usuario o contraseña incorrectos.\n");
    }
}

void registrarse(sqlite3 *db) {

	int id = 05;
	char nombre;
    char apellido;
    char contrasena;
    char email;


    printf("\n== Registrarse==\n");
    printf("Introduce el nombre :\n");
    fflush(stdout);
    scanf("%s", &nombre);
    printf("Introduce el apellido :\n");
    fflush(stdout);
    scanf("%s", &apellido);
    printf("Introduce la contrasena:");
    fflush(stdout);
    scanf("%s", &contrasena);
    printf("Introduce la direccion de residencia:");
    fflush(stdout);
    scanf("%s", &email);

    if(anadirUsuario(id, nombre, apellido, contrasena,  email, db)) {
       printf("Inicio de sesión exitoso!\n");
       menuPrincipal(db);
       id++;
   } else{
       printf("Nombre de usuario o contraseña incorrectos.\n");
   }


}

void deustoBooking(sqlite3* db) {
    int seleccion;

    printf("\n== Deusto Booking==\n");
    printf("1-Buscar Hoteles\n");
    printf("2-Hacer una reserva \n");
    printf("3-Cancelar una reserva \n");
    printf("4-Ver mis reservas\n");
    printf("5-Cerrar Sesion \n");
    fflush(stdout);
    scanf("%d", &seleccion);

    switch (seleccion) {
        case 1:
        	if (cargarHoteles(db)){
        		printf("Hoteles cargados correctamente\n");
        		deustoBooking(db);
        	}else {
        		printf("Error al cargar los hoteles\n");
        		deustoBooking(db);
        	}
            break;
        case 2:
            reservar(db);
            break;
        case 3:
            cancelarReserva(db);
            break;
        case 4:
            if(cargarReservas(db)) {
                printf("\nReservas cargadas correctamente\n");
                deustoBooking(db);
            }else {
            	printf("\nError al cargar las reservas\n");
            	deustoBooking(db);
            }
            break;
        case 5:
            menuPrincipal(db);
            printf("Saliendo...\n");
            break;
        default:
            printf("Opción no válida\n");
            break;
    }
}

void reservar(sqlite3* bd) {

    int id;
    char nombreHotel;
    char fechaEntrada;
    char fechaSalida;


    printf("== Reservar==\n");
    printf("Introduce el id del hotel :\n");
    fflush(stdout);
    scanf("%d", &id);
    printf("Introduce el nombre del hotel :\n");
    fflush(stdout);
    scanf("%s", &nombreHotel);
    printf("Introduce la fecha de entrada:");
    fflush(stdout);
    scanf("%s", &fechaEntrada);
    printf("Introduce la fecha de salida:");
    fflush(stdout);
    scanf("%s", &fechaSalida);


    if(anadirReserva(id, nombreHotel, fechaEntrada, fechaSalida, bd)){
    	printf("Reserva Realizada\n");
    	deustoBooking(bd);
    }else{
    	printf("\nError al cargar las reservas\n");
    	deustoBooking(bd);
    }

}

void cancelarReserva(sqlite3 *db) {
    int codigoReserva;

    printf("== Cancelar Reservar==\n");
    printf("Introduce el codigo de la reserva :\n");
    fflush(stdout);
    scanf("%d", &codigoReserva);
    eliminarReserva(codigoReserva, db);
    printf("0. Atras \n");
}

void cancelarHotel(sqlite3 *db) {
    int codigoHotel;

    printf("== Cancelar Hotel==\n");
    printf("Introduce el codigo del hotel :\n");
    fflush(stdout);
    scanf("%d", &codigoHotel);
    eliminarHotel(codigoHotel, db);
    printf("0. Atras \n");
}

void cancelarUsuario(sqlite3 *db) {
    int codigoUsuario;

    printf("== Cancelar Usuario==\n");
    printf("Introduce el codigo del usuario :\n");
    fflush(stdout);
    scanf("%d", &codigoUsuario);
    eliminarUsuario(codigoUsuario, db);
    printf("0. Atras \n");
}
