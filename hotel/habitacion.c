#include <stdio.h>
#include "Habitacion.h"
#include <string.h>
#include <stdlib.h>

void imprimirHabitacion(Habitacion h){
	printf("Habitacion nº: %i, Tipo de habitacion: %s, Capacidad: %i, Precio por noche: %.2f, Estado: %s", h.id, h.tipo, h.capacidad, h.precio, h.estado);
}

void anyadirHabitaciones(Habitacion* Habitaciones, int tamanyoHabitaciones){
	char tipo[100];
	int capacidad = 0;
	float precio = 0;
	char estado[100];
	printf("Indique todos los datos en mayusculas, por favor\n");
	printf("Indique el tipo de habitación: ");
	scanf("%s", tipo);
	printf("Indique la capacidad de la habitacion: \n");
	scanf("%i", &capacidad);
	printf("Indique el precio por noche de la habitacion: \n");
	scanf("%.2f", &precio);

	Habitaciones = malloc(sizeof(Habitacion) * tamanyoHabitaciones + 1);

	Habitaciones[tamanyoHabitaciones].tipo = malloc(sizeof(char) * 100);
	Habitaciones[tamanyoHabitaciones].estado = malloc(sizeof(char) * 100);

	Habitaciones[tamanyoHabitaciones].id = Habitaciones[tamanyoHabitaciones-1].id++;
	strcpy(Habitaciones[tamanyoHabitaciones].tipo, tipo);
	Habitaciones[tamanyoHabitaciones].capacidad = capacidad;
	Habitaciones[tamanyoHabitaciones].precio = precio;
	strcpy(Habitaciones[tamanyoHabitaciones].estado, "DISPONIBLE");

	char estado2[] = "DISPONIBLE";

	sqlite3 *db;

//	printf("Database opened\n") ;
//
//	result = insertNewHabitacion(db, tipo, capacidad, precio, estado2);
//	if (result != SQLITE_OK) {
//		printf("Error inserting new data\n");
//		printf("%s\n", sqlite3_errmsg(db));
//	}

}
