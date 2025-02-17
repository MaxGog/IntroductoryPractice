#include "Maze.h"

using namespace System::Drawing;

const int sizeMaze = 32, nL = 32, nC = 32;

UINT map[sizeMaze] = { 0xFEFFFFFF, 0xC0FE000F, 0xDE00FFEF, 0xDFEFEF0F, 0xC00FEFEF, 0xFFFE000F,
	0x87FEF6FF, 0xF0FEF0FF, 0xF6FEFEFF, 0xE600FE0F, 0xEEFFFFEF, 0xE0FE000F, 0xF7FFEEFF, 0xF7000EFF,
	0xF7EFEEFF, 0xF7EFFE0F, 0xF00FFFFF, 0xFEFFF0FF, 0xFE0007FF, 0xFFEFEFFF, 0xFFEF0FFF, 0xF00F7FFF,
	0xF7FF000F, 0xF0007FEF, 0xFFFFFF0F, 0xFFFFFFEF, 0xFFFF000F, 0xFFFF7FFF, 0xFF000FFF, 0xFFEFFFFF,
	0xFF0FFFFF, 0xFFEFFFFF }, * nMoving = 0, * nPath = 0;
UINT nbit = 0b1000'0000'0000'0000'0000'0000'0000'0000;

MyColors nCLRS = CL_BLUE, nCLRE = CL_LIGHT_PURPLE, nPlayer = CL_RED;
UINT nStartRow = 0, nStartColumn = 7;
UINT nEndRow = 31, nEndColumn = 11;

UINT nRow = nStartRow + 1, nColumn = nStartColumn;

int nWBlock = 16, nHBlock = 16, nLC = 10, nTC = 200;

UINT nCash = 0;
COORD position;

void ResetMaze()
{
	nCLRS = CL_BLUE;
	nCLRE = CL_LIGHT_PURPLE;
	nPlayer = CL_RED;
	UINT nStartRow = 0;
	nStartColumn = 7;
	UINT nEndRow = 31;
	nEndColumn = 11;

	nRow = nStartRow + 1;
	nColumn = nStartColumn;

	nWBlock = 16;
	nHBlock = 16;
	nLC = 10;
	nTC = 200;

	nCash = 0;
}

MyAction MazeDraw(System::Drawing::Graphics^ graph)
{
	UINT vv = 0b111111110000000011111111000000000;
	unsigned char sKey = 0;
	char* sTitle = 0;

	UINT i, j, nWidChar = 0, nHeiChar = 0;

	//HDC hdc = 0;

	//Font* fnt = new Font();

	System::Drawing::Rectangle rc(nLC, nTC, nWBlock * nL, nHBlock * nC);
	System::Drawing::Rectangle rcBlock(0, 0, nWBlock, nHBlock);
	System::Drawing::Color clr = System::Drawing::Color::FromArgb(255, 192, 192, 192);
	Color clrIO = Color::FromArgb(0);
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(clr);
	graph->FillRectangle(brush, rc);

	//SetConsoleTitle(L"Программа лабиринт");
	//textboxTitle->Text = "Прохождение лабиринта.";
	//hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	//system("cls");

	rcBlock.Width = nWBlock;
	rcBlock.Height = nHBlock;

	for (i = 0; i < nL; i++)
	{
		rcBlock.Y = nTC + i * nHBlock;
		for (j = 0; j < nC; j++ )
		{
			rcBlock.X = nLC + nWBlock * j;
			//if (map[i] & (bit >> j))
			//{
			//	brush->Color = clrIO;
			//	graph->FillRectangle(brush, rcBlock);
			//}
			if ((i == nRow) && (j == nColumn))
			{
				brush->Color = Color::Blue;
				graph->FillRectangle(brush, rcBlock);
			}
			else if ((i == nStartRow) && (j == nStartColumn) || (i == nEndRow) && (j == nEndColumn))
			{
				brush->Color = Color::Red;
				graph->FillRectangle(brush, rcBlock);
			}
			else if (!(map[i] & (nbit >> j)))
			{
				if ((nPath != 0) && (nPath[i] & (nbit >> j)))
					brush->Color = Color::Yellow;
				else
					brush->Color = Color::Black;
				graph->FillRectangle(brush, rcBlock);
			}
		}
	}
	if ((nRow == nEndRow) && (nColumn == nEndColumn)) return act_MAZEEXIT; else return act_MAZE;
}

void MazeKeys(int pkey)
{
	switch (pkey)
	{
	case 38: if ((nRow == 0) || (map[nRow - 1] & (nbit >> nColumn))) { Beep(750, 300); }
		   else nRow--; break;
	case 37: if ((nColumn == 0) || (map[nRow] & (nbit >> nColumn - 1))) { Beep(750, 300); }
		   else nColumn--; break;
	case 39: if (((nColumn + 1) == sizeMaze) || (map[nRow] & (nbit >> (nColumn + 1)))) { Beep(750, 300); }
		   else nColumn++; break;
	case 40: if (((nRow + 1) == sizeMaze) || (map[nRow + 1] & (nbit >> nColumn))) { Beep(750, 300); }
		   else nRow++; break;
	}
}

int Moving(char pnRow, char pnCol, System::Drawing::Graphics^ graph, const BOOL pKey)
{
	int nRes = 0;
	System::Drawing::Rectangle rcBlock(0, 0, nWBlock, nHBlock);
	System::Drawing::Color clr = System::Drawing::Color::Yellow;
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(clr);

	rcBlock.Y = nTC + pnRow * nHBlock;
	rcBlock.X = nLC + nWBlock * pnCol;

	graph->FillRectangle(brush, rcBlock);

	nMoving[pnRow] |= nbit >> pnCol;
	nPath[pnRow] |= nbit >> pnCol;

	if ((pnRow == nEndRow) && (pnCol == nEndColumn)) return 99;

	if (pnRow - 1 >= 0)
		if (!(map[pnRow - 1] & (nbit >> pnCol)) && !((nMoving[pnRow - 1] & (nbit >> pnCol))))
		{
			nRes = Moving(pnRow - 1, pnCol, graph, pKey);
			if (nRes) { return nRes; }
		}

	if (pnCol - 1 >= 0)
		if (!(map[pnRow] & (nbit >> pnCol - 1)) && !((nMoving[pnRow] & (nbit >> pnCol - 1))))
		{
			nRes = Moving(pnRow, pnCol - 1, graph, pKey);
			if (nRes) { return nRes; }
		}

	if (pnCol + 1 <= nC)
		if (!(map[pnRow] & (nbit >> pnCol + 1)) && !((nMoving[pnRow] & (nbit >> pnCol + 1))))
		{
			nRes = Moving(pnRow, pnCol + 1, graph, pKey);
			if (nRes) { return nRes; }
		}

	if (pnRow + 1 <= nL)
		if (!(map[pnRow + 1] & (nbit >> pnCol)) && !((nMoving[pnRow + 1] & (nbit >> pnCol))))
		{
			nRes = Moving(pnRow + 1, pnCol, graph, pKey);
			if (nRes) { return nRes; }
		}

	brush->Color = Color::Black;
	graph->FillRectangle(brush, rcBlock);
	nPath[pnRow] &= ~(nbit >> pnCol);

	return 0;
}

int StartMoving(System::Drawing::Graphics^ graph)
{
	nMoving = new (UINT[nL]);
	memset(nMoving, 0, sizeof(UINT) * nL);
	nPath = new UINT[nL];
	memset(nPath, 0, sizeof(UINT) * nL);

	int res = Moving(nRow, nColumn, graph, false);
	delete nMoving;
	return res;
}
