#include "Chart.h"
#include "MainForm.h"
#include <stdlib.h>
#include <string.h>
#include <cmath>

using namespace IntroductoryPractice;
using namespace System;
using namespace System::Globalization;
using namespace System::Drawing;
using namespace System::Globalization;
using namespace System::Windows::Forms;

void MainForm::Recursion()
{
	ClearOldTask();
	float num_x, num_a, num_y;
	String^ sResult;
	textboxTitle->Text = "Использование рекурсии суммирования всех членов.";
	textboxTitle->AppendText("\r\nВведите значение X.");

	Input_DialogForm^ f_input1 = gcnew Input_DialogForm;
	f_input1->SetLabel("Введите значение X");
	//result = f_input1->ShowDialog();
	if (f_input1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		sResult = f_input1->GetDialogData();
		if (sResult == "") return;
		num_x = Convert::ToDouble(sResult);
	}
	else
	{
		textboxTitle->AppendText("Значение отсутствует. Повторите попытку.");
		return;
	}

	textboxTitle->AppendText("\r\nВведите значение A.");

	Input_DialogForm^ f_input2 = gcnew Input_DialogForm;
	f_input2->SetLabel("Введите значение A");
	//result = f_input2->ShowDialog();
	if (f_input2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		sResult = f_input2->GetDialogData();
		if (sResult == "") return;
		num_a = Convert::ToDouble(sResult);
	}
	else
	{
		textboxTitle->AppendText("Значение отсутствует. Повторите попытку.");
		return;
	}

	f_input1->Close();
	f_input2->Close();

	textboxTitle->AppendText("\r\n\nЗначение X = " + num_x);
	textboxTitle->AppendText("\r\nЗначение A = " + num_a);

	RecOut = new stRecursion[10];
	memset(RecOut, 0, sizeof(stRecursion) * 10);

	num_y = calc_func(num_x, num_a, 1, 0, 1, RecOut);

	String^ sItem = gcnew String("");
	NumberFormatInfo^ ifp = gcnew NumberFormatInfo;
	CultureInfo^ ifc = gcnew CultureInfo("ru_RU");
	ifp->NumberDecimalDigits = 3;
	ifc->NumberFormat->NumberDecimalDigits = 3;

	listBoxOutput->Items->Add("ID\tЗНАЧЕНИЯ\t\tСУММА");
	for (int i = 0; i < 10; i++)
	{
		sItem = Convert::ToString(RecOut[i].nIdStruct);
		sItem += "\t" + Convert::ToString(RecOut[i].nValue1.ToString("n", ifp));
		sItem += "\t\t" + Convert::ToString(RecOut[i].nValue2.ToString("N", ifc));
		listBoxOutput->Items->Add(sItem);
	}

	listBoxOutput->Items->Add("");
	listBoxOutput->Items->Add("\r\r\nВывести конечное значение y = " + num_y.ToString("N", ifc));
}

//СТАРАЯ ВЕРСИЯ РЕКУРСИИ С КОНСОЛИ
/*void calculateChart()
{
	float num_x, num_a, num_y;
	SetColor(CL_LIGHT_YELLOW, CL_BLACK);
	cout << "График функции (45 вариант) | Задание с рекурсией" << endl << endl;
	DEFAULT_COLOR;
	cout << "Задание: дана функция по вариантам, нужно вычислить промежуточные значения с параметрами X и A.\n\nВведите X: ";
	cin >> num_x;
	cout << "Введите A: ";
	cin >> num_a;
	num_y = calc_func(num_x, num_a, 1, 0, 1);
}*/

float calc_func(float x, float a, int i, float summ, float step, pstRecursion pstRec)
{
	step = step * (x * x * x);
	float a_n = sqrtf(step * (a + i));
	summ = summ + a_n;
	pstRec[i - 1].AddItem(i, a_n, summ);
	if (i >= 10) return summ;
	return calc_func(x, a, ++i, summ, step, pstRec);
}

