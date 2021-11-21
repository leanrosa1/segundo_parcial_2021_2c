/*
 * controller.h
 *
 *  Created on: 18 nov. 2021
 *      Author: leandro
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_
int controller_loadFromText(char* path , LinkedList* pArrayArcades);
int controller_addArcade(LinkedList* pArrayArcade, int maxId, char* pathId, char* pathData);
int controller_editArcade(LinkedList* pArrayArcades, char* pathData);
int controller_getArcadesFromText(char* path , LinkedList* pArrayArcades);
int controller_clearList(LinkedList* pArrayArcades);
int controller_deleteArcade(char* path , LinkedList* pArrayArcades);
int controller_printArcades(char* path , LinkedList* pArrayArcades);
int controller_generateGamesFile(LinkedList* pArrayArcades);
int controller_generateMultiplayerArcadesFile(LinkedList* pArrayArcades);
int controller_updateNumberOfCoins(char* path, LinkedList* pArrayArcades);
#endif /* CONTROLLER_H_ */
