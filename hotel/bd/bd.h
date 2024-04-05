/*
 * bd.h
 *
 *  Created on: 4 abr 2024
 *      Author: mario
 */

#ifndef BD_H_
#define BD_H_

#include "sqlite3.h"
#include "admin.h"
#include "habitacion.h"
#include "hotel.h"
#include "usuario.h"
#include <stdio.h>
#include <string.h>

//BD
sqlite3* cargarBD();
sqlite3* cerrarBD(sqlite3* bd);
//Admin
int verificarAdmin(char*, char*, sqlite3*);
//Usuario
int cargarUsuarios(sqlite3* bd);
int anadirUsuario(char* nombre, char* apellido, char* contrasena, int id, char* email, sqlite3* bd);
int eliminarUsuario(int id, sqlite3* bd);
int verificarUsuario(char*, char*, sqlite3*);
//Hoteles
int cargarHoteles(sqlite3* bd);
int anadirHotel(char* nombre, int estrellas, char* pais, char* ciudad, int num_piso, int num_indiv, int num_dobles, int num_suite, sqlite3* bd);
int eliminarHotel(int id, sqlite3* bd);
//Habitaciones
int cargarHabitaciones(sqlite3* bd);
int anadirHabitacion(int id, char* tipo, int capacidad, float precio, char* estado, sqlite3* bd);
int eliminarHabitacion(int id, sqlite3* bd);
//Reservas
int cargarReservas(sqlite3* bd);
int anadirReserva(int id, char* nombreHotel, char* fechaEntrada, char* fechaSalida ,sqlite3* bd);
int eliminarReserva(int id, sqlite3* bd);

#endif /* BD_H_ */
