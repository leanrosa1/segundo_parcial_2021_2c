/*
 * Game.c
 *
 *  Created on: 20 nov. 2021
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Arcade.h"
#include "Game.h"
#include "LinkedList.h"
#include "parser.h"

#define STR_LEN 64

//private prototypes
static void initGameList (Game gameList[], int listLen);
static int isThisGameInList (char gameName[], Game gameList[], int listLen);

int game_getList (LinkedList* arcadesList, Game gameList[])
{
	int status = -1;
	int index;
	int gameListIndex = 0;
	int listLen;
	Arcade* pArcade;

	if (arcadesList != NULL && gameList != NULL)
	{
		listLen = ll_len(arcadesList);

		initGameList(gameList, listLen);

		for (index = 0; index < listLen; index++)
		{
			pArcade = ll_get(arcadesList, index);

			if (pArcade != NULL)
			{
				if (isThisGameInList(pArcade->gameName, gameList, listLen) == -1)
				{
					strncpy(gameList[gameListIndex].name, pArcade->gameName, STR_LEN);
					gameList[gameListIndex].isEmpty = -1;
					gameListIndex++;
				}
			}
		}
		status = 1;
	}
	return status;
}

int game_printList (Game gameList[], int listLen)
{
	int status = -1;
	int index;

	if (gameList != NULL && listLen > 0)
	{
		if (gameList[0].isEmpty != 1)
		{
			status = 1;
			for (index = 0; index < listLen; index++)
			{
				if (gameList[index].isEmpty != 1)
				{
					printf("\n-------------------------------------------");
					printf("\nNOMBRE DE JUEGO: %s", gameList[index].name);
				}
				else
					break;
			}
		}
	}
	return status;
}

static void initGameList (Game gameList[], int listLen)
{
	int index;

	for (index = 0; index < listLen; index++)
	{
		gameList[index].isEmpty = 1;
	}
}

static int isThisGameInList (char gameName[], Game gameList[], int listLen)
{
	int wasFound = -1;
	int index;

	for (index = 0; index < listLen; index++)
	{
		if (gameList[index].isEmpty != 1)
		{
			if (strncmp(gameName, gameList[index].name, STR_LEN) == 0)
			{
				wasFound = 1;
				break;
			}
		}
	}
	return wasFound;
}

int game_createFile(Game gameList[], int listLen)
{
	int status = -1;
	FILE* file;

	if (gameList != NULL && listLen > 0)
	{
		file = fopen("games.txt", "w");
		if (parser_textFromGameList(gameList, listLen, file) == 1)
		{
			fclose(file);
			printf("\nArchivo generado correctamente");
		}
	}
	return status;
}