void DrawTextRotate(Graphics^ pgraph, String^ ptext, System::Drawing::Rectangle prect, Font^ pfont, Brush^ pbrush, float angle)
{
	System::Drawing::Rectangle rect(0, 0, prect.Height, prect.Width);
	pgraph->ResetTransform();
	pgraph->RotateTransform(angle);

	pgraph->TranslateTransform(prect.Left, prect.Bottom, System::Drawing::Drawing2D::MatrixOrder::Append);
	StringFormat^ string_format = gcnew StringFormat();
	string_format->Alignment = StringAlignment::Center;
	string_format->LineAlignment = StringAlignment::Center;
	Pen^ pen = gcnew Pen(Color::Black, 2);
	//pgraph->DrawRectangle(pen, prect);
	pgraph->DrawString(ptext, pfont, pbrush, rect, string_format);
	pgraph->ResetTransform();
}


void DrawAxisX(Graphics^ pgraph, RECT pArea, float pnMin, float pnMax, int pnSec)
{
	PointF p1, p2;
	p1.X = pArea.left;
	p1.Y = pArea.bottom;

	p2.X = pArea.right;
	p2.Y = pArea.bottom;

	Pen^ pen = gcnew Pen(Color::Black, 2);
	pgraph->DrawLine(pen, p1, p2);
	Font^ font = gcnew Font("Times New Roman", 12);
	SolidBrush^ brush = gcnew SolidBrush(Color::Red);

	String^ saxis = gcnew String("Индефикатор значения");
	int indaxis = ((pArea.right - pArea.left) - saxis->Length) / 2;

	pgraph->DrawString(saxis, font, brush, pArea.left + indaxis, pArea.bottom + 30);

	float nPxPerVal = (pArea.right - pArea.left) / (pnMax - pnMin);

	pen->Width = 1;
	pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dot;
	pen->Color = Color::Gray;

	for (int i = 0; i < (pnSec); i++)
	{
		float nPxStep = pArea.left + (i)*nPxPerVal * (pnMax - pnMin) / (pnSec - 1);
		pgraph->DrawLine(pen, nPxStep, (float)pArea.bottom + 2, nPxStep, (float)pArea.top);
		brush->Color = Color::Black;
		pgraph->DrawString(Convert::ToString(pnMin + i), font, brush, nPxStep - font->Size / 2, pArea.bottom + 4);
	}
}

void DrawAxisY(Graphics^ pgraph, RECT pArea, float pnMin, float pnMax, int pnSec)
{
	PointF p1, p2;
	p1.X = pArea.left;
	p1.Y = pArea.bottom;

	p2.X = pArea.left;
	p2.Y = pArea.top;

	Pen^ pen = gcnew Pen(Color::Black, 2);
	pgraph->DrawLine(pen, p1, p2);

	float nDlt = (pnMax - pnMin) / pnSec;
	float nPxPerVal = (pArea.bottom - pArea.top) / (pnMax - pnMin);

	Font^ font = gcnew Font("Times New Roman", 12);
	SolidBrush^ brush = gcnew SolidBrush(Color::Red);

	String^ label = gcnew String("Значения");
	int indaxis = ((pArea.bottom - pArea.top) - label->Length) / 2;

	System::Drawing::Rectangle rect( int(pArea.left - font->Height), pArea.top, int(font->Height), int(pArea.bottom - pArea.top) );

	DrawTextRotate(pgraph, label, rect, font, brush, -90);

	String^ sItem = gcnew String("");
	NumberFormatInfo^ ifp = gcnew NumberFormatInfo;
	CultureInfo^ ifc = gcnew CultureInfo("ru_RU");
	ifp->NumberDecimalDigits = 3;
	ifc->NumberFormat->NumberDecimalDigits = 3;

	for (int i = 0; i < (pnSec) + 1; i++)
	{
		float nPxStep = pArea.bottom - (i)*nPxPerVal * (pnMax - pnMin) / (pnSec);
		if (i > 0)
		{
			pen->Width = 1;
			pen->DashStyle = System::Drawing::Drawing2D::DashStyle::Dot;
			pen->Color = Color::Gray;

			pgraph->DrawLine(pen, pArea.left - 3, int(nPxStep), pArea.right, int(nPxStep));
		}
		float val = (pnMin + (i * nDlt));
		brush->Color = Color::Black;
		pgraph->DrawString(val.ToString("n", ifp), font, brush, pArea.left - 100, int(nPxStep));
	}
}

