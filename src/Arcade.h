/*
 * Arcade.h
 *
 *  Created on: 17 nov. 2021
 *      Author: leandro
 */

#ifndef ARCADE_H_
#define ARCADE_H_
#include "LinkedList.h"
struct Arcade
{
    int id;
    char country[64];
    char soundType[64];
    int numberOfPlayers;
    int numberOfCoins;
    char playroomName[64];
    char gameName[64];
}typedef Arcade;

Arcade* arcade_new (void);
Arcade* arcade_newParams (char idStr[], char country[], char soundStr[], char players[], char coins[], char playroom[], char game[]);
int arcade_setId(Arcade* this, int id);
int arcade_getId(Arcade* this, int* id);
int arcade_setCountry(Arcade* this, char country[]);
int arcade_getCountry(Arcade* this,char country[]);
int arcade_setSoundType(Arcade* this, char soundType[]);
int arcade_getSoundType(Arcade* this, char soundType[]);
int arcade_setNumberOfPlayers(Arcade* this, int players);
int arcade_getNumberOfPlayers(Arcade* this, int* players);
int arcade_setNumberOfCoins(Arcade* this, int coins);
int arcade_getNumberOfCoins(Arcade* this, int* coins);
int arcade_setPlayroomName(Arcade* this, char playroom[]);
int arcade_getPlayroomName(Arcade* this,char playroom[]);
int arcade_setGameName(Arcade* this, char game[]);
int arcade_getGameName(Arcade* this,char game[]);
void arcade_delete(Arcade* this);
void arcade_printList(LinkedList* pArrayArcades);
int arcade_findById(LinkedList* listOfArcades, int id);
void arcade_print(Arcade* pArcade);
int arcade_getMultiplayerArcades(LinkedList* listOfMultiplayerArcades);
#endif /* ARCADE_H_ */
