#include "ArrayList.h"

void ListInit(List* plist)
{
	plist->numOfData = 0;
	plist->curPosition = -1;
}

void LInsert(List* plist, LData data)
{
	// 배열의 길이를 초과했는지 검사
	if (plist->numOfData >= LIST_LEN) {
		printf("저장이 불가능합니다.");

		return;
	}

	// 데이터 저장 후, 데이터의 수를 나타내는 numOfData 값 증가
	plist->arr[plist->numOfData] = data;
	(plist->numOfData)++;
}

int LFirst(List* plist, LData* pdata)
{
	// 저장된 데이터가 존재하는지 검사
	if (plist->numOfData == 0) {
		return FALSE;
	}

	plist->curPosition = 0;
	*pdata = plist->arr[0];

	return TRUE;
}

int LNext(List* plist, LData* pdata)
{
	if (plist->curPosition >= (plist->numOfData) - 1) {
		return FALSE;
	}

	(plist->curPosition)++;
	*pdata = plist->arr[plist->curPosition];

	return TRUE;
}

LData LRemove(List* plist) {
	int rpos = plist->curPosition;
	int num = plist->numOfData;
	int i;
	LData rdata = plist->arr[rpos];

	for (i = rpos; i < num - 1; i++) {
		plist->arr[i] = plist->arr[i + 1];
	}

	(plist->numOfData)--;
	(plist->curPosition)--;

	return rdata;
}

int LCount(List* plist) 
{
	return plist->numOfData;
}