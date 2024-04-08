/*
 * bd.c
 *
 *  Created on: 4 abr 2024
 *      Author: mario
 */

#include "bd.h"
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>

// BD

sqlite3* cargarBD() {
    sqlite3 *bd;
    int rc = sqlite3_open("baseDeDatos.db", &bd);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(bd));
        sqlite3_close(bd);
        return NULL;
    } else {
        printf("Base de datos abierta correctamente.\n");
    }
    return bd;
}


sqlite3* cerrarBD(sqlite3* bd) {
    if (bd) {
        sqlite3_close(bd);
        printf("Base de datos cerrada correctamente.\n");
    } else {
        printf("No hay base de datos abierta para cerrar.\n");
    }
    return NULL;
}

int verificarAdmin(char* nombreAdmin, char* contrasena, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT COUNT(*) FROM administradores WHERE usuario = ? AND contrasena = ?";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, nombreAdmin, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, contrasena, -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            result = sqlite3_column_int(stmt, 0); // Si hay una fila, el resultado será 1, indicando que las credenciales son válidas
        }

        sqlite3_finalize(stmt);
    }

    return result;
}



int cargarUsuarios(sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM usuarios";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        printf("Consulta preparada correctamente.\n");

        while (sqlite3_step(stmt) == SQLITE_ROW) {
            // Procesar cada fila de resultados aquí
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char *nombre = sqlite3_column_text(stmt, 1);
            const unsigned char *apellido = sqlite3_column_text(stmt, 2);
            const unsigned char *contrasena = sqlite3_column_text(stmt, 3);
            const unsigned char *email = sqlite3_column_text(stmt, 4);

            // Puedes imprimir o almacenar los datos como desees
            printf("ID: %d, Nombre: %s, Apellido: %s, Contraseña: %s, Email: %s\n", id, nombre, apellido, contrasena, email);
        }

        sqlite3_finalize(stmt);
        result = 1; // Indicar que se cargaron usuarios exitosamente
    } else {
        fprintf(stderr, "Error al preparar la consulta: %s\n", sqlite3_errmsg(bd));
    }

    return result;
}

int anadirUsuario(char* nombre, char* apellido, char* contrasena, int id, char* email, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO usuarios (id, nombre, apellido, contrasena, email) VALUES (?, ?, ?, ?, ?)";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);
        sqlite3_bind_text(stmt, 2, nombre, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, apellido, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, contrasena, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 5, email, -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            printf("Usuario añadido correctamente.\n");
            result = 1; // Indicar que el usuario se añadió correctamente
        } else {
            fprintf(stderr, "Error al añadir usuario: %s\n", sqlite3_errmsg(bd));
        }

        sqlite3_finalize(stmt);
    }

    return result;
}

int eliminarUsuario(int id, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM usuarios WHERE id = ?";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            printf("Usuario eliminado correctamente.\n");
            result = 1; // Indicar que el usuario se eliminó correctamente
        } else {
            fprintf(stderr, "Error al eliminar usuario: %s\n", sqlite3_errmsg(bd));
        }

        sqlite3_finalize(stmt);
    }

    return result;
}

int verificarUsuario(char* usuario, char* contrasena, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT COUNT(*) FROM usuarios WHERE nombre = ? AND contrasena = ?";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, usuario, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, contrasena, -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_ROW) {
            result = sqlite3_column_int(stmt, 0); // Si hay una fila, el resultado será 1, indicando que las credenciales son válidas
        }

        sqlite3_finalize(stmt);
    }

    return result;
}

int cargarHoteles(sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM hoteles";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            // Procesar cada fila de resultados aquí
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char *nombre = sqlite3_column_text(stmt, 1);
            int estrellas = sqlite3_column_int(stmt, 2);
            const unsigned char *pais = sqlite3_column_text(stmt, 3);
            const unsigned char *ciudad = sqlite3_column_text(stmt, 4);
            int num_piso = sqlite3_column_int(stmt, 5);
            int num_indiv = sqlite3_column_int(stmt, 6);
            int num_dobles = sqlite3_column_int(stmt, 7);
            int num_suite = sqlite3_column_int(stmt, 8);

            // Puedes imprimir o almacenar los datos como desees
            printf("ID: %d, Nombre: %s, Estrellas: %d, País: %s, Ciudad: %s, Piso: %d, Individuales: %d, Dobles: %d, Suite: %d\n",
                    id, nombre, estrellas, pais, ciudad, num_piso, num_indiv, num_dobles, num_suite);
        }

        sqlite3_finalize(stmt);
        result = 1; // Indicar que se cargaron hoteles exitosamente
    }

    return result;
}

