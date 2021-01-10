#pragma once

#define TRUE 1
#define FALSE 0

typedef int LData;

typedef struct _Node
{
	LData data;
	struct _Node* next;

}Node;

typedef struct _LinkedList
{
	Node* head;
	Node* cur;
	Node* before;
	int numOfData;
	int (*comp)(LData data1, LData data2);
}LinkedList;

typedef LinkedList List;

void ListInit(List* pList);
void LInsert(List* pList, LData data);
int LFirst(List* pList, LData* pData);
int LNext(List* pList, LData* pData);
LData LRemove(List* pList);
int LCount(List* pList);
void SetSortRule(List* pList, int (*comp)(LData data1, LData data2));
