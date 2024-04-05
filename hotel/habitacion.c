#include <stdio.h>
#include "Habitacion.h"
#include <string.h>
#include <stdlib.h>

void imprimirHabitacion(Habitacion h){
	printf("Habitacion nº: %i, Tipo de habitacion: %s, Capacidad: %i, Precio por noche: %.2f, Estado: %s", h.id, h.tipo, h.capacidad, h.precio, h.estado);
}
