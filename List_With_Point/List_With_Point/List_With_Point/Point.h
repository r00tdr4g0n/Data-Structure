#pragma once

typedef struct _Point
{
	int xPos;
	int yPos;
}Point;

void SetPointPos(Point* pPos, int xPos, int yPos);
void ShowPointPos(Point* pPos);
int PointComp(Point* pPos1, Point* pPos2);