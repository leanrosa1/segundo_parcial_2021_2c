/*
 * idFactory.c
 *
 *  Created on: 10 nov. 2021
 *      Author: leandro
 */

#include <stdio.h>
#include <stdlib.h>

int idFactory_getMaximumId (char* idPath)
{
	int maximumId = 500;
	char auxId[16];

	FILE* pIdFile = fopen(idPath, "r");

	if (pIdFile != NULL)
	{
		fscanf(pIdFile, "%[^\n]\n", auxId);
		maximumId = atoi(auxId);
	}

	return maximumId;
}

int idFactory_getNewId (int maxId, char* path)
{
	int newId;
	FILE* idFile;

	newId = maxId + 1;
	idFile = fopen(path, "w");

	if (idFile != NULL)
	{
		fprintf(idFile, "%d", newId);
		fclose(idFile);
	}

	return newId;
}
