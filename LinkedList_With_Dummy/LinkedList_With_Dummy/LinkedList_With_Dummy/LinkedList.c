#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

void ListInit(List* pList) 
{
	pList->head = (Node*)malloc(sizeof(Node));
	pList->head->next = NULL;
	pList->cur = NULL;
	pList->before = NULL;
	pList->comp = NULL;
	pList->numOfData = 0;
}

void FInsert(List* pList, LData data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->next = pList->head->next;
	pList->head->next = newNode;

	(pList->numOfData)++;
}

void SInsert(List* pList, LData data)
{
	// To do
}

void LInsert(List* pList, LData data)
{
	if (pList->comp == NULL)
		FInsert(pList, data);
	else
		SInsert(pList, data);
}

int LFirst(List* pList, LData* pData)
{
	if (pList->head->next == NULL) 
		return FALSE;

	pList->before = pList->head;
	pList->cur = pList->head->next;

	*pData = pList->cur->data;

	return TRUE;
}

int LNext(List* pList, LData* pData)
{
	if(pList->cur->next == NULL)
		return FALSE;

	pList->before = pList->cur;
	pList->cur = pList->cur->next;

	*pData = pList->cur->data;

	return TRUE;
}

LData LRemove(List* pList)
{
	Node* rPos = pList->cur;
	LData rData = rPos->data;

	pList->before->next = pList->cur->next;
	pList->cur = pList->before;

	free(rPos);
	(pList->numOfData)--;

	return rData;
}

int LCount(List* pList)
{
	return pList->numOfData;
}

void SetSortRule(List* pList, int (*comp)(LData data1, LData data2))
{
	// To do
}