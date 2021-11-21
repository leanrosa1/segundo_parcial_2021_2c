/*
 * Arcade.c
 *
 *  Created on: 17 nov. 2021
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arcade.h"
#include "myStr.h"
#include "LinkedList.h"
#include "parser.h"

#define STR_LEN 64

//private prototypes
static int validateId (int id);

Arcade* arcade_new (void)
{
	Arcade* pArcade = malloc(sizeof(Arcade));
	return pArcade;
}

Arcade* arcade_newParams (char idStr[], char country[], char soundStr[], char players[], char coins[], char playroom[], char game[])
{
	Arcade* pArcade = arcade_new();
	int internalStatus;
	int id;
	int numberOfPlayers;
	int numberOfCoins;

	if (myStrIsOnlyNumbers(idStr, &internalStatus) == 1)
	{
		id = atoi(idStr);
		if (validateId(id) == 1)
		{
			if (myStrIsOnlyText(country, &internalStatus) == 1)
			{
				if (myStrIsOnlyNumbers(players, &internalStatus) == 1)
				{
					numberOfPlayers = atoi(players);
					if (myStrIsOnlyNumbers(coins, &internalStatus) == 1)
					{
						numberOfCoins = atoi(coins);

						arcade_setId(pArcade, id);
						arcade_setCountry(pArcade, country);
						arcade_setSoundType(pArcade, soundStr);
						arcade_setNumberOfPlayers(pArcade, numberOfPlayers);
						arcade_setNumberOfCoins(pArcade, numberOfCoins);
						arcade_setPlayroomName(pArcade, playroom);
						arcade_setGameName(pArcade, game);
					}
				}
			}
		}
	}

	return pArcade;
}

static int validateId (int id)
{
	int status = -1;

	if (id > 0)
	{
		status = 1;
	}

	return status;
}

int arcade_setId(Arcade* this, int id)
{
	int status = -1;

	if (this != NULL)
	{
		this->id = id;
		status = 1;
	}
	return status;
}

int arcade_getId(Arcade* this, int* id)
{
	int status = -1;

	if (this != NULL)
	{
		*id = this->id;
		status = 1;
	}
	return status;
}

int arcade_setCountry(Arcade* this, char country[])
{
	int status = -1;

	if (this != NULL)
	{
		strncpy(this->country, country, STR_LEN);
		status = 1;
	}
	return status;
}

int arcade_getCountry(Arcade* this,char country[])
{
	int status = -1;

	if (this != NULL)
	{
		strncpy(country, this->country, STR_LEN);
		status = 1;
	}
	return status;
}

int arcade_setSoundType(Arcade* this, char soundType[])
{
	int status = -1;

	if (this != NULL)
	{
		strncpy(this->soundType, soundType, STR_LEN);
		status = 1;
	}
	return status;
}

int arcade_getSoundType(Arcade* this, char soundType[])
{
	int status = -1;

	if (this != NULL)
	{
		strncpy(soundType, this->soundType, STR_LEN);
		soundType= this->soundType;
		status = 1;
	}
	return status;
}

int arcade_setNumberOfPlayers(Arcade* this, int players)
{
	int status = -1;

	if (this != NULL)
	{
		this->numberOfPlayers = players;
		status = 1;
	}
	return status;
}

int arcade_getNumberOfPlayers(Arcade* this, int* players)
{
	int status = -1;

	if (this != NULL)
	{
		*players = this->numberOfPlayers;
		status = 1;
	}
	return status;
}

int arcade_setNumberOfCoins(Arcade* this, int coins)
{
	int status = -1;

	if (this != NULL)
	{
		this->numberOfCoins = coins;
		status = 1;
	}
	return status;
}

int arcade_getNumberOfCoins(Arcade* this, int* coins)
{
	int status = -1;

	if (this != NULL)
	{
		*coins = this->numberOfCoins;
		status = 1;
	}
	return status;
}

int arcade_setPlayroomName(Arcade* this, char playroom[])
{
	int status = -1;

	if (this != NULL)
	{
		strncpy(this->playroomName, playroom, STR_LEN);
		status = 1;
	}
	return status;
}

int arcade_getPlayroomName(Arcade* this,char playroom[])
{
	int status = -1;

	if (this != NULL)
	{
		strncpy(playroom, this->playroomName, STR_LEN);
		status = 1;
	}
	return status;
}

int arcade_setGameName(Arcade* this, char game[])
{
	int status = -1;

	if (this != NULL)
	{
		strncpy(this->gameName, game, STR_LEN);
		status = 1;
	}
	return status;
}

int arcade_getGameName(Arcade* this,char game[])
{
	int status = -1;

	if (this != NULL)
	{
		strncpy(game, this->gameName, STR_LEN);
		status = 1;
	}
	return status;
}

void arcade_delete(Arcade* this)
{
	if (this != NULL)
	{
		free(this);
	}
}

void arcade_printList(LinkedList* pArrayArcades)
{
	int listLen;
	int index;
	Arcade* pArcade;
	int id;
	char country[64];
	char soundType[64];
	int numberOfPlayers;
	int numberOfCoins;
	char playroomName[64];
	char gameName[64];

	listLen = ll_len(pArrayArcades);

	for (index = 0; index < listLen; index++)
	{
		pArcade = ll_get(pArrayArcades, index);

		if (pArcade != NULL)
		{
			arcade_getId(pArcade, &id);
			arcade_getCountry(pArcade, country);
			arcade_getSoundType(pArcade, soundType);
			arcade_getNumberOfPlayers(pArcade, &numberOfPlayers);
			arcade_getNumberOfCoins(pArcade, &numberOfCoins);
			arcade_getPlayroomName(pArcade, playroomName);
			arcade_getGameName(pArcade, gameName);

			printf("\n---------------ARCADE---------------");
			printf("\nID: %d", id);
			printf("\nPAIS: %s", country);
			printf("\nTIPO DE SONIDO: %s", soundType);
			printf("\nCANTIDAD DE JUGADORES: %d", numberOfPlayers);
			printf("\nCANTIDAD DE FICHAS: %d", numberOfCoins);
			printf("\nSALON: %s", playroomName);
			printf("\nJUEGOS: %s", gameName);
			printf("\n--------------------------------------");
		}
	}
}

int arcade_findById(LinkedList* listOfArcades, int id)
{
	int foundPosition = -1;
	int listIndex;
	int listLen;
	int idToCompare;
	Arcade* pArcade;

	if (listOfArcades != NULL && id > 0)
	{
		listLen = ll_len(listOfArcades);

		for (listIndex = 0; listIndex < listLen; listIndex++)
		{
			pArcade = ll_get(listOfArcades, listIndex);

			if (arcade_getId(pArcade, &idToCompare) == 1)
			{
				if (idToCompare == id)
				{
					foundPosition = listIndex;
					break;
				}
			}
		}
	}
	return foundPosition;
}

void arcade_print(Arcade* pArcade)
{
	int id;
	char country[64];
	char soundType[64];
	int numberOfPlayers;
	int numberOfCoins;
	char playroomName[64];
	char gameName[64];

	if (pArcade != NULL)
	{
		arcade_getId(pArcade, &id);
		arcade_getCountry(pArcade, country);
		arcade_getSoundType(pArcade, soundType);
		arcade_getNumberOfPlayers(pArcade, &numberOfPlayers);
		arcade_getNumberOfCoins(pArcade, &numberOfCoins);
		arcade_getPlayroomName(pArcade, playroomName);
		arcade_getGameName(pArcade, gameName);

		printf("\n---------------ARCADE---------------");
		printf("\nID: %d", id);
		printf("\nPAIS: %s", country);
		printf("\nTIPO DE SONIDO: %s", soundType);
		printf("\nCANTIDAD DE JUGADORES: %d", numberOfPlayers);
		printf("\nCANTIDAD DE FICHAS: %d", numberOfCoins);
		printf("\nSALON: %s", playroomName);
		printf("\nJUEGOS: %s", gameName);
		printf("\n--------------------------------------");
	}
	else
		printf("\nNo existe el arcade");
}

int arcade_getMultiplayerArcades(LinkedList* listOfMultiplayerArcades)
{
	int status = -1;
	FILE* file;

	if (listOfMultiplayerArcades != NULL)
	{
		file = fopen("multijugador.csv", "w");
		if (parser_TextFromListOfArcades(file, listOfMultiplayerArcades) == 1)
		{
			fclose(file);
			status = 1;
			printf("\nArchivo generado correctamente");
		}
	}


	return status;
}