void drawGraph(Graphics^ pgraph, pstRecursion pRec, int pnSizeRec, RECT pstRect)
{
	if (pnSizeRec == 0 || pRec == NULL) return;

	float nMinAxisX, nMaxAxisX, nMinAxisY, nMaxAxisY;

	nMinAxisY = nMaxAxisY - pRec[0].nValue1;
	nMinAxisX = pRec[0].nIdStruct;
	nMaxAxisX = pRec[pnSizeRec - 1].nIdStruct;
	for (int i = 0; i < pnSizeRec; i++)
	{
		if (nMinAxisY > pRec[i].nValue1) nMinAxisY = pRec[i].nValue1;
		if (nMinAxisY > pRec[i].nValue2) nMinAxisY = pRec[i].nValue2;

		if (nMinAxisY < pRec[i].nValue1) nMaxAxisY = pRec[i].nValue1;
		if (nMinAxisY < pRec[i].nValue2) nMaxAxisY = pRec[i].nValue2;
	}
	Pen^ blackPen = gcnew Pen(Color::Black);
	pgraph->DrawRectangle(blackPen, pstRect.left, pstRect.top, pstRect.right - pstRect.left, pstRect.bottom - pstRect.top);

	Font^ hfont = gcnew Font("Times New Roman", 16);

	SolidBrush^ hbrush = gcnew SolidBrush(Color::Red);

	String^ sHeading = "График рекурентного соотношения";
	int nheadsize = sHeading->Length, nind = 100;

	int zind = ((pstRect.right - pstRect.left) - hfont->Size * sHeading->Length) / 2 + nind;
	pgraph->DrawString(sHeading, hfont, hbrush, pstRect.left + zind, pstRect.top);

	RECT rAxisX(pstRect);
	rAxisX.top += 30;
	rAxisX.left += 100;
	rAxisX.right -= 20;
	rAxisX.bottom -= 60;
	DrawAxisX(pgraph, rAxisX, nMinAxisX, nMaxAxisX, pnSizeRec);
	DrawAxisY(pgraph, rAxisX, nMinAxisY, nMaxAxisY, 7);

	float nPxPerVal = (rAxisX.right - rAxisX.left);

	int nY = (int)(rAxisX.bottom - (pRec[0].nValue1 - nMinAxisY) * (rAxisX.bottom - rAxisX.top) / (nMaxAxisY - nMinAxisY));
	int nSY = (int)(rAxisX.bottom - (pRec[0].nValue2 - nMinAxisY) * (rAxisX.bottom - rAxisX.top) / (nMaxAxisY - nMinAxisY));
	int nPxOld = rAxisX.left;

	blackPen->Width = 4;
	for (int i = 1; i < pnSizeRec; i++)
	{
		float nPxStep = rAxisX.left + (i)*nPxPerVal / (pnSizeRec - 1);
		int nY2 = (int)(rAxisX.bottom - (pRec[i].nValue1 - nMinAxisY) * (rAxisX.bottom - rAxisX.top) / (nMaxAxisY - nMinAxisY));

		blackPen->Color = Color::Blue;
		pgraph->DrawLine(blackPen, (int)nPxOld, nY, (int)nPxStep, nY2);
		nY = nY2;

		int nSY2 = (int)(rAxisX.bottom - (pRec[i].nValue2 - nMinAxisY) * (rAxisX.bottom - rAxisX.top) / (nMaxAxisY - nMinAxisY));
		blackPen->Color = Color::Red;
		pgraph->DrawLine(blackPen, (int)nPxOld, nSY, (int)nPxStep, nSY2);
		nSY = nSY2;

		nPxOld = nPxStep;
	}
}