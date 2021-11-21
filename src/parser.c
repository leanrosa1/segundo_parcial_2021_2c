#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Arcade.h"
#include "Game.h"

#define NAME_LEN 128

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayArcade)
{

	int status = -1;
	Arcade* auxArcade;
	char id[16];
	char country[64];
	char soundType[16];
	char numberOfPlayers[16];
	char numberOfCoins[16];
	char playroomName[64];
	char gameName[64];

	if (pFile != NULL && pArrayArcade != NULL)
	{
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, country, soundType, numberOfPlayers, numberOfCoins, playroomName, gameName);

		do
		{
			status = 1;

			if (fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, country, soundType, numberOfPlayers, numberOfCoins, playroomName, gameName) == 7)
			{
				auxArcade = arcade_newParams(id, country, soundType, numberOfPlayers, numberOfCoins, playroomName, gameName);
				if (auxArcade != NULL)
				{
					ll_add(pArrayArcade, auxArcade);
				}
			}
			else
			{
				arcade_delete(auxArcade);
				break;
			}
		} while (feof(pFile) == 0);
	}
	return status;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */


int parser_TextFromArcade (FILE* pFile , Arcade* pArcade)
{
	int status = -1;
	int id;
	char country[64];
	char soundType[64];
	int numberOfPlayers;
	int numberOfCoins;
	char playroomName[64];
	char gameName[64];

	if (pFile != NULL && pArcade != NULL)
	{
		status = 1;
		//no lo necesito porque voy a hacer append (a);
			//fprintf(pFile, "id,nombre,horasTrabajadas,sueldo\n");

		arcade_getId(pArcade, &id);
		arcade_getCountry(pArcade, country);
		arcade_getSoundType(pArcade, soundType);
		arcade_getNumberOfPlayers(pArcade, &numberOfPlayers);
		arcade_getNumberOfCoins(pArcade, &numberOfCoins);
		arcade_getPlayroomName(pArcade, playroomName);
		arcade_getGameName(pArcade, gameName);

		fprintf(pFile, "%d,%s,%s,%d,%d,%s,%s\n", id, country, soundType, numberOfPlayers, numberOfCoins, playroomName, gameName);
	}
	return status;
}

int parser_TextFromListOfArcades (FILE* pFile , LinkedList* pArrayArcades)
{
	Arcade* auxArcade;
	int status = -1;
	int listLen;
	int index;
	int id;
	char country[64];
	char soundType[64];
	int numberOfPlayers;
	int numberOfCoins;
	char playroomName[64];
	char gameName[64];

	if (pFile != NULL && pArrayArcades != NULL)
	{
		listLen = ll_len(pArrayArcades);
		status = 1;
		fprintf(pFile, "id,nacionalidad,tipo_sonido,cant_jug,fichas_max,salon,game\n");

		for (index = 0; index < listLen; index++)
		{
			auxArcade = ll_get(pArrayArcades, index);

			if (auxArcade != NULL)
			{
				arcade_getId(auxArcade, &id);
				arcade_getCountry(auxArcade, country);
				arcade_getSoundType(auxArcade, soundType);
				arcade_getNumberOfPlayers(auxArcade, &numberOfPlayers);
				arcade_getNumberOfCoins(auxArcade, &numberOfCoins);
				arcade_getPlayroomName(auxArcade, playroomName);
				arcade_getGameName(auxArcade, gameName);

				fprintf(pFile, "%d,%s,%s,%d,%d,%s,%s\n", id, country, soundType, numberOfPlayers, numberOfCoins, playroomName, gameName);
			}
		}
	}
	return status;
}

int parser_textFromGameList(Game gameList[],int listLen, FILE* pFile)
{
	int status = -1;
	int index;

	if (gameList != NULL && pFile != NULL && listLen > 0)
	{
		fprintf(pFile, "juegos registrados\n");

		for (index = 0; index < listLen; index++)
		{
			if (gameList[index].isEmpty != 1)
			{
				fprintf(pFile, "%s\n", gameList[index].name);
			}
		}
		status = 1;
	}

	return status;
}

