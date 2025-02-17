#pragma once
#include <Windows.h>
#include <string>

#include "Header.h"

using namespace System;
using namespace System::Drawing;

typedef struct _stRecursion
{
	int nIdStruct;
	double nValue1, nValue2;
	_stRecursion() : nIdStruct(0), nValue1(0), nValue2(0) {}
	_stRecursion(int pnId, double pVal1, double pVal2) :nIdStruct(pnId), nValue1(pVal1), nValue2(pVal2) {}
	void AddItem(int id, double value1, double value2)
	{
		nIdStruct = id; 
		nValue1 = value1;
		nValue2 = value2;
	}
}stRecursion, * pstRecursion;

static CURSORINFO pci;

float calc_func(float x, float a, int i, float summ, float step, pstRecursion pstRec);

//void Recursion();
void DrawAxisX(Graphics^ pgraph, RECT pArea, float pnMin, float pnMax, int pnSec = 10);
void DrawAxisY(Graphics^ pgraph, RECT pArea, float pnMin, float pnMax, int pnSec = 4);
void drawGraph(Graphics^ pgraph, pstRecursion pRec, int pnSizeRec, RECT pstRect);
void DrawTextRotate(Graphics^ pgraph, String^ ptext, System::Drawing::Rectangle prect, Font^ pfont, Brush^ pbrush, float angle);