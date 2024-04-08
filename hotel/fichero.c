#include "fichero.h"
#include <stdio.h>

void guardarHotelesEnArchivo(sqlite3 *db, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar hoteles.\n");
        return;
    }

    // Consulta para obtener los hoteles desde la base de datos
    const char *sql = "SELECT * FROM hoteles";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Error al preparar la consulta para guardar hoteles.\n");
        fclose(archivo);
        return;
    }

    // Escribir cada hotel en el archivo
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int id = sqlite3_column_int(stmt, 0);
        const unsigned char *nombre = sqlite3_column_text(stmt, 1);
        int estrellas = sqlite3_column_int(stmt, 2);
        const unsigned char *pais = sqlite3_column_text(stmt, 3);
        const unsigned char *ciudad = sqlite3_column_text(stmt, 4);

        fprintf(archivo, "ID: %d, Nombre: %s, Estrellas: %d, País: %s, Ciudad: %s\n",
                id, nombre, estrellas, pais, ciudad);
    }

    sqlite3_finalize(stmt);
    fclose(archivo);
}

void guardarHabitacionesLibresEnArchivo(sqlite3 *db, const char *nombreArchivo) {
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para guardar habitaciones libres.\n");
        return;
    }

    // Consulta para obtener todas las habitaciones libres de todos los hoteles
    const char *sql = "SELECT * FROM habitaciones";
    sqlite3_stmt *stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        printf("Error al preparar la consulta para guardar habitaciones libres.\n");
        fclose(archivo);
        return;
    }

    // Escribir cada habitación libre en el archivo
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        int hotel_id = sqlite3_column_int(stmt, 0);
        const unsigned char *hotel_nombre = sqlite3_column_text(stmt, 1);
        int id = sqlite3_column_int(stmt, 2);
        const unsigned char *tipo = sqlite3_column_text(stmt, 3);
        int capacidad = sqlite3_column_int(stmt, 4);
        float precio = sqlite3_column_double(stmt, 5);

        fprintf(archivo, "Hotel ID: %d, Hotel Nombre: %s, Habitación ID: %d, Tipo: %s, Capacidad: %d, Precio: %.2f\n",
                hotel_id, hotel_nombre, id, tipo, capacidad, precio);
    }

    sqlite3_finalize(stmt);
    fclose(archivo);
}

