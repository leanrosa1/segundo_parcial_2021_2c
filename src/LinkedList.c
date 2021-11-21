#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"



static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
	LinkedList* this = (LinkedList*)malloc(sizeof(LinkedList));

	if (this != NULL)
	{
		this->size = 0;
		this->pFirstNode = NULL;
	}
	return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int size;

	if (this != NULL)
    {
		size = this->size;
    }
	else
	{
		size = -1;
	}
	return size;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int index;


	if (this != NULL && nodeIndex >= 0 && ll_len(this) > nodeIndex)
    {
		pNode = this->pFirstNode;

		for (index = 0; index < nodeIndex; index++)
		{
			pNode = pNode->pNextNode;
		}
    }
	return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
	int status = -1;
	Node* newNode;
	Node* auxNode;

	if (this != NULL && nodeIndex >= 0 && ll_len(this) >= nodeIndex)
	{

		newNode = (Node*)malloc(sizeof(Node));

		if (newNode != NULL)
		{
			if (nodeIndex == 0) //si es el primero
			{
				auxNode = this->pFirstNode;
				this->pFirstNode = newNode;
				newNode->pNextNode = auxNode;
			}
			else
			{
				auxNode = getNode(this, nodeIndex - 1);
				newNode->pNextNode = auxNode->pNextNode;
				auxNode->pNextNode = newNode;
			}
			this->size = this->size + 1;
			newNode->pElement = pElement;
			status = 0;
		}

	}
	return status;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int status = -1;
    int size;

    if (this != NULL)
    {
    	size = ll_len(this);
    	if (addNode(this, size, pElement) == 0)
    	{
    		status = 0;
    	}
    }

    return status;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;

    if (this != NULL && index >= 0 && ll_len(this) > index)
    {
    	auxNode = getNode(this, index);

    	if (auxNode != NULL)
    	{
    		returnAux = auxNode->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int status = -1;
    Node* auxNode;

    if (this != NULL && index >= 0 && ll_len(this) > index)
    {
    	auxNode = getNode(this, index);

    	if (auxNode != NULL)
    	{
    		auxNode->pElement = pElement;
    		status = 0;
    	}
    }
    return status;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int status = -1;
    Node* previousNode;
    Node* followingNode;
    Node* auxNode;

    if (this != NULL && index >= 0 && ll_len(this) > index)
    {

    	auxNode = getNode(this, index);

    	if (index == 0)
    	{
    		followingNode = getNode(this, index + 1);
    		this->pFirstNode = followingNode;
    	}
    	else
    	{
    		previousNode = getNode(this, index - 1);
    		previousNode->pNextNode = auxNode->pNextNode;
    	}

    	free(auxNode);
    	this->size--;
    	status = 0;
    }

    return status;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int status = -1;

    if (this != NULL)
    {
    	for (int index = 0; index < ll_len(this); index++)
    	{
    		ll_remove(this, index);
    	}
    	status = 0;
    }
    return status;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int status = -1;

    if (this != NULL)
    {
    	ll_clear(this);
    	free(this);
    	status = 0;
    }

    return status;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int foundIndex = -1;

    if (this != NULL)
    {
    	for (int index = 0; index < ll_len(this); index++)
    	{
    		if (ll_get(this, index) == pElement)
    		{
    			foundIndex = index;
    		}
    	}
    }

    return foundIndex;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int status = -1;
    int size;

    if (this != NULL)
    {
    	size = ll_len(this);

    	if (size == 0)
    	{
    		status = 1;
    	}
    	else
    	{
    		status = 0;
    	}
    }

    return status;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int status = -1;

    if (this != NULL && index >= 0 && index <= ll_len(this))
    {
    	addNode(this, index, pElement);
		status = 0;
    }

    return status;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* pElement = NULL;

    if (this != NULL)
    {
    	pElement = ll_get(this, index);
    	ll_remove(this, index);
    }

    return pElement;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int status = -1;
    void* auxElement;

    if (this != NULL)
    {
    	status = 0;

    	for (int index = 0; index < ll_len(this); index++)
    	{
    		auxElement = ll_get(this, index);

    		if (auxElement == pElement)
    		{
    			status = 1;
    		}
    	}
    }
    return status;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int status = -1;
    int counter = 0;
    void* auxElement;

    if (this != NULL && this2 != NULL)
    {

    	for (int index = 0; index < ll_len(this2); index++)
    	{
    		if (ll_len(this) > 0)
			{
    			auxElement = ll_get(this2, index);

    			if (ll_contains(this, auxElement) != 1)
    			{
    				break;
    			}
    			else
    			{
    				counter = counter + 1;
    			}
			}
    	}

    	if (counter == ll_len(this2) && counter != 0)
    	{
    		status = 1;
    	}
    	else
    		status = 0;
    }

    return status;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    void* pElement;

    if (this != NULL && from >= 0 && from < ll_len(this) && to > from && to <= ll_len(this))
    {
    	if (ll_len(this) > 0)
    	{
    		cloneArray = ll_newLinkedList();

    		for (int index = from; index < to; index++)
			{
				pElement = NULL;
				pElement = ll_get(this, index);

				if (pElement != NULL)
				{
					ll_add(cloneArray, pElement);
				}
				else
					break;
			}
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;

    if (this != NULL && ll_len(this) > 0)
    {
    	cloneArray = ll_subList(this, 0, ll_len(this));
    }

    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int status = -1;
	int hasChanges = 1;
	int index;
	int size;
	void* current;
	void* following;
	int orderResult;

	if (this != NULL && pFunc != NULL && (order == 0 || order == 1))
	{
		status = 0;
		size = ll_len(this);

		while (hasChanges)
		{
			hasChanges = 0;

			for (index = 0; index < size - 1; index ++)
			{
				current = ll_get(this, index);
				following = ll_get(this, index + 1);
				orderResult = pFunc(current, following);

				if ((order == 1 && orderResult == 1) || (order == 0 && orderResult == -1))
				{
					ll_set(this, index, following);
					ll_set(this, index + 1, current);
					hasChanges = 1;
				}
			}
		}
	}

	return status;
}

int ll_map(LinkedList* this, void (*pFunc)(void*))
{
	int status = -1;
	int size;
	int index;
	void* pAux;

	if (this != NULL && pFunc != NULL)
	{
		status = 1;
		size = ll_len(this);

		for (index = 0; index < size; index++)
		{
			pAux = ll_get(this, index);

			if (pAux != NULL)
			{
				pFunc(pAux);
			}
		}
	}
	return status;
}


int ll_filter(LinkedList* this, int (*pFunc)(void*))
{
	int status = -1;
	int critery;
	void* pAux;
	int index;

	if(this != NULL && pFunc != NULL)
	{
		for(index = ll_len(this)-1; index >= 0; index--)
		{
			pAux = ll_get(this, index);

			if(pAux != NULL)
			{
				critery = pFunc(pAux);
				if(critery == 0)
				{
					status = ll_remove(this, index);
				}
			}
		}
	}
	return status;
}


