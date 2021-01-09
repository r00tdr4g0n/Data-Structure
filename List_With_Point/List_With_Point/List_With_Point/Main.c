#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"

int main()
{
	List list;
	Point compPos;
	Point* pPos;

	ListInit(&list);

	pPos = (Point*)malloc(sizeof(Point));
	SetPointPos(pPos, 2, 1);
	LInsert(&list, pPos);

	pPos = (Point*)malloc(sizeof(Point));
	SetPointPos(pPos, 2, 2);
	LInsert(&list, pPos);

	pPos = (Point*)malloc(sizeof(Point));
	SetPointPos(pPos, 3, 1);
	LInsert(&list, pPos);

	pPos = (Point*)malloc(sizeof(Point));
	SetPointPos(pPos, 3, 2);
	LInsert(&list, pPos);

	printf("현재 데이터의 수 : %d \n", LCount(&list));

	if (LFirst(&list, &pPos)) {
		ShowPointPos(pPos);

		while (LNext(&list, &pPos)) {
			ShowPointPos(pPos);
		}
	}

	// xPos가 2인 모든 데이터 삭제
	compPos.xPos = 2;
	compPos.yPos = 0;

	if (LFirst(&list, &pPos)) {
		// 반환값이 1이면 x만 같은 경우
		if (PointComp(pPos, &compPos) == 1) {
			pPos = LRemove(&list);
			free(pPos);
		}

		while (LNext(&list, &pPos)) {
			if (PointComp(pPos, &compPos) == 1) {
				pPos = LRemove(&list);
				free(pPos);
			}
		}
	}

	return 0;
}