#pragma once
#include <string>
#include <fstream>
#include <Windows.h>

#include "Header.h"
#include "MyConvector.h"

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Runtime::InteropServices;

class CID
{
protected:
	int nId;
	nameshape sName;
public:
	CID() :nId(0), sName(NONE) {}
	CID(int pnid) : nId(pnid), sName(NONE) {}
	CID(nameshape pnname) : sName(pnname), nId(0) {}
	CID(int pnid, nameshape pnname) : nId(pnid), sName(pnname) {}


	int GetID() { return nId; }
	void SetID(int pnid) { nId = pnid; }
	_declspec(property(get = GetID, put = SetID)) int id;

	nameshape GetName() { return sName; }
	virtual void SetName(nameshape pnname) { sName = pnname; }
	_declspec(property(get = GetName, put = SetName)) nameshape name;
};

class CShape : public CID
{
protected:
	int nx, ny, nWidth, nHeight, brushColor, penColor;
	int nRight, nBottom;

public:
	CShape() : nx(0), ny(0), nWidth(40), nHeight(60)
	{
		brushColor = RGB(34, 34, 34);
		penColor = RGB(255, 255, 255);
	}
	CShape(int pnx, int pny, int pnWidth = 40, int pnHeight = 60)
	{
		nx = pnx;
		ny = pny;
		nWidth = pnWidth;
		nHeight = pnHeight;
		brushColor = RGB(34, 34, 34);
		penColor = RGB(255, 255, 255);
	}
	CShape(int pnx, int pny, int pnWid, int pnHei, int pnBrush, int pnPen)
	{
		nx = pnx;
		ny = pny;
		nWidth = pnWid;
		nHeight = pnHei;
		brushColor = pnBrush;
		penColor = pnPen;
	}

	int getX() { return nx; }
	void setX(int pnx) { nx = pnx; }
	_declspec(property(get = getX, put = setX)) int X;

	int getY() { return ny; }
	void setY(int pny) { ny = pny; }
	_declspec(property(get = getY, put = setY)) int Y;

	int getWidth() { return nWidth; }
	void setWidth(int pnWidth) { nWidth = pnWidth; }
	_declspec(property(get = getWidth, put = setWidth)) int Width;

	int getHeight() { return nHeight; }
	void setHeight(int pnHeight) { nHeight = pnHeight; }
	_declspec(property(get = getHeight, put = setHeight)) int Height;

	int getBrushColor() { return brushColor; }
	void setBrushColor(int pnBrush) { brushColor = pnBrush; }
	_declspec(property(get = getBrushColor, put = setBrushColor)) int BrushColor;

	int getPenColor() { return penColor; }
	void setPenColor(int pnPen) { penColor = pnPen; }

	_declspec(property(get = getPenColor, put = setPenColor)) int PenColor;

	int GetMiddleX() { return nx + Width / 2; }
	int GetMiddleY() { return ny + Height / 2; }

	int GetRight() { return nx + nWidth; }
	int GetBottom() { return ny + nHeight; }

	_declspec(property(get = getX, put = setX)) int Left;
	_declspec(property(get = getY, put = setY)) int Top;
	_declspec(property(get = GetRight)) int Right;
	_declspec(property(get = GetBottom)) int Bottom;
	_declspec(property(get = GetMiddleX)) int MiddleX;
	_declspec(property(get = GetMiddleY)) int MiddleY;

	void Move(int px, int py, bool anime = false) 
	{
		if (anime) {
			int dx = (px - nx),
				dy = (py - ny);
			for (int i = 0; i <= 30; i++) {
				nx = nx + dx * i / 30;
				ny = ny + dy * i / 30;

				Sleep(100 / i);
			}
		}
		else {
			nx = px;
			ny = py;
		}
	}

	virtual void Draw(System::Drawing::Graphics^ graph) = 0;
};

class CManager
{
	CShape** objShape;
	int ncount;

public:
	CManager();
	~CManager();

	int Add(CShape* pfig);
	int Delete(CShape* pfig);
	int Delete(int pindex);
	int Delete(short pid);
	void AllClear();
	CShape* GetShape(int pid);
	CShape* GetShape(int x, int y);

	int GetCount();
	__declspec(property(get = GetCount)) int count;

	int GetLastId()
	{
		int nid = 0;
		for (int i = 0; i < ncount; i++)
		{
			if (nid < (objShape[i])->GetID())
				nid = (objShape[i])->GetID();
		}
		return nid;
	}
	__declspec(property(get = GetLastId)) int Last_ID;

