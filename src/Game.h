/*
 * Game.h
 *
 *  Created on: 20 nov. 2021
 *      Author: leandro
 */

#ifndef SRC_GAME_H_
#define SRC_GAME_H_
struct Game
{
	char name[63];
	int isEmpty;
};
typedef struct Game Game;
int game_getList (LinkedList* arcadesList, Game gameList[]);
int game_printList (Game gameList[], int listLen);
int game_createFile(Game gameList[], int listLen);
#endif /* SRC_GAME_H_ */
