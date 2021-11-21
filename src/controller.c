/*
 * controller.c
 *
 *  Created on: 18 nov. 2021
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "parser.h"
#include "input.h"
#include "menu.h"
#include "idFactory.h"
#include "Game.h"

#define STR_LEN 64

//private prototypes
static Arcade* selectArcade(LinkedList* pArrayArcades);

//func pointers
int sortByName(void*, void*);
int filterByMultiplayer(void*);
void doubleNumberOfCoins(void*);

int controller_loadFromText(char* path , LinkedList* pArrayArcades)
{
	int status = -1;
	FILE* file;

	file = fopen(path, "r");

	if (parser_ArcadeFromText(file, pArrayArcades) == 1)
	{
		fclose(file);
		arcade_printList(pArrayArcades);
		status = 1;
	}
	return status;
}

int controller_addArcade(LinkedList* pArrayArcade, int maxId, char* pathId, char* pathData)
{
	int status = -1;
	Arcade* pArcade;
	int id;
	char country[64];
	int auxSound;
	char soundType[64];
	int numberOfPlayers;
	int numberOfCoins;
	char playroomName[64];
	char gameName[64];
	FILE* file;

	if (pArrayArcade != NULL)
	{
		pArcade = arcade_new();

		if (pArcade != NULL)
		{
			if (input_getText(country, STR_LEN, 2, "Ingrese el pais", "Error") == 1)
			{
				if (input_getInt(1, 2, 2, "Ingrese tipo de sonido (1. STEREO || 2.MONO)", &auxSound, "Error") == 1)
				{
					if (input_getInt(1, 4, 2, "Ingrese cantidad de jugadores (entre 1 y 4)", &numberOfPlayers, "Error") == 1)
					{
						if (input_getInt(1, 1000, 2, "Ingrese cantidad de fichas (entre 1 y 1000)", &numberOfCoins, "Error") == 1)
						{
							if (input_getText(playroomName, STR_LEN, 2, "Ingrese el salon", "Error") == 1)
							{
								if (input_getText(gameName, STR_LEN, 2, "Ingrese el juego", "Error") == 1)
								{
									printf("\nDatos ingresados correctamente");

									id = idFactory_getNewId(maxId, pathId);
									arcade_setId(pArcade, id);
									arcade_setCountry(pArcade, country);
									if (auxSound == 1)
									{
										strncpy(soundType, "STEREO", STR_LEN);
									}
									else
									{
										strncpy(soundType, "MONO", STR_LEN);
									}
									arcade_setSoundType(pArcade, soundType);
									arcade_setNumberOfPlayers(pArcade, numberOfPlayers);
									arcade_setNumberOfCoins(pArcade, numberOfCoins);
									arcade_setPlayroomName(pArcade, playroomName);
									arcade_setGameName(pArcade, gameName);

									//ll_add(pArrayArcade, pArcade);
									file = fopen(pathData, "a");
									if (parser_TextFromArcade(file, pArcade) == 1)
									{
										fclose(file);
										printf("\nGuardado en base de datos correctamente");
										status = 1;
									}

								}
							}
						}

					}
				}
			}
		}
	}
    return status;
}

int controller_editArcade(LinkedList* pArrayArcades, char* pathData)
{
    int status = -1;
    int selectedOption;
    char game[STR_LEN];
	int players;
    Arcade* pArcade;
    FILE* file;
    int gameListLen = ll_len(pArrayArcades);
	Game gameList[gameListLen];

    if (pArrayArcades != NULL)
    {
    	pArcade = selectArcade(pArrayArcades);

    	if (pArcade != NULL)
    	{
    		printf("\nEl arcade seleccionado tiene id %d", pArcade->id);
    		menu_printEditMenu();
    		if (input_getInt(1, 2, 2, "Elija la opcion", &selectedOption, "Error") == 1)
			{
				switch (selectedOption)
				{
					case 1:
						if (input_getInt(1, 4, 2, "Ingrese cantidad de jugadores (entre 1 y 4)", &players, "Error") == 1)
						{
							printf("\nEl numero de jugadores ingresado fue %d", players);
							arcade_setNumberOfPlayers(pArcade, players);
							file = fopen(pathData, "w");
							if (parser_TextFromListOfArcades(file, pArrayArcades) == 1)
							{
								fclose(file);
								printf("\nGuardado en base de datos correctamente");
								status = 1;
							}
						}
						break;
					case 2:
						if (game_getList(pArrayArcades, gameList) == 1)
						{
							printf("\nLos juegos actualmente cargados son:");
							game_printList(gameList, gameListLen);
							if (input_getText(game, STR_LEN, 2, "Ingrese el juego", "Error") == 1)
							{
								arcade_setGameName(pArcade, game);
								file = fopen(pathData, "w");
								if (parser_TextFromListOfArcades(file, pArrayArcades) == 1)
								{
									fclose(file);
									printf("\nGuardado en base de datos correctamente");
									status = 1;
								}
							}
						}
						break;
				}
				printf("\nArcade modificado correctamente");
				status = 1;
			}
    		else
    			printf("\nError al seleccionar opcion a modificar");
    	}
    	else
    		printf("\nEl arcade con id indicado no existe");
    }
    return status;
}

static Arcade* selectArcade(LinkedList* pArrayArcades)
{
	int id;
	int index;
	Arcade* pArcade;

	if (pArrayArcades != NULL)
	{
		arcade_printList(pArrayArcades);
		if (input_getInt(1, 9999999, 2, "Ingrese el ID del arcade", &id, "Error") == 1)
		{
			index = arcade_findById(pArrayArcades, id);
			if (index != -1)
			{
				pArcade = ll_get(pArrayArcades, index);
			}
		}
	}
	return pArcade;
}

int controller_getArcadesFromText(char* path , LinkedList* pArrayArcades)
{
	int status = -1;
	FILE* file;

	file = fopen(path, "r");

	if (parser_ArcadeFromText(file, pArrayArcades) == 1)
	{
		fclose(file);
		status = 1;
	}
	return status;
}

int controller_clearList(LinkedList* pArrayArcades)
{
	int status = -1;
	ll_clear(pArrayArcades);

	return status;
}

int controller_deleteArcade(char* path , LinkedList* pArrayArcades)
{
	int status = -1;
	Arcade* pArcade;
	int id;
	int selectedOption;
	int index;
	Arcade* auxArcade;
	int auxId;
	FILE* file;

	if (pArrayArcades != NULL)
	{
		pArcade = selectArcade(pArrayArcades);


		if (pArcade != NULL)
		{
			arcade_print(pArcade);
			if (input_getInt(0, 1, 2, "¿Desea eliminar este arcade? 0.NO || 1.SI", &selectedOption, "Error") == 1)
			{
				status = 1;
				if (selectedOption == 1)
				{
					arcade_getId(pArcade, &id);

					for (index = 0; index < ll_len(pArrayArcades); index++)
					{
						auxArcade = ll_get(pArrayArcades, index);
						arcade_getId(auxArcade, &auxId);

						if ( auxId == id)
						{
							printf("\nLLega a matchear un id");

							if (ll_remove(pArrayArcades, index) == 0)
							{
								printf("\nArcade eliminado correctamente de la ll");
							}
							file = fopen(path, "w");
							if (parser_TextFromListOfArcades(file, pArrayArcades) == 1)
							{
								fclose(file);
								printf("\nGuardado en base de datos correctamente");
							}
							break;
						}
					}
				}
			}
			else
				printf("\nError al elegir opcion");
		}
		else
		{
			printf("\nEl id ingresado no corresponde con un arcade");
		}
	}

	return status;
}

int sortByName(void* a, void* b)
{
	int value = 0;
	int comparisonValue;
	Arcade* arcadeOne;
	Arcade* arcadeTwo;

	arcadeOne = (Arcade*)a;
	arcadeTwo = (Arcade*)b;
	comparisonValue = strcmp(arcadeOne->gameName, arcadeTwo->gameName);

	if (comparisonValue > 0)
	{
		value = 1;
	}
	else if (comparisonValue < 0)
	{
		value = -1;
	}
	return value;
}

int filterByMultiplayer(void* a)
{
	int value = 0;
	Arcade* arcade;
	arcade = (Arcade*)a;
	int numberOfPlayers;

	arcade_getNumberOfPlayers(arcade, &numberOfPlayers);
	if(numberOfPlayers > 1)
	{
		value = 1;
	}
	return value;
}

void doubleNumberOfCoins(void* a)
{
	Arcade* arcade;
	arcade = (Arcade*)a;
	int currentNumberOfCoins;
	arcade_getNumberOfCoins(arcade, &currentNumberOfCoins);
	arcade_setNumberOfCoins(arcade, currentNumberOfCoins * 2);
}

int controller_printArcades(char* path , LinkedList* pArrayArcades)
{
	int status = -1;
	LinkedList* aux;

	if (path != NULL && pArrayArcades != NULL)
	{
		aux = ll_clone(pArrayArcades);

		if (ll_sort(aux, sortByName, 0) == 0)
		{
			arcade_printList(aux);
			status = 1;
		}
	}

	return status;
}

int controller_generateGamesFile(LinkedList* pArrayArcades)
{
	int status = -1;
	int gameListLen = ll_len(pArrayArcades);
	Game gameList[gameListLen];

	if (pArrayArcades != NULL)
	{
		if (game_getList(pArrayArcades, gameList) == 1)
		{
			printf("\nJuegos cargados en el array");
			game_createFile(gameList, gameListLen);
			status = 1;
		}
	}

	return status;
}

int controller_generateMultiplayerArcadesFile(LinkedList* pArrayArcades)
{
	int status = -1;
	LinkedList* aux;

	aux = ll_clone(pArrayArcades);

	if (pArrayArcades != NULL)
	{
		if (ll_filter(aux, filterByMultiplayer) != 1)
		{
			if (arcade_getMultiplayerArcades(aux) == 1)
			{
				status = 1;
			}
		}
	}
	return status;
}

int controller_updateNumberOfCoins(char* path, LinkedList* pArrayArcades)
{
	int status = -1;
	FILE* file;

	if (pArrayArcades != NULL && path != NULL)
	{
		if (ll_map(pArrayArcades, doubleNumberOfCoins) == 1)
		{
			file = fopen(path, "w");
			if (parser_TextFromListOfArcades(file, pArrayArcades) == 1)
			{
				status = 1;
				printf("\nupdate ok");
			}
		}
	}
	return status;
}
