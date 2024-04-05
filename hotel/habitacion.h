#ifndef HABITACION_H_
#define HABITACION_H_

typedef struct{
	int id;
	char* tipo;
	int capacidad;
	float precio;
	char* estado;
}Habitacion;

void imprimirHabitacion(Habitacion h);

void anyadirHabitaciones(Habitacion* habitaciones, int tamanyoHabitaciones);

void eliminarHabitaciones(Habitacion* habitaciones, int tamanyoHabitaciones);

#endif /* HABITACION_H_ */
