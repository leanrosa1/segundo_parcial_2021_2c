/*
 * menu.c
 *
 *  Created on: 6 nov. 2021
 *      Author: leandro
 */


#include <stdio.h>
#include <stdlib.h>
#include "input.h"


void menu_printMainMenu (void)
{
	printf("\n");
	printf("\n----------------MENU----------------");
	printf("\n1. LEER ARCADES DESDE ARCHIVO CSV");
	printf("\n2. INCORPORAR ARCADE");
	printf("\n3. MODIFICAR ARCADE");
	printf("\n4. ELIMINAR ARCADE");
	printf("\n5. IMPRIMIR ARCADES ORDENADOS POR NOMBRE DE JUEGO");
	printf("\n6. GENERAR ARCHIVO CON JUEGOS");
	printf("\n7. GENERAR ARCHIVO CON ARCADES MULTIJUGADOR");
	printf("\n8. ACTUALIZAR CANTIDAD DE FICHAS");
	printf("\n9. SALIR");
	printf("\n------------------------------------");
}

void menu_printEditMenu (void)
{
	printf("\n");
	printf("\n------------------------------------");
	printf("\n1. MODIFICAR CANTIDAD DE JUGADORES");
	printf("\n2. MODIFICAR JUEGO QUE CONTIENE");
	printf("\n------------------------------------");
}

int menu_selectAnOption (int* selectedOption, int minValue, int maxValue)
{
	int status = -1;
	int auxiliarSelectedOption;

	if (input_getInt(minValue, maxValue, 2, "->Seleccione una opcion", &auxiliarSelectedOption, "Error") == 1)
	{
		status = 1;
		*selectedOption = auxiliarSelectedOption;
	}
	return status;
}

