/*
 * idFactory.h
 *
 *  Created on: 10 nov. 2021
 *      Author: leandro
 */

#ifndef IDFACTORY_H_
#define IDFACTORY_H_
int idFactory_getMaximumId (char* idPath);
int idFactory_getNewId (int maxId, char* path);
#endif /* IDFACTORY_H_ */
