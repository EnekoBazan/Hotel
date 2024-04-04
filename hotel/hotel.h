/*
 * hotel.h
 *
 *  Created on: 4 abr 2024
 *      Author: mario
 */

#ifndef HOTEL_H_
#define HOTEL_H_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct{

	char* nombre;
	int estrellas;
	char* pais;
	char* ciudad;
	int num_piso;
	int num_indiv;
	int num_dobles;
	int num_suite;

}Hotel;

#endif /* HOTEL_H_ */