	void Draw(System::Drawing::Graphics^ graph);
	void Draw(System::Drawing::Graphics^ graph, int pid);
	void Draw(System::Drawing::Graphics^ graph, _eNameShapes pclass);
	void DrawGraph(System::Drawing::Graphics^ graph);
	void NoDrawLineGraph(System::Drawing::Graphics^ graph, CShape* pfig);
	void LoadArchive(string pfile);
	void SaveArchive(string pfile);

	CShape* operator[](int index);
	CShape* operator[](short pid);
};

class CRectangle : public CShape
{
public:
	CRectangle() : CShape(0, 0, 40, 60, RGB(rand() % 255, 50, 50), RGB(255, 255, 255))
	{
		name = RECTANGLE;
	}

	CRectangle(int pnx, int pny, int pnWidth = 30, int pnHeight = 60) : CShape(pnx, pny, pnWidth, pnHeight)
	{
		brushColor = RGB(rand() % 255, 50, 50);
		penColor = RGB(255, 255, 255);
		name = RECTANGLE;
	}
	CRectangle(int pnx, int pny, int pnWid, int pnHei, int pnBrush, int pnPen) : CShape(pnx, pny, pnWid, pnHei, pnBrush, pnPen)
	{
		name = RECTANGLE;
	}

	virtual void Draw(System::Drawing::Graphics^ graph);
};

class CTriangle : public CShape
{
public:

	CTriangle() : CShape(0, 0, 70, 50, RGB(134, rand() % 255, 134), RGB(255, 255, 255))
	{
		name = TRIANGLE;
	}

	CTriangle(int pnx, int pny, int pnWidth = 70, int pnHeight = 50) : CShape(pnx, pny, pnWidth, pnHeight)
	{
		brushColor = RGB(134, rand() % 255, 134);
		penColor = RGB(255, 255, 255);
		name = TRIANGLE;
	}
	CTriangle(int pnx, int pny, int pnWid, int pnHei, int pnBrush, int pnPen) : CShape(pnx, pny, pnWid, pnHei, pnBrush, pnPen)
	{
		name = TRIANGLE;
	}

	virtual void Draw(System::Drawing::Graphics^ graph);
};

class CEllipse : public CShape
{
public:
	CEllipse() : CShape(0, 0, 60, 60, RGB(134, 134, rand() % 255), RGB(255, 255, 255))
	{
		name = ELLIPSE;
	}

	CEllipse(int pnx, int pny, int pnWidth = 60, int pnHeight = 60) : CShape(pnx, pny, pnWidth, pnHeight)
	{
		brushColor = RGB(134, 134, rand() % 255);
		penColor = RGB(255, 255, 255);
		name = ELLIPSE;
	}
	CEllipse(int pnx, int pny, int pnWid, int pnHei, int pnBrush, int pnPen) : CShape(pnx, pny, pnWid, pnHei, pnBrush, pnPen)
	{
		name = ELLIPSE;
	}

	virtual void Draw(System::Drawing::Graphics^ graph);
};

class CUnion : public CShape
{
	CShape* oshape_1, * oshape_2;
public:
	CUnion() :CShape() {
		oshape_1 = NULL; oshape_2 = NULL; name = LINE;
	}
	CUnion(CShape* pshape_1, CShape* pshape_2) : oshape_1(pshape_1), oshape_2(pshape_2)
	{
		name = LINE;
	}
	CUnion(int pid, CShape* pshape_1, CShape* pshape_2) : CShape(), oshape_1(pshape_1), oshape_2(pshape_2)
	{
		nId = pid;
		name = LINE;
	}
	CShape* GetShape_1() { return oshape_1; }
	CShape* GetShape_2() { return oshape_2; }
	void SetShape_1(CShape* pshape) { oshape_1 = pshape; }
	void SetShape_2(CShape* pshape) { oshape_2 = pshape; }
	bool IsInObjects(CShape* pfig) { return oshape_1 == pfig || oshape_2 == pfig; }
	__declspec(property(get = GetShape_1, put = SetShape_1)) CShape* shape_1;
	__declspec(property(get = GetShape_2, put = SetShape_2)) CShape* shape_2;

	__declspec(property(get = getPenColor, put = setPenColor)) int Color;
	__declspec(property(get = getWidth, put = setWidth)) int Thickness;

	virtual void Draw(System::Drawing::Graphics^ graph);
};

CShape* FindShape(int pnid);