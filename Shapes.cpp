#include "Shapes.h"

CManager::CManager() :objShape(NULL), ncount(0) {}
CManager::~CManager() { AllClear(); }

int CManager::Add(CShape* pfig)
{
	if (pfig == NULL) return -1;
	objShape = (CShape**)realloc(objShape, sizeof(CShape*) * (++ncount));
	objShape[ncount - 1] = pfig;
	return ncount - 1;
}

int CManager::Delete(CShape* pfig)
{
	for (int i = 0; i < ncount; i++)
		if (objShape[i] == pfig) return Delete(i);
	return 0;
}

int CManager::Delete(int pindex)
{
	if (pindex < 0 || pindex >= ncount) return -1;
	delete (objShape[pindex]);
	for (int i = pindex + 1; i < ncount; i++) objShape[i - 1] = objShape[i];
	objShape = (CShape**)realloc(objShape, sizeof(CShape*) * (--ncount));
	return pindex;
}

int CManager::Delete(short pid)
{
	for (int i = 0; i < ncount; i++)
		if (((CRectangle*)objShape[i])->id == pid) return Delete(i);
	return 0;
}

void CManager::AllClear()
{
	for (int i = 0; i < ncount; i++) delete objShape[i];
	if (objShape != NULL) objShape = (CShape**)realloc(objShape, 0);
	ncount = 0;
}

void CManager::Draw(System::Drawing::Graphics^ graph)
{
	for (int i = 0; i < ncount; i++) objShape[i]->Draw(graph);
}

void CManager::Draw(System::Drawing::Graphics^ graph, int pid)
{
	for (int i = 0; i < ncount; i++)
		if (((CRectangle*)objShape[i])->id == pid) objShape[i]->Draw(graph);
}

void CManager::Draw(System::Drawing::Graphics^ graph, _eNameShapes pclass)
{
	for (int i = 0; i < ncount; i++)
		if (((CRectangle*)objShape[i])->name == pclass) objShape[i]->Draw(graph);
}

void CManager::DrawGraph(System::Drawing::Graphics^ graph)
{
	for (int i = 0; i < ncount; i++)
	{
		objShape[i]->Draw(graph);
		if ((objShape[i])->name == LINE)
		{
			((CUnion*)objShape[i])->shape_1->Draw(graph);
			((CUnion*)objShape[i])->shape_2->Draw(graph);
		}
	}
}

void CManager::NoDrawLineGraph(System::Drawing::Graphics^ graph, CShape* pfig) {
	for (int i = 0; i < ncount; i++)
	{
		if ((objShape[i])->name == LINE)
		{
			if (((CUnion*)objShape[i])->IsInObjects(pfig))
			{
				objShape[i]->Draw(graph);
				((CUnion*)objShape[i])->shape_1->Draw(graph);
				((CUnion*)objShape[i])->shape_2->Draw(graph);
			}
		}
	}
}

CShape* CManager::GetShape(int pid)
{
	for (int i = 0; i < ncount; i++)
		if (((CRectangle*)objShape[i])->id == pid) return objShape[i];
	return NULL;
}

CShape* CManager::GetShape(int x, int y)
{
	CShape* shape = 0;
	for (int i = 0; i < ncount; i++)
	{
		shape = objShape[i];
		if ((shape->X <= x) && (x <= shape->Right) && (shape->Y <= y) && (y <= shape->Bottom))
		{
			return shape;
		}
		shape = 0;
	}
	return shape;
}

int CManager::GetCount() { return ncount; }

void CManager::LoadArchive(string pfile)
{
	ifstream fin(pfile, ios::beg);
	if (!fin) return;
	string sline = "", skey{}, svalue{};
	CShape* shape = nullptr, * shape_2 = nullptr;
	CUnion* ounion = nullptr;

	pair<string, string> keyvalue;
	while (fin)
	{
		fin >> sline;
		if (sline == "Rectangle")
		{
			shape = new CRectangle;
			shape->SetName(RECTANGLE);
		}
		else if (sline == "Triangle")
		{
			shape = new CTriangle;
			shape->SetName(TRIANGLE);
		}
		else if (sline == "Ellipse")
		{
			shape = new CEllipse;
			shape->SetName(ELLIPSE);
		}
		else if (sline == "Line")
		{
			shape = new CUnion;
			shape->SetName(LINE);
		}

		if (shape)
		{
			while (fin && skey != "end")
			{
				fin >> sline;
				if (sline == "end") break;
				keyvalue = GetKeyValue(sline);
				skey = keyvalue.first;
				svalue = keyvalue.second;
				if (skey == "id") shape->SetID(strtol(svalue.c_str(), 0, 10));
				else if (skey == "x") shape->X = strtol(svalue.c_str(), 0, 10);
				else if (skey == "y") shape->Y = strtol(svalue.c_str(), 0, 10);
				else if (skey == "width") shape->Width = strtol(svalue.c_str(), 0, 10);
				else if (skey == "height") shape->Height = strtol(svalue.c_str(), 0, 10);
				else if (skey == "bcolor") shape->BrushColor = strtol(svalue.c_str(), 0, 10);
				else if (skey == "pcolor") shape->PenColor = strtol(svalue.c_str(), 0, 10);
				else if (skey == "shape1")
				{
					int id = strtol(svalue.c_str(), 0, 10);
					shape_2 = GetShape(id);
					((CUnion*)shape)->shape_1 = shape_2;
				}
				else if (skey == "shape2")
				{
					int id = strtol(svalue.c_str(), 0, 10);
					shape_2 = GetShape(id);
					((CUnion*)shape)->shape_2 = shape_2;
				}
			}
			this->Add(shape);
		}
	}
	fin.close();
}

