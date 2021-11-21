/*
 * menu.h
 *
 *  Created on: 6 nov. 2021
 *      Author: leandro
 */

#ifndef MENU_H_
#define MENU_H_

void menu_printMainMenu (void);
void menu_printEditMenu (void);
int menu_selectAnOption (int* selectedOption, int minValue, int maxValue);

#endif /* MENU_H_ */