int anadirHotel(char* nombre, int estrellas, char* pais, char* ciudad, int num_piso, int num_indiv, int num_dobles, int num_suite, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO hoteles (nombre, estrellas, pais, ciudad, num_piso, num_indiv, num_dobles, num_suite) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, nombre, -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, estrellas);
        sqlite3_bind_text(stmt, 3, pais, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, ciudad, -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 5, num_piso);
        sqlite3_bind_int(stmt, 6, num_indiv);
        sqlite3_bind_int(stmt, 7, num_dobles);
        sqlite3_bind_int(stmt, 8, num_suite);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            printf("Hotel añadido correctamente.\n");
            result = 1; // Indicar que el hotel se añadió correctamente
        } else {
            fprintf(stderr, "Error al añadir hotel: %s\n", sqlite3_errmsg(bd));
        }

        sqlite3_finalize(stmt);
    }

    return result;
}

int eliminarHotel(int id, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM hoteles WHERE id = ?";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            printf("Hotel eliminado correctamente.\n");
            result = 1; // Indicar que el hotel se eliminó correctamente
        } else {
            fprintf(stderr, "Error al eliminar hotel: %s\n", sqlite3_errmsg(bd));
        }

        sqlite3_finalize(stmt);
    }

    return result;
}

int cargarHabitaciones(sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM habitaciones";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            // Procesar cada fila de resultados aquí
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char *tipo = sqlite3_column_text(stmt, 1);
            int capacidad = sqlite3_column_int(stmt, 2);
            float precio = sqlite3_column_double(stmt, 3);
            const unsigned char *estado = sqlite3_column_text(stmt, 4);

            // Puedes imprimir o almacenar los datos como desees
            printf("ID: %d, Tipo: %s, Capacidad: %d, Precio: %.2f, Estado: %s\n",
                    id, tipo, capacidad, precio, estado);
        }

        sqlite3_finalize(stmt);
        result = 1; // Indicar que se cargaron habitaciones exitosamente
    }

    return result;
}

int anadirHabitacion(int id, char* tipo, int capacidad, float precio, char* estado, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO habitaciones (id, tipo, capacidad, precio, estado) VALUES (?, ?, ?, ?, ?)";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);
        sqlite3_bind_text(stmt, 2, tipo, -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 3, capacidad);
        sqlite3_bind_double(stmt, 4, precio);
        sqlite3_bind_text(stmt, 5, estado, -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            printf("Habitación añadida correctamente.\n");
            result = 1; // Indicar que la habitación se añadió correctamente
        } else {
            fprintf(stderr, "Error al añadir habitación: %s\n", sqlite3_errmsg(bd));
        }

        sqlite3_finalize(stmt);
    }

    return result;
}

int eliminarHabitacion(int id, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM habitaciones WHERE id = ?";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            printf("Habitación eliminada correctamente.\n");
            result = 1; // Indicar que la habitación se eliminó correctamente
        } else {
            fprintf(stderr, "Error al eliminar habitación: %s\n", sqlite3_errmsg(bd));
        }

        sqlite3_finalize(stmt);
    }

    return result;
}

int cargarReservas(sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "SELECT * FROM reservas";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            // Procesar cada fila de resultados aquí
            int id = sqlite3_column_int(stmt, 0);
            const unsigned char *nombreHotel = sqlite3_column_text(stmt, 1);
            const unsigned char *fechaEntrada = sqlite3_column_text(stmt, 2);
            const unsigned char *fechaSalida = sqlite3_column_text(stmt, 3);

            // Puedes imprimir o almacenar los datos como desees
            printf("ID: %d, Hotel: %s, Entrada: %s, Salida: %s\n",
                    id, nombreHotel, fechaEntrada, fechaSalida);
        }

        sqlite3_finalize(stmt);
        result = 1; // Indicar que se cargaron reservas exitosamente
    }

    return result;
}

int anadirReserva(int id, char* nombreHotel, char* fechaEntrada, char* fechaSalida, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "INSERT INTO reservas (id, nombreHotel, fechaEntrada, fechaSalida) VALUES (?, ?, ?, ?)";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);
        sqlite3_bind_text(stmt, 2, nombreHotel, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, fechaEntrada, -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 4, fechaSalida, -1, SQLITE_STATIC);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            printf("Reserva añadida correctamente.\n");
            result = 1; // Indicar que la reserva se añadió correctamente
        } else {
            fprintf(stderr, "Error al añadir reserva: %s\n", sqlite3_errmsg(bd));
        }

        sqlite3_finalize(stmt);
    }

    return result;
}

int eliminarReserva(int id, sqlite3* bd) {
    sqlite3_stmt *stmt;
    const char *sql = "DELETE FROM reservas WHERE id = ?";
    int result = 0;

    if (sqlite3_prepare_v2(bd, sql, -1, &stmt, NULL) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, id);

        if (sqlite3_step(stmt) == SQLITE_DONE) {
            printf("Reserva eliminada correctamente.\n");
            result = 1; // Indicar que la reserva se eliminó correctamente
        } else {
            fprintf(stderr, "Error al eliminar reserva: %s\n", sqlite3_errmsg(bd));
        }

        sqlite3_finalize(stmt);
    }

    return result;
}
