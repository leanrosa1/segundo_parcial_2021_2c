#ifndef PARSER_H_
#define PARSER_H_
#include "Arcade.h"
#include "Game.h"
int parser_TextFromArcade (FILE* pFile , Arcade* pArcade);
int parser_ArcadeFromText(FILE* pFile , LinkedList* pArrayArcade);
int parser_TextFromListOfArcades (FILE* pFile , LinkedList* pArrayArcades);
int parser_textFromGameList(Game gameList[],int listLen, FILE* pFile);
#endif
