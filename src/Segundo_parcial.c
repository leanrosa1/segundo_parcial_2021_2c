/*
 ============================================================================
 Name        : Segundo_parcial.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "idFactory.h"
#include "menu.h"
#include "controller.h"

int main(void)
{
	int selectedOption;
	int upload = -1;
	LinkedList* arcadesList = ll_newLinkedList();
	int maximumId = idFactory_getMaximumId("/home/leandro/eclipse-workspace/Segundo_parcial/src/id.txt");
	printf("\nEl id maximo es %d", maximumId);

	do
	{
		//ll_clear(arcadesList);
		//controller_clearList(arcadesList);
		//controller_loadFromText("./src/arcades.csv", arcadesList);
		//upload = 1;
		menu_printMainMenu();
		if (menu_selectAnOption(&selectedOption, 1, 9) == 1)
		{
			switch(selectedOption)
			{
				case 1:
					/*if (controller_getArcadesFromText("./src/arcades.csv", arcadesList) != 1)
					{
						printf("\nErrorrrr");
					}
					else
						upload = 1;*/
					printf("\nCargado correctamente");
					break;
				case 2:
					if (controller_addArcade(arcadesList, maximumId, "/home/leandro/eclipse-workspace/Segundo_parcial/src/id.txt", "./src/arcades.csv") != 1)
					{
						printf("\nOcurrio un error");
					}
					else
					{
						maximumId++;
						//controller_clearList(arcadesList);
					}
					break;
				case 3:
					//controller_getArcadesFromText("./src/arcades.csv", arcadesList);
					if (upload != 1)
					{
						controller_getArcadesFromText("./src/arcades.csv", arcadesList);
						upload = 1;
					}
					if (controller_editArcade(arcadesList, "./src/arcades.csv") != 1)
					{
						printf("\nOcurrio un error");
					}
					break;
				case 4:
					//controller_getArcadesFromText("./src/arcades.csv", arcadesList);
					if (upload != 1)
					{
						controller_getArcadesFromText("./src/arcades.csv", arcadesList);
						upload = 1;
					}
					if (controller_deleteArcade("./src/arcades.csv",arcadesList) != 1)
					{
						printf("\nOcurrio un error");
					}
					break;
				case 5:
					//controller_getArcadesFromText("./src/arcades.csv", arcadesList);
					if (upload != 1)
					{
						controller_getArcadesFromText("./src/arcades.csv", arcadesList);
						upload = 1;
					}
					if (controller_printArcades("./src/arcades.csv",arcadesList) != 1)
					{
						printf("\nOcurrio un error");
					}
					break;
				case 6:
					//controller_getArcadesFromText("./src/arcades.csv", arcadesList);
					if (upload != 1)
					{
						controller_getArcadesFromText("./src/arcades.csv", arcadesList);
						upload = 1;
					}
					if (controller_generateGamesFile(arcadesList) != 1)
					{
						printf("\nOcurrio un error");
					}
					break;
				case 7:
					//controller_getArcadesFromText("./src/arcades.csv", arcadesList);
					if (upload != 1)
					{
						controller_getArcadesFromText("./src/arcades.csv", arcadesList);
						upload = 1;
					}
					if (controller_generateMultiplayerArcadesFile(arcadesList) != 1)
					{
						printf("\nOcurrio un error");
					}
					break;
				case 8:
					//controller_getArcadesFromText("./src/arcades.csv", arcadesList);
					if (upload != 1)
					{
						controller_getArcadesFromText("./src/arcades.csv", arcadesList);
						upload = 1;
					}
					if (controller_updateNumberOfCoins("./src/arcades.csv", arcadesList) != 1)
					{
						printf("\nOcurrio un error");
					}
					break;
				case 9:
					printf("\nFinalizando programa...");
					ll_deleteLinkedList(arcadesList);
			}
		}
		else
		{
			printf("\nError al elegir la opcion. Finalizando programa...");
			exit(0);
		}
	} while(selectedOption != 9);
	return 0;
}
