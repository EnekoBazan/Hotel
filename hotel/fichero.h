/*
 * fichero.h
 *
 *  Created on: 8 abr 2024
 *      Author: mario
 */
#ifndef FICHERO_H
#define FICHERO_H

#include "bd.h" // Incluimos el archivo de cabecera de la base de datos para acceder a las estructuras de datos necesarias

// Funciones públicas
void guardarHotelesEnArchivo(sqlite3 *db, const char *nombreArchivo);
void guardarHabitacionesLibresEnArchivo(sqlite3 *db, const char *nombreArchivo);

#endif /* FICHERO_H */

