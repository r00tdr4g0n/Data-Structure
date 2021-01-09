#include <stdio.h>
#include "Point.h"

void SetPointPos(Point* pPos, int xPos, int yPos)
{
	pPos->xPos = xPos;
	pPos->yPos = yPos;
}

void ShowPointPos(Point* pPos)
{
	printf("[%d, %d] \n", pPos->xPos, pPos->yPos);
}

int PointComp(Point* pPos1, Point* pPos2)
{
	if (pPos1->xPos == pPos2->xPos && pPos1->yPos == pPos2->yPos) {
		return 0;
	}
	else if (pPos1->xPos == pPos2->xPos) {
		return 1;
	}
	else if (pPos1->yPos == pPos2->yPos) {
		return 2;
	}
	else
		return -1;
}