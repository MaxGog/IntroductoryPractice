#include "FirstSemester.h"
#include "Chart.h"
#include "MainForm.h"

#include <cmath>

using namespace System;
using namespace System::Globalization;
using namespace System::Drawing;
using namespace System::Globalization;
using namespace System::Windows::Forms;

using namespace std;

void IntroductoryPractice::MainForm::ParametricFunction()
{
	float enter_k, const_k, k_d, a = 2, step;
	float x, y;
	const int N = 35;

	String^ sResult;

	textboxTitle->Text = "������������� ��������������� �������...";
	textboxTitle->AppendText("\r\n������� �������� ����������� ��� k.");

	Input_DialogForm^ f_input1 = gcnew Input_DialogForm;
	f_input1->SetLabel("������� �������� ����������� ��� k");
	if (f_input1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		sResult = f_input1->GetDialogData();
		if (sResult == "") return;
		enter_k = Convert::ToDouble(sResult);
	}
	else
	{
		textboxTitle->AppendText("\r\n�������� �����������. ��������� �������.");
		return;
	}

	Input_DialogForm^ f_input2 = gcnew Input_DialogForm;
	f_input2->SetLabel("������� �������� kd	 ��� ����");
	if (f_input2->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		sResult = f_input2->GetDialogData();
		if (sResult == "") return;
		k_d = Convert::ToDouble(sResult);
	}
	else
	{
		textboxTitle->AppendText("\r\n�������� �����������. ��������� �������.");
		return;
	}

	f_input1->Close();
	f_input2->Close();

	textboxTitle->AppendText("\r\n\n�������� k = " + enter_k);
	textboxTitle->AppendText("\r\n�������� kd ���� = " + k_d);

	RecOut = new stRecursion[N];
	memset(RecOut, 0, sizeof(stRecursion) * N);

	step = a * k_d;
	const_k = enter_k * a;
	x = const_k;

	for (int i = 0; i < 35; i++)
	{
		if (x > -a)
		{
			y = a * pow(abs(x + 2 * a), (1/2));
		}
		else if (x <= -a)
		{
			y = a * cos(x + 1) + a;
		}
		RecOut[i].AddItem(i + 1, x, y);
		x += step;
	}   
	String^ sItem = gcnew String("");
	NumberFormatInfo^ ifp = gcnew NumberFormatInfo;
	CultureInfo^ ifc = gcnew CultureInfo("ru_RU");
	ifp->NumberDecimalDigits = 4;
	ifc->NumberFormat->NumberDecimalDigits = 4;

	listBoxOutput->Items->Add("�\tX\t\tY");
	for (int i = 0; i < 10; i++)
	{
		sItem = Convert::ToString(RecOut[i].nIdStruct);
		sItem += "\t" + Convert::ToString(RecOut[i].nValue1.ToString("n", ifp));
		sItem += "\t\t" + Convert::ToString(RecOut[i].nValue2.ToString("N", ifc));
		listBoxOutput->Items->Add(sItem);
	}
}

void IntroductoryPractice::MainForm::BranchingAlgorithmFirst()
{
	float a, b, d;
	const float limited = 12.5;
	float x, y, k;
	String^ sResult;

	textboxTitle->Text = "������������ ������ �2.1\r\n���� ���������� a, b, d. � ����������� �� �� �������� ��������� ���������� x, y, � k\r\n";

	Input_DialogForm^ f_input = gcnew Input_DialogForm;
	f_input->SetLabel("������� �������� ��� a");
	if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		sResult = f_input->GetDialogData();
		if (sResult == "") return;
		a = Convert::ToDouble(sResult);
	}
	else
	{
		textboxTitle->AppendText("\r\n�������� �����������. ��������� �������.");
		return;
	}
	f_input->SetLabel("������� �������� ��� b");
	if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		sResult = f_input->GetDialogData();
		if (sResult == "") return;
		b = Convert::ToDouble(sResult);
	}
	else
	{
		textboxTitle->AppendText("\r\n�������� �����������. ��������� �������.");
		return;
	}
	f_input->SetLabel("������� �������� ��� d");
	if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		sResult = f_input->GetDialogData();
		if (sResult == "") return;
		d = Convert::ToDouble(sResult);
	}
	else
	{
		textboxTitle->AppendText("\r\n�������� �����������. ��������� �������.");
		return;
	}
	f_input->Close();

	if (a == NULL || b == NULL || d == NULL) return;

	if (d < a < limited)
	{
		x = 2 * pow(a, 2) - 3 * pow(b, 3);
		y = a - d;
		k = 1;
	}
	else
	{
		x = sqrt(a - b) + d;
		y = 10, 5 * b;
		k = 2;
	}

	textboxTitle->AppendText("\r\n\n�������� a = " + a);
	textboxTitle->AppendText("\r\n�������� b = " + b);
	textboxTitle->AppendText("\r\n�������� d = " + d);
	listBoxOutput->Items->Add("x = " + x);
	listBoxOutput->Items->Add("y = " + y);
	listBoxOutput->Items->Add("k = " + k);
}

void IntroductoryPractice::MainForm::BranchingAlgorithmSecond()
{
	float a1, a2, a3;
	String^ sResult;

	textboxTitle->Text = "������������ ������ �2.2\r\n���� ���������� a1, a2, a3. ����������, �������� �� ��� ����������������� ������� �������������� ����������.������� " +
		"��������������� ��������� ��� ������� ������ ������������������ � ���������� � ����������� ����, ���� ������� ���� ���������.";

	Input_DialogForm^ f_input = gcnew Input_DialogForm;
	f_input->SetLabel("������� �������� ��� a1");
	if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		sResult = f_input->GetDialogData();
		if (sResult == "") return;
		a1 = Convert::ToDouble(sResult);
	}
	else
	{
		textboxTitle->AppendText("\r\n�������� �����������. ��������� �������.");
		return;
	}
	f_input->SetLabel("������� �������� ��� a2");
	if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		sResult = f_input->GetDialogData();
		if (sResult == "") return;
		a2 = Convert::ToDouble(sResult);
	}
	else
	{
		textboxTitle->AppendText("\r\n�������� �����������. ��������� �������.");
		return;
	}
	f_input->SetLabel("������� �������� ��� a3");
	if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		sResult = f_input->GetDialogData();
		if (sResult == "") return;
		a3 = Convert::ToDouble(sResult);
	}
	else
	{
		textboxTitle->AppendText("\r\n�������� �����������. ��������� �������.");
		return;
	}
	f_input->Close();

	textboxTitle->AppendText("\r\n\n�������� a = " + a1);
	textboxTitle->AppendText("\r\n�������� a2 = " + a2);
	textboxTitle->AppendText("\r\n�������� a3 = " + a3);

	if (a2 / a1 == a3 / a2)
	{
		listBoxOutput->Items->Add("������ ������������������ ����� �������� �������������� �����������.");
		listBoxOutput->Items->Add("q = " + (a2 / a1));
	}
	else if (a3 / a1 == a1 / a2)
	{
		listBoxOutput->Items->Add("������ ������������������ ����� �������� �������������� �����������.");
		listBoxOutput->Items->Add("q = " + (a3 / a1));
	}
	else if (a1 / a3 == a3 / a2)
	{
		listBoxOutput->Items->Add("������ ������������������ ����� �������� �������������� �����������.");
		listBoxOutput->Items->Add("q = " + (a1 / a3));
	}
	else
	{
		listBoxOutput->Items->Add("������ ������������������ ����� �� �������� �������������� �����������.");
	}
}

void IntroductoryPractice::MainForm::ProcessingOneDimensionalArray()
{
	float f[14]{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14 }, l[7]{ 1,2,3,4,5,6,7 }, sum_f = 0, sum_l = 0, s1, d[7];
	float max = d[0], min = d[0];
	int dmax = 0, dmin = 0;
	String^ sResult;
	Input_DialogForm^ f_input = gcnew Input_DialogForm;

	textboxTitle->Text = "������������ ������ �3.2\r\n������� �������� ��������� �������� f � l: ";
	
	textboxTitle->AppendText("\r\n\n������ f = ");
	for (int i = 0; i < std::size(f); i++)
	{
		f_input->SetLabel("������� �������� ��� f[" + (i + 1) + "]");
		if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			sResult = f_input->GetDialogData();
			if (sResult == "") return;
			f[i] = Convert::ToDouble(sResult);
			textboxTitle->AppendText(f[i] + " ");
		}
		else
		{
			textboxTitle->AppendText("\r\n�������� �����������. ��������� �������.");
			return;
		}
	}
	textboxTitle->AppendText("\r\n\n������ l = ");
	for (int i = 0; i < std::size(l); i++)
	{
		f_input->SetLabel("������� �������� ��� l[" + (i + 1) + "]");
		if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			sResult = f_input->GetDialogData();
			if (sResult == "") return;
			l[i] = Convert::ToDouble(sResult);
			textboxTitle->AppendText(l[i] + " ");
		}
		else
		{
			textboxTitle->AppendText("\r\n�������� �����������. ��������� �������.");
			return;
		}
	}

	for (int i = 0; i < std::size(f); i++)
	{
		sum_f += f[i];
		if (i < std::size(l))
			sum_l += l[i];
	}

	s1 = (sum_f - sum_l) / l[0];

	for (int i = 0; i < std::size(l); i++)
	{
		d[i] = l[i] / s1;
	}

	listBoxOutput->Items->Add("����� ������� f = " + sum_f);
	listBoxOutput->Items->Add("����� ������� l = " + sum_l);
	listBoxOutput->Items->Add("S1 = " + s1);
	listBoxOutput->Items->Add("");
	listBoxOutput->Items->Add("������ d:");
	for (int i = 0; i < std::size(d); i++)
		listBoxOutput->Items->Add((i + 1) + ". " + d[i]);
	listBoxOutput->Items->Add("");

	float sd = fabs((sum_f / static_cast<double>(std::size(f))) - (sum_l / static_cast<double>(std::size(l))));

	for (int c{}; c < std::size(d); ++c) {
		if (max < d[c]) {
			max = d[c];
			dmax = c;
		}
		if (min > d[c]) {
			min = d[c];
			dmin = c;
		}
	}
	d[dmax] -= sd;
	d[dmin] += sd;

	listBoxOutput->Items->Add("Sd = " + sd);
	listBoxOutput->Items->Add("");
	listBoxOutput->Items->Add("����� ������ d:");
	for (int i = 0; i < std::size(d); i++)
		listBoxOutput->Items->Add((i + 1) + ". " + d[i]);
}

void IntroductoryPractice::MainForm::Matrix()
{
	int line = 0, maxi = 0, totmax = 0, i, j, column = 0, rows = 50, col = 50;
	float a[50][50]{};
	String^ sResult;
	Input_DialogForm^ f_input = gcnew Input_DialogForm;
	textboxTitle->Text = "������������ ������ �4\r\n������ � ��������. � ������� ������� ������������ ������������ �������. " +
		"���������� ��� ������������� �������� � �������, ������� ������� �� �������, ���������� ��������, �������� �� ����������. � ������ " +
		"����������� ���������� ���������� � ������� ������ ��������������� ��������� � ��������� ������� ���������� �� ���������� �� ���, ���� �������� ��������� ��� ����� ��������";
	
	f_input->SetLabel("������� ���������� ����� �������");
	if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		
		try
		{
			sResult = f_input->GetDialogData();
			rows = Convert::ToInt32(sResult);
		}
		catch (int num_err)
		{
			textboxTitle->AppendText("\r\n������������ ��������. ��������� �������. ��� ������: " + num_err);
			throw;
		}
	}
	else
	{
		textboxTitle->AppendText("�������� �����������. ��������� �������.");
		return;
	}

	f_input->SetLabel("������� ���������� �������� �������");
	if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		try
		{
			sResult = f_input->GetDialogData();
			col = Convert::ToInt32(sResult);
		}
		catch (int num_err)
		{
			textboxTitle->AppendText("\r\n������������ ��������. ��������� �������. ��� ������: " + num_err);
			return;
		}
	}
	else
	{
		textboxTitle->AppendText("\r\n�������� �����������. ��������� �������.");
		return;
	}

	if (rows <= 1 && col <= 1)
	{
		textboxTitle->AppendText("\r\n���������� ����� � �������� ������� ����.");
		return;
	}
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			f_input->SetLabel("������� �������� �������� ������� � ����: " + (i + 1) + " " + (j + 1));
			if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				sResult = f_input->GetDialogData();
				if (sResult == "") return;
				a[i][j] = Convert::ToDouble(sResult);
			}
			else
			{
				textboxTitle->AppendText("\r\n�������� �����������. ��������� �������.");
				return;
			}
		}
	}

	f_input->Close();

	String^ sItem = gcnew String("");

	listBoxOutput->Items->Add("�������� �������: ");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int temp = a[i][j];
			sItem += "\t" + Convert::ToString(temp.ToString());
		}
		listBoxOutput->Items->Add(sItem);
		sItem = "";
	}
	listBoxOutput->Items->Add("");

	for (i = 0; i < rows; i++) {
		for (j = 0; j < col; j++) {
			if (maxi <= a[i][j]) {
				maxi = a[i][j];
				totmax += 1;
				line = i;
				column = j;
			}
		}
	}
	if (totmax != 1)
		listBoxOutput->Items->Add("����. ��������� ������� ������� = " + maxi);
	else
		listBoxOutput->Items->Add("����. ������� ������� = " + maxi);


	for (i = line + 1; i < rows; i++)
	{
		for (j = column; j < col; j++) 
		{
			if (a[i][j] < 0) 
			{
				a[i][j] = a[line][j] * a[line][j];
			}
		}
	}
	

	listBoxOutput->Items->Add("");
	listBoxOutput->Items->Add("��������� �������: ");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < col; j++)
		{
			sItem += "\t" + Convert::ToString(a[i][j].ToString());
		}
		listBoxOutput->Items->Add(sItem);
		sItem = "";
	}
	listBoxOutput->Items->Add("");
}