void CManager::SaveArchive(string pfile)
{
	ofstream fout(pfile);
	if (!fout) return;

	for (int i = 0; i < ncount; i++)
	{
		CShape* shape = this->objShape[i];
		if (shape == nullptr) continue;

		switch (shape->GetName())
		{
		case TRIANGLE:
			fout << "Triangle";
			break;
		case RECTANGLE:
			fout << "Rectangle";
			break;
		case ELLIPSE:
			fout << "Ellipse";
			break;
		case LINE:
			fout << "Line";
			break;
		default:
			fout << "None";
			break;
		}
		fout << endl << "id=" << shape->GetID() << endl;
		fout << "x=" << shape->X << endl << "y=" << shape->Y << endl;
		fout << "width=" << shape->Width << endl << "height=" << shape->Height << endl;
		fout << "bcolor=" << shape->BrushColor << endl << "pcolor=" << shape->PenColor << endl;

		if (shape->GetName() == LINE)
		{
			fout << "shape1=" << ((CUnion*)shape)->shape_1->id << endl;
			fout << "shape2=" << ((CUnion*)shape)->shape_2->id << endl;
		}

		fout << "end" << endl;
	}

	fout.close();
}

CShape* CManager::operator[](int index)
{
	if (index < 0 || index >= ncount) return NULL;
	return objShape[index];
}

CShape* CManager::operator[](short pid) { return GetShape(pid); }

CShape* FindShape(int pnid)
{
	//for (int i = 0; i < ncount; i++)
		//if (((CRectangle*)objShape[i])->id == pid) return objShape[i];
	return NULL;
}

void CRectangle::Draw(System::Drawing::Graphics^ graph)
{
	System::Drawing::Color bclr = System::Drawing::Color::FromArgb(255, GetRValue(brushColor), GetGValue(brushColor), GetBValue(brushColor));
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(bclr);
	System::Drawing::Pen^ pen = gcnew Pen(Color::FromArgb(255, GetRValue(penColor), GetGValue(penColor), GetBValue(penColor)));
	
	System::Drawing::Rectangle rc(nx, ny, nWidth, nHeight);

	graph->FillRectangle(brush, rc);
	graph->DrawRectangle(pen, rc);

	Font font(L"Arial", 12);
	int clr = ~brushColor;
	System::Drawing::SolidBrush^ brushFont = gcnew System::Drawing::SolidBrush(Color::FromArgb(255, GetRValue(clr), GetGValue(clr), GetBValue(clr)));
	String^ text = Convert::ToString(nId);
	graph->DrawString(text, %font, brushFont, MiddleX - 8, MiddleY - 8);
}

void CTriangle::Draw(System::Drawing::Graphics^ graph)
{
	System::Drawing::Color bclr = System::Drawing::Color::FromArgb(255, GetRValue(brushColor), GetGValue(brushColor), GetBValue(brushColor));
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(bclr);
	System::Drawing::Pen^ pen = gcnew Pen(Color::FromArgb(255, GetRValue(penColor), GetGValue(penColor), GetBValue(penColor)));

	Pen^ blackPen = gcnew Pen(Color::Black, 3);

	PointF pt1 = PointF((float)nx + nWidth / 2, (float)ny);
	PointF pt2 = PointF((float)pt1.X, (float)ny + nHeight);
	PointF pt3 = PointF((float)nx, (float)ny + nHeight);
	PointF pt4 = PointF((float)pt1.X, (float)pt1.Y);

	cli::array<PointF, 1>^ pt = { pt1, pt2, pt3, pt4 };

	graph->DrawPolygon(pen, pt);
	graph->FillPolygon(brush, pt);

	Font font(L"Arial", 12);
	int clr = ~brushColor;
	System::Drawing::SolidBrush^ brushFont = gcnew System::Drawing::SolidBrush(Color::FromArgb(255, GetRValue(clr), GetGValue(clr), GetBValue(clr)));
	String^ text = Convert::ToString(nId);
	graph->DrawString(text, %font, brushFont, MiddleX - 8, MiddleY - 8);
}

void CEllipse::Draw(System::Drawing::Graphics^ graph)
{
	System::Drawing::Color bclr = System::Drawing::Color::FromArgb(255, GetRValue(brushColor), GetGValue(brushColor), GetBValue(brushColor));
	System::Drawing::SolidBrush^ brush = gcnew System::Drawing::SolidBrush(bclr);
	System::Drawing::Pen^ pen = gcnew Pen(Color::FromArgb(255, GetRValue(penColor), GetGValue(penColor), GetBValue(penColor)));
	System::Drawing::Rectangle rc(nx, ny, nWidth, nHeight);

	graph->FillEllipse(brush, rc);
	graph->DrawEllipse(pen, rc);

	Font font(L"Arial", 12);
	int clr = ~brushColor;
	System::Drawing::SolidBrush^ brushFont = gcnew System::Drawing::SolidBrush(Color::FromArgb(255, GetRValue(clr), GetGValue(clr), GetBValue(clr)));
	String^ text = Convert::ToString(nId);
	graph->DrawString(text, %font, brushFont, MiddleX - 8, MiddleY - 8);
}

void CUnion::Draw(System::Drawing::Graphics^ graph)
{
	Pen^ pen = gcnew Pen(Color::Black, 3);
	graph->DrawLine(pen, shape_1->MiddleX, shape_1->MiddleY, shape_2->MiddleX, shape_2->MiddleY);
}
