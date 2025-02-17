#pragma once
#include <stdlib.h>
#include <string>
#include <Windows.h>

#include "Input_DialogForm.h"
#include "Mask.h"
#include "Encryption.h"
#include "Sorting.h"
#include "Chart.h"
#include "Maze.h"
#include "Shapes.h"

#include "MyConvector.h"

namespace IntroductoryPractice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		static stRecursion* RecOut;

		static CManager* mng = 0;
		static int mx, my, dx, dy;
		static CShape* ActiveClass = 0;
		MyAction onaction;

		MainForm(void)
		{
			InitializeComponent();
		}

		void ClearOldTask()
		{
			textboxTitle->Text = "Выберите пункт меню для решения задачи.";
			listBoxOutput->Items->Clear();
			onaction = DEFAULT;
			Refresh();
		}

	protected:
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::MenuStrip^ menuMain;
	private: System::Windows::Forms::ToolStripMenuItem^ menuMask;
	private: System::Windows::Forms::ToolStripMenuItem^ menuFirstTerm;
	private: System::Windows::Forms::ToolStripMenuItem^ menuAbout;
	private: System::Windows::Forms::ToolStripMenuItem^ menuLab21;
	private: System::Windows::Forms::ToolStripMenuItem^ menuLab22;
	private: System::Windows::Forms::ToolStripMenuItem^ menuLab32;
	private: System::Windows::Forms::ToolStripMenuItem^ menuLab4;
	private: System::Windows::Forms::ToolStripMenuItem^ menuMaze;
	private: System::Windows::Forms::ToolStripMenuItem^ menuPlayMaze;
	private: System::Windows::Forms::ToolStripMenuItem^ menuRouteMaze;
	private: System::Windows::Forms::ToolStripMenuItem^ menuRecursion;
	private: System::Windows::Forms::ToolStripMenuItem^ menuSort;
	private: System::Windows::Forms::ToolStripMenuItem^ menuEncryption;
	private: System::Windows::Forms::ToolStripMenuItem^ menuEncCaeser;
	private: System::Windows::Forms::ToolStripMenuItem^ menuEncDynCaeser;
	private: System::Windows::Forms::ToolStripMenuItem^ menuEncBit;
	private: System::Windows::Forms::ToolStripMenuItem^ menuClass;
	private: System::Windows::Forms::ToolStripMenuItem^ menuSortChoice;
	private: System::Windows::Forms::ToolStripMenuItem^ menuSortBubble;
	private: System::Windows::Forms::ToolStripMenuItem^ menuFastSort;
	private: System::Windows::Forms::ToolStripMenuItem^ menuCreateObjects;
	private: System::Windows::Forms::ToolStripMenuItem^ menuCreateTriangle;
	private: System::Windows::Forms::ToolStripMenuItem^ menuCreateRectangle;
	private: System::Windows::Forms::ToolStripMenuItem^ menuCreateEllipse;
	private: System::Windows::Forms::ToolStripMenuItem^ menuOnUnion;
	private: System::Windows::Forms::ToolStripMenuItem^ menuOffUnion;
	private: System::Windows::Forms::ToolStripMenuItem^ menuUpdateShapes;
	private: System::Windows::Forms::ToolStripMenuItem^ menuSaveShapes;
	private: System::Windows::Forms::ToolStripMenuItem^ menuLoadShapes;
	private: System::Windows::Forms::ToolStripMenuItem^ menuUnionObjetcs;
	private: System::Windows::Forms::ToolStripMenuItem^ menuExit;
	private: System::Windows::Forms::Panel^ panelTitle;
	private: System::Windows::Forms::Panel^ panelOutput;
	private: System::Windows::Forms::TextBox^ textboxTitle;
	private: System::Windows::Forms::ListBox^ listBoxOutput;
	private: System::Windows::Forms::ToolStripMenuItem^ menuShiftLeft;
	private: System::Windows::Forms::ToolStripMenuItem^ menuShiftRight;
	private: System::Windows::Forms::ToolStripMenuItem^ menuSortChoiceDown;
	private: System::Windows::Forms::ToolStripMenuItem^ menuSortChoiceUp;
	private: System::Windows::Forms::ToolStripMenuItem^ menuSortBubbleDown;
	private: System::Windows::Forms::ToolStripMenuItem^ menuSortBubbleUp;
	private: System::Windows::Forms::ToolStripMenuItem^ menuSortQuickDown;
	private: System::Windows::Forms::ToolStripMenuItem^ menuSortQuickUp;
	private: System::Windows::Forms::ToolStripMenuItem^ menuEditArraySort;
	private: System::ComponentModel::IContainer^ components;
	private: System::Windows::Forms::ContextMenuStrip^ contextMenuShapes;
	private: System::Windows::Forms::ToolStripMenuItem^ создатьОбъектToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ изменитьЦветОToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ contextMenuCreateRectangle;
	private: System::Windows::Forms::ToolStripMenuItem^ contextMenuCreateSquare;
	private: System::Windows::Forms::ToolStripMenuItem^ contextMenuCreateEllipse;
	private: System::Windows::Forms::ToolStripMenuItem^ contextMenuCreateTriangle;
	private: System::Windows::Forms::ToolStripMenuItem^ contextMenuEditBackground;
	private: System::Windows::Forms::ToolStripMenuItem^ contextMenuEditPen;
	private: System::Windows::Forms::ToolStripMenuItem^ изменитьРазмерОбъектаToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ contextMenuEditWidth;
	private: System::Windows::Forms::ToolStripMenuItem^ contextMenuSave;
	private: System::Windows::Forms::ToolStripMenuItem^ contextMenuLoad;
	private: System::Windows::Forms::ToolStripMenuItem^ contextMenuEditHeight;
	private: System::Windows::Forms::ColorDialog^ colorDialog;
	private: System::Windows::Forms::ToolStripMenuItem^ menuParametricFunction;

	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->menuMain = (gcnew System::Windows::Forms::MenuStrip());
			this->menuMask = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuFirstTerm = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuAbout = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuLab21 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuLab22 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuLab32 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuLab4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuParametricFunction = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuMaze = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuPlayMaze = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuRouteMaze = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuRecursion = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSort = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSortChoice = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSortChoiceDown = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSortChoiceUp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSortBubble = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSortBubbleDown = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSortBubbleUp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuFastSort = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSortQuickDown = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSortQuickUp = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuEditArraySort = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuEncryption = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuEncCaeser = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuEncDynCaeser = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuEncBit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuShiftLeft = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuShiftRight = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuClass = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuCreateObjects = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuCreateTriangle = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuCreateRectangle = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuCreateEllipse = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuUnionObjetcs = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuOnUnion = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuOffUnion = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuUpdateShapes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuSaveShapes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuLoadShapes = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->menuExit = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panelTitle = (gcnew System::Windows::Forms::Panel());
			this->textboxTitle = (gcnew System::Windows::Forms::TextBox());
			this->panelOutput = (gcnew System::Windows::Forms::Panel());
			this->listBoxOutput = (gcnew System::Windows::Forms::ListBox());
			this->contextMenuShapes = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->создатьОбъектToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuCreateRectangle = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuCreateSquare = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuCreateEllipse = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuCreateTriangle = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->изменитьЦветОToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuEditBackground = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuEditPen = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->изменитьРазмерОбъектаToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuEditWidth = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuEditHeight = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuSave = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->contextMenuLoad = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->colorDialog = (gcnew System::Windows::Forms::ColorDialog());
			this->menuMain->SuspendLayout();
			this->panelTitle->SuspendLayout();
			this->panelOutput->SuspendLayout();
			this->contextMenuShapes->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuMain
			// 
			this->menuMain->BackColor = System::Drawing::SystemColors::MenuBar;
			this->menuMain->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->menuMain->ImageScalingSize = System::Drawing::Size(20, 20);
			this->menuMain->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(8) {
				this->menuMask, this->menuFirstTerm,
					this->menuMaze, this->menuRecursion, this->menuSort, this->menuEncryption, this->menuClass, this->menuExit
			});
			this->menuMain->LayoutStyle = System::Windows::Forms::ToolStripLayoutStyle::HorizontalStackWithOverflow;
			this->menuMain->Location = System::Drawing::Point(0, 0);
			this->menuMain->Name = L"menuMain";
			this->menuMain->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
			this->menuMain->Size = System::Drawing::Size(1508, 28);
			this->menuMain->TabIndex = 2;
			this->menuMain->Text = L"menuMain";
			// 
			// menuMask
			// 
			this->menuMask->Name = L"menuMask";
			this->menuMask->Size = System::Drawing::Size(60, 24);
			this->menuMask->Text = L"Маска";
			this->menuMask->Click += gcnew System::EventHandler(this, &MainForm::menuMask_Click);
			// 
			// menuFirstTerm
			// 
			this->menuFirstTerm->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
				this->menuAbout,
					this->menuLab21, this->menuLab22, this->menuLab32, this->menuLab4, this->menuParametricFunction
			});
			this->menuFirstTerm->Name = L"menuFirstTerm";
			this->menuFirstTerm->Size = System::Drawing::Size(93, 24);
			this->menuFirstTerm->Text = L"1-й семестр";
			// 
			// menuAbout
			// 
			this->menuAbout->Name = L"menuAbout";
			this->menuAbout->Size = System::Drawing::Size(262, 26);
			this->menuAbout->Text = L"Сведения о программисте";
			this->menuAbout->Click += gcnew System::EventHandler(this, &MainForm::menuAbout_Click);
			// 
			// menuLab21
			// 
			this->menuLab21->Name = L"menuLab21";
			this->menuLab21->Size = System::Drawing::Size(262, 26);
			this->menuLab21->Text = L"Лабораторная работа №2.1";
			this->menuLab21->Click += gcnew System::EventHandler(this, &MainForm::menuLab21_Click);
			// 
			// menuLab22
			// 
			this->menuLab22->Name = L"menuLab22";
			this->menuLab22->Size = System::Drawing::Size(262, 26);
			this->menuLab22->Text = L"Лабораторная работа №2.2";
			this->menuLab22->Click += gcnew System::EventHandler(this, &MainForm::menuLab22_Click);
			// 
			// menuLab32
			// 
			this->menuLab32->Name = L"menuLab32";
			this->menuLab32->Size = System::Drawing::Size(262, 26);
			this->menuLab32->Text = L"Лабораторная работа №3.2";
			this->menuLab32->Click += gcnew System::EventHandler(this, &MainForm::menuLab32_Click);
			// 
			// menuLab4
			// 
			this->menuLab4->Name = L"menuLab4";
			this->menuLab4->Size = System::Drawing::Size(262, 26);
			this->menuLab4->Text = L"Лабораторная работа №4";
			this->menuLab4->Click += gcnew System::EventHandler(this, &MainForm::menuLab4_Click);
			// 
			// menuParametricFunction
			// 
			this->menuParametricFunction->Name = L"menuParametricFunction";
			this->menuParametricFunction->Size = System::Drawing::Size(262, 26);
			this->menuParametricFunction->Text = L"Параметрическая функция";
			this->menuParametricFunction->Click += gcnew System::EventHandler(this, &MainForm::menuParametricFunction_Click);
			// 
			// menuMaze
			// 
			this->menuMaze->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuPlayMaze,
					this->menuRouteMaze
			});
			this->menuMaze->Name = L"menuMaze";
			this->menuMaze->Size = System::Drawing::Size(80, 24);
			this->menuMaze->Text = L"Лабиринт";
			// 
			// menuPlayMaze
			// 
			this->menuPlayMaze->Name = L"menuPlayMaze";
			this->menuPlayMaze->Size = System::Drawing::Size(214, 26);
			this->menuPlayMaze->Text = L"Пройти лабиринт";
			this->menuPlayMaze->Click += gcnew System::EventHandler(this, &MainForm::menuPlayMaze_Click);
			// 
			// menuRouteMaze
			// 
			this->menuRouteMaze->Name = L"menuRouteMaze";
			this->menuRouteMaze->Size = System::Drawing::Size(214, 26);
			this->menuRouteMaze->Text = L"Маршрут лабиринта";
			this->menuRouteMaze->Click += gcnew System::EventHandler(this, &MainForm::menuRouteMaze_Click);
			// 
			// menuRecursion
			// 
			this->menuRecursion->Name = L"menuRecursion";
			this->menuRecursion->Size = System::Drawing::Size(133, 24);
			this->menuRecursion->Text = L"Рекурсия и график";
			this->menuRecursion->Click += gcnew System::EventHandler(this, &MainForm::menuRecursion_Click);
			// 
			// menuSort
			// 
			this->menuSort->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->menuSortChoice,
					this->menuSortBubble, this->menuFastSort, this->menuEditArraySort
			});
			this->menuSort->Name = L"menuSort";
			this->menuSort->Size = System::Drawing::Size(94, 24);
			this->menuSort->Text = L"Сортировка";
			// 
			// menuSortChoice
			// 
			this->menuSortChoice->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuSortChoiceDown,
					this->menuSortChoiceUp
			});
			this->menuSortChoice->Name = L"menuSortChoice";
			this->menuSortChoice->Size = System::Drawing::Size(232, 26);
			this->menuSortChoice->Text = L"Сортировка выбором";
			// 
			// menuSortChoiceDown
			// 
			this->menuSortChoiceDown->Name = L"menuSortChoiceDown";
			this->menuSortChoiceDown->Size = System::Drawing::Size(191, 26);
			this->menuSortChoiceDown->Text = L"По убыванию";
			this->menuSortChoiceDown->Click += gcnew System::EventHandler(this, &MainForm::menuSortChoiceDown_Click);
			// 
			// menuSortChoiceUp
			// 
			this->menuSortChoiceUp->Name = L"menuSortChoiceUp";
			this->menuSortChoiceUp->Size = System::Drawing::Size(191, 26);
			this->menuSortChoiceUp->Text = L"По возростанию";
			this->menuSortChoiceUp->Click += gcnew System::EventHandler(this, &MainForm::menuSortChoiceUp_Click);
			// 
			// menuSortBubble
			// 
			this->menuSortBubble->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuSortBubbleDown,
					this->menuSortBubbleUp
			});
			this->menuSortBubble->Name = L"menuSortBubble";
			this->menuSortBubble->Size = System::Drawing::Size(232, 26);
			this->menuSortBubble->Text = L"Сортировка пузырьком";
			// 
			// menuSortBubbleDown
			// 
			this->menuSortBubbleDown->Name = L"menuSortBubbleDown";
			this->menuSortBubbleDown->Size = System::Drawing::Size(191, 26);
			this->menuSortBubbleDown->Text = L"По убыванию";
			this->menuSortBubbleDown->Click += gcnew System::EventHandler(this, &MainForm::menuSortBubbleDown_Click);
			// 
			// menuSortBubbleUp
			// 
			this->menuSortBubbleUp->Name = L"menuSortBubbleUp";
			this->menuSortBubbleUp->Size = System::Drawing::Size(191, 26);
			this->menuSortBubbleUp->Text = L"По возростанию";
			this->menuSortBubbleUp->Click += gcnew System::EventHandler(this, &MainForm::menuSortBubbleUp_Click);
			// 
			// menuFastSort
			// 
			this->menuFastSort->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuSortQuickDown,
					this->menuSortQuickUp
			});
			this->menuFastSort->Name = L"menuFastSort";
			this->menuFastSort->Size = System::Drawing::Size(232, 26);
			this->menuFastSort->Text = L"Быстрая сортировка";
			// 
			// menuSortQuickDown
			// 
			this->menuSortQuickDown->Name = L"menuSortQuickDown";
			this->menuSortQuickDown->Size = System::Drawing::Size(191, 26);
			this->menuSortQuickDown->Text = L"По убыванию";
			this->menuSortQuickDown->Click += gcnew System::EventHandler(this, &MainForm::menuSortQuickDown_Click);
			// 
			// menuSortQuickUp
			// 
			this->menuSortQuickUp->Name = L"menuSortQuickUp";
			this->menuSortQuickUp->Size = System::Drawing::Size(191, 26);
			this->menuSortQuickUp->Text = L"По возростанию";
			this->menuSortQuickUp->Click += gcnew System::EventHandler(this, &MainForm::menuSortQuickUp_Click);
			// 
			// menuEditArraySort
			// 
			this->menuEditArraySort->Name = L"menuEditArraySort";
			this->menuEditArraySort->Size = System::Drawing::Size(232, 26);
			this->menuEditArraySort->Text = L"Изменить массив";
			this->menuEditArraySort->Click += gcnew System::EventHandler(this, &MainForm::menuEditArraySort_Click);
			// 
			// menuEncryption
			// 
			this->menuEncryption->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->menuEncCaeser,
					this->menuEncDynCaeser, this->menuEncBit
			});
			this->menuEncryption->Name = L"menuEncryption";
			this->menuEncryption->Size = System::Drawing::Size(102, 24);
			this->menuEncryption->Text = L"Шифрование";
			// 
			// menuEncCaeser
			// 
			this->menuEncCaeser->Name = L"menuEncCaeser";
			this->menuEncCaeser->Size = System::Drawing::Size(225, 26);
			this->menuEncCaeser->Text = L"Цезарь";
			this->menuEncCaeser->Click += gcnew System::EventHandler(this, &MainForm::menuEncCaeser_Click);
			// 
			// menuEncDynCaeser
			// 
			this->menuEncDynCaeser->Name = L"menuEncDynCaeser";
			this->menuEncDynCaeser->Size = System::Drawing::Size(225, 26);
			this->menuEncDynCaeser->Text = L"Динамический Цезарь";
			this->menuEncDynCaeser->Click += gcnew System::EventHandler(this, &MainForm::menuEncDynCaeser_Click);
			// 
			// menuEncBit
			// 
			this->menuEncBit->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuShiftLeft,
					this->menuShiftRight
			});
			this->menuEncBit->Name = L"menuEncBit";
			this->menuEncBit->Size = System::Drawing::Size(225, 26);
			this->menuEncBit->Text = L"Сдвигом N-бит";
			// 
			// menuShiftLeft
			// 
			this->menuShiftLeft->Name = L"menuShiftLeft";
			this->menuShiftLeft->Size = System::Drawing::Size(172, 26);
			this->menuShiftLeft->Text = L"Сдвиг влево";
			this->menuShiftLeft->Click += gcnew System::EventHandler(this, &MainForm::menuShiftLeft_Click);
			// 
			// menuShiftRight
			// 
			this->menuShiftRight->Name = L"menuShiftRight";
			this->menuShiftRight->Size = System::Drawing::Size(172, 26);
			this->menuShiftRight->Text = L"Сдвиг вправо";
			this->menuShiftRight->Click += gcnew System::EventHandler(this, &MainForm::menuShiftRight_Click);
			// 
			// menuClass
			// 
			this->menuClass->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->menuCreateObjects,
					this->menuUnionObjetcs, this->menuUpdateShapes, this->menuSaveShapes, this->menuLoadShapes
			});
			this->menuClass->Name = L"menuClass";
			this->menuClass->Size = System::Drawing::Size(65, 24);
			this->menuClass->Text = L"Классы";
			this->menuClass->Click += gcnew System::EventHandler(this, &MainForm::menuClass_Click);
			// 
			// menuCreateObjects
			// 
			this->menuCreateObjects->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->menuCreateTriangle,
					this->menuCreateRectangle, this->menuCreateEllipse
			});
			this->menuCreateObjects->Name = L"menuCreateObjects";
			this->menuCreateObjects->Size = System::Drawing::Size(208, 26);
			this->menuCreateObjects->Text = L"Создать объект";
			// 
			// menuCreateTriangle
			// 
			this->menuCreateTriangle->Name = L"menuCreateTriangle";
			this->menuCreateTriangle->Size = System::Drawing::Size(184, 26);
			this->menuCreateTriangle->Text = L"Треугольник";
			this->menuCreateTriangle->Click += gcnew System::EventHandler(this, &MainForm::menuCreateTriangle_Click);
			// 
			// menuCreateRectangle
			// 
			this->menuCreateRectangle->Name = L"menuCreateRectangle";
			this->menuCreateRectangle->Size = System::Drawing::Size(184, 26);
			this->menuCreateRectangle->Text = L"Прямоугольник";
			this->menuCreateRectangle->Click += gcnew System::EventHandler(this, &MainForm::menuCreateRectangle_Click);
			// 
			// menuCreateEllipse
			// 
			this->menuCreateEllipse->Name = L"menuCreateEllipse";
			this->menuCreateEllipse->Size = System::Drawing::Size(184, 26);
			this->menuCreateEllipse->Text = L"Эллипс";
			this->menuCreateEllipse->Click += gcnew System::EventHandler(this, &MainForm::menuCreateEllipse_Click);
			// 
			// menuUnionObjetcs
			// 
			this->menuUnionObjetcs->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->menuOnUnion,
					this->menuOffUnion
			});
			this->menuUnionObjetcs->Name = L"menuUnionObjetcs";
			this->menuUnionObjetcs->Size = System::Drawing::Size(208, 26);
			this->menuUnionObjetcs->Text = L"Соеденить объекты";
			// 
			// menuOnUnion
			// 
			this->menuOnUnion->Name = L"menuOnUnion";
			this->menuOnUnion->Size = System::Drawing::Size(156, 26);
			this->menuOnUnion->Text = L"Включить";
			this->menuOnUnion->Click += gcnew System::EventHandler(this, &MainForm::menuOnUnion_Click);
			// 
			// menuOffUnion
			// 
			this->menuOffUnion->Name = L"menuOffUnion";
			this->menuOffUnion->Size = System::Drawing::Size(156, 26);
			this->menuOffUnion->Text = L"Выключить";
			this->menuOffUnion->Click += gcnew System::EventHandler(this, &MainForm::menuOffUnion_Click);
			// 
			// menuUpdateShapes
			// 
			this->menuUpdateShapes->Name = L"menuUpdateShapes";
			this->menuUpdateShapes->Size = System::Drawing::Size(208, 26);
			this->menuUpdateShapes->Text = L"Обновить";
			this->menuUpdateShapes->Click += gcnew System::EventHandler(this, &MainForm::menuUpdateShapes_Click);
			// 
			// menuSaveShapes
			// 
			this->menuSaveShapes->Name = L"menuSaveShapes";
			this->menuSaveShapes->Size = System::Drawing::Size(208, 26);
			this->menuSaveShapes->Text = L"Сохранить карту";
			this->menuSaveShapes->Click += gcnew System::EventHandler(this, &MainForm::menuSaveShapes_Click);
			// 
			// menuLoadShapes
			// 
			this->menuLoadShapes->Name = L"menuLoadShapes";
			this->menuLoadShapes->Size = System::Drawing::Size(208, 26);
			this->menuLoadShapes->Text = L"Загрузить карту";
			this->menuLoadShapes->Click += gcnew System::EventHandler(this, &MainForm::menuLoadShapes_Click);
			// 
			// menuExit
			// 
			this->menuExit->Name = L"menuExit";
			this->menuExit->ShortcutKeys = static_cast<System::Windows::Forms::Keys>((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::X));
			this->menuExit->Size = System::Drawing::Size(150, 24);
			this->menuExit->Text = L"Выход из программы";
			this->menuExit->Click += gcnew System::EventHandler(this, &MainForm::menuExit_Click);
			// 
			// panelTitle
			// 
			this->panelTitle->Controls->Add(this->textboxTitle);
			this->panelTitle->Dock = System::Windows::Forms::DockStyle::Top;
			this->panelTitle->Location = System::Drawing::Point(0, 28);
			this->panelTitle->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelTitle->Name = L"panelTitle";
			this->panelTitle->Size = System::Drawing::Size(1508, 175);
			this->panelTitle->TabIndex = 3;
			// 
			// textboxTitle
			// 
			this->textboxTitle->BackColor = System::Drawing::SystemColors::Window;
			this->textboxTitle->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textboxTitle->Enabled = false;
			this->textboxTitle->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textboxTitle->Location = System::Drawing::Point(0, 0);
			this->textboxTitle->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->textboxTitle->Multiline = true;
			this->textboxTitle->Name = L"textboxTitle";
			this->textboxTitle->Size = System::Drawing::Size(1508, 175);
			this->textboxTitle->TabIndex = 0;
			this->textboxTitle->Text = L"Здесь пишем задания и описание задачи";
			// 
			// panelOutput
			// 
			this->panelOutput->Controls->Add(this->listBoxOutput);
			this->panelOutput->Dock = System::Windows::Forms::DockStyle::Left;
			this->panelOutput->Location = System::Drawing::Point(0, 203);
			this->panelOutput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelOutput->Name = L"panelOutput";
			this->panelOutput->Size = System::Drawing::Size(534, 560);
			this->panelOutput->TabIndex = 4;
			// 
			// listBoxOutput
			// 
			this->listBoxOutput->Dock = System::Windows::Forms::DockStyle::Fill;
			this->listBoxOutput->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBoxOutput->FormattingEnabled = true;
			this->listBoxOutput->ItemHeight = 28;
			this->listBoxOutput->Location = System::Drawing::Point(0, 0);
			this->listBoxOutput->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listBoxOutput->Name = L"listBoxOutput";
			this->listBoxOutput->Size = System::Drawing::Size(534, 560);
			this->listBoxOutput->TabIndex = 0;
			this->listBoxOutput->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::listBoxOutput_KeyDown);
			// 
			// contextMenuShapes
			// 
			this->contextMenuShapes->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuShapes->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->создатьОбъектToolStripMenuItem,
					this->изменитьЦветОToolStripMenuItem, this->изменитьРазмерОбъектаToolStripMenuItem, this->contextMenuSave, this->contextMenuLoad
			});
			this->contextMenuShapes->Name = L"contextMenuShapes";
			this->contextMenuShapes->Size = System::Drawing::Size(264, 124);
			// 
			// создатьОбъектToolStripMenuItem
			// 
			this->создатьОбъектToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->contextMenuCreateRectangle,
					this->contextMenuCreateSquare, this->contextMenuCreateEllipse, this->contextMenuCreateTriangle
			});
			this->создатьОбъектToolStripMenuItem->Name = L"создатьОбъектToolStripMenuItem";
			this->создатьОбъектToolStripMenuItem->Size = System::Drawing::Size(263, 24);
			this->создатьОбъектToolStripMenuItem->Text = L"Создать объект";
			// 
			// contextMenuCreateRectangle
			// 
			this->contextMenuCreateRectangle->Name = L"contextMenuCreateRectangle";
			this->contextMenuCreateRectangle->Size = System::Drawing::Size(203, 26);
			this->contextMenuCreateRectangle->Text = L"Прямоугольник";
			this->contextMenuCreateRectangle->Click += gcnew System::EventHandler(this, &MainForm::contextMenuCreateRectangle_Click);
			// 
			// contextMenuCreateSquare
			// 
			this->contextMenuCreateSquare->Name = L"contextMenuCreateSquare";
			this->contextMenuCreateSquare->Size = System::Drawing::Size(203, 26);
			this->contextMenuCreateSquare->Text = L"Квадрат";
			this->contextMenuCreateSquare->Click += gcnew System::EventHandler(this, &MainForm::contextMenuCreateSquare_Click);
			// 
			// contextMenuCreateEllipse
			// 
			this->contextMenuCreateEllipse->Name = L"contextMenuCreateEllipse";
			this->contextMenuCreateEllipse->Size = System::Drawing::Size(203, 26);
			this->contextMenuCreateEllipse->Text = L"Эллипс";
			this->contextMenuCreateEllipse->Click += gcnew System::EventHandler(this, &MainForm::contextMenuCreateEllipse_Click);
			// 
			// contextMenuCreateTriangle
			// 
			this->contextMenuCreateTriangle->Name = L"contextMenuCreateTriangle";
			this->contextMenuCreateTriangle->Size = System::Drawing::Size(203, 26);
			this->contextMenuCreateTriangle->Text = L"Треугольник";
			this->contextMenuCreateTriangle->Click += gcnew System::EventHandler(this, &MainForm::contextMenuCreateTriangle_Click);
			// 
			// изменитьЦветОToolStripMenuItem
			// 
			this->изменитьЦветОToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->contextMenuEditBackground,
					this->contextMenuEditPen
			});
			this->изменитьЦветОToolStripMenuItem->Name = L"изменитьЦветОToolStripMenuItem";
			this->изменитьЦветОToolStripMenuItem->Size = System::Drawing::Size(263, 24);
			this->изменитьЦветОToolStripMenuItem->Text = L"Изменить цвет объекта";
			// 
			// contextMenuEditBackground
			// 
			this->contextMenuEditBackground->Name = L"contextMenuEditBackground";
			this->contextMenuEditBackground->Size = System::Drawing::Size(255, 26);
			this->contextMenuEditBackground->Text = L"Изменить цвет фона";
			this->contextMenuEditBackground->Click += gcnew System::EventHandler(this, &MainForm::contextMenuEditBackground_Click);
			// 
			// contextMenuEditPen
			// 
			this->contextMenuEditPen->Name = L"contextMenuEditPen";
			this->contextMenuEditPen->Size = System::Drawing::Size(255, 26);
			this->contextMenuEditPen->Text = L"Изменить цвет контура";
			this->contextMenuEditPen->Click += gcnew System::EventHandler(this, &MainForm::contextMenuEditPen_Click);
			// 
			// изменитьРазмерОбъектаToolStripMenuItem
			// 
			this->изменитьРазмерОбъектаToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->contextMenuEditWidth,
					this->contextMenuEditHeight
			});
			this->изменитьРазмерОбъектаToolStripMenuItem->Name = L"изменитьРазмерОбъектаToolStripMenuItem";
			this->изменитьРазмерОбъектаToolStripMenuItem->Size = System::Drawing::Size(263, 24);
			this->изменитьРазмерОбъектаToolStripMenuItem->Text = L"Изменить размер объекта";
			// 
			// contextMenuEditWidth
			// 
			this->contextMenuEditWidth->Name = L"contextMenuEditWidth";
			this->contextMenuEditWidth->Size = System::Drawing::Size(220, 26);
			this->contextMenuEditWidth->Text = L"Изменить ширину";
			this->contextMenuEditWidth->Click += gcnew System::EventHandler(this, &MainForm::contextMenuEditWidth_Click);
			// 
			// contextMenuEditHeight
			// 
			this->contextMenuEditHeight->Name = L"contextMenuEditHeight";
			this->contextMenuEditHeight->Size = System::Drawing::Size(220, 26);
			this->contextMenuEditHeight->Text = L"Изменить высоту";
			this->contextMenuEditHeight->Click += gcnew System::EventHandler(this, &MainForm::contextMenuEditHeight_Click);
			// 
			// contextMenuSave
			// 
			this->contextMenuSave->Name = L"contextMenuSave";
			this->contextMenuSave->Size = System::Drawing::Size(263, 24);
			this->contextMenuSave->Text = L"Сохранить карту";
			this->contextMenuSave->Click += gcnew System::EventHandler(this, &MainForm::menuSaveShapes_Click);
			// 
			// contextMenuLoad
			// 
			this->contextMenuLoad->Name = L"contextMenuLoad";
			this->contextMenuLoad->Size = System::Drawing::Size(263, 24);
			this->contextMenuLoad->Text = L"Загрузить карту";
			this->contextMenuLoad->Click += gcnew System::EventHandler(this, &MainForm::menuLoadShapes_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1508, 763);
			this->Controls->Add(this->panelOutput);
			this->Controls->Add(this->panelTitle);
			this->Controls->Add(this->menuMain);
			this->MainMenuStrip = this->menuMain;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"MainForm";
			this->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->ShowIcon = false;
			this->Text = L"Ознакомительная практика";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Activated += gcnew System::EventHandler(this, &MainForm::MainForm_Activated);
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::MainForm_Paint);
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyDown);
			this->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MainForm::MainForm_KeyPress);
			this->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDoubleClick);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
			this->menuMain->ResumeLayout(false);
			this->menuMain->PerformLayout();
			this->panelTitle->ResumeLayout(false);
			this->panelTitle->PerformLayout();
			this->panelOutput->ResumeLayout(false);
			this->contextMenuShapes->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//МОИ ФУНКЦИИ
		public: void EncryptionView(int model)
		{
			int bitEnc = 0;
			ClearOldTask();
			textboxTitle->Text = "Задание: шифрование.\r\nПеревод строки в шифрованное методом ";
			switch (model)
			{
			case 0:
				textboxTitle->AppendText("Цезаря.");
				break;
			case 1:
				textboxTitle->AppendText("динамического Цезаря.");
				break;
			case 2: case 3:
				textboxTitle->AppendText("побитового сдвига.");
				break;
			}
			Input_DialogForm^ idf = gcnew Input_DialogForm;
			if (model == 2 || model == 3)
			{
				idf->SetLabel("Введите количество бит, на которое будет произведён сдвиг текста");
				if (idf->ShowDialog() != System::Windows::Forms::DialogResult::OK)
				{
					idf->Close();
					textboxTitle->AppendText("\r\nОтмененно!");
					return;
				}
				bitEnc = Convert::ToInt32(idf->GetDialogData());
			}
			idf->SetLabel("Введите текст для шифрования");
			if (idf->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				idf->Close();
				textboxTitle->AppendText("\r\nОтмененно!");
				return;
			}
			String^ stext = idf->GetDialogData();
			textboxTitle->AppendText("\r\nВведённая строка: \'");
			textboxTitle->AppendText(stext + "\'");
			std::string ss;
			StringToChar(stext, ss);
			SetPhrase(ss);
			switch (model)
			{
			case 0:
				EncryptCaeser();
				break;
			case 1:
				EncryptDynamicCaeser();
				break;
			case 2:
				EncryptBitShift(true, bitEnc);
				break;
			case 3:
				EncryptBitShift(false, bitEnc);
				break;
			}
			listBoxOutput->Items->Add("Зашифрованный текст: ");
			listBoxOutput->Items->Add(CharToString(const_cast<char*>((GetEncPhrase()).c_str())));
			Decoding();
			listBoxOutput->Items->Add(" ");
			listBoxOutput->Items->Add("Расшифрованный текст: ");
			listBoxOutput->Items->Add(CharToString(const_cast<char*>((GetEncPhrase()).c_str())));
		}
		
		public: void SortingView(int model)
		{
			{
				ClearOldTask();
				textboxTitle->Text = "Задание: сортировка.\r\nСортировка массива ";
				switch (model)
				{
				case 0: case 1:
					textboxTitle->AppendText("выбором.");
					break;
				case 2: case 3:
					textboxTitle->AppendText("пузырьком.");
					break;
				case 4: case 5:
					textboxTitle->AppendText("быстрым методом.");
					break;
				}
				textboxTitle->AppendText("\r\nНиже представлен уже отсортированный массив.");
				switch (model)
				{
				case 0:
					SetOrient(false);
					SortingSelection();
					break;
				case 1:
					SetOrient(true);
					SortingSelection();
					break;
				case 2:
					SetOrient(false);
					SortingBubble();
					break;
				case 3:
					SetOrient(true);
					SortingBubble();
					break;
				case 4:
					SetOrient(false);
					SortingQuick();
					break;
				case 5:
					SetOrient(true);
					SortingQuick();
					break;
				}

				for (int i = 0; i < GetSizeArray(); i++)
				{
					std::string result = GetElementSortingArray(i);
					listBoxOutput->Items->Add(CharToString(const_cast<char*>(result.c_str())));
				}

				textboxTitle->AppendText("\r\n\r\nВремя в тиках, которое понадобилось для сортировки: " + GetTime());
			}
		}

		public: void Recursion();

		public: void ParametricFunction();

		public: void BranchingAlgorithmFirst();

		public: void BranchingAlgorithmSecond();
		
		public: void ProcessingOneDimensionalArray();
		public: void Matrix();

		private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e)
		{
			ClearOldTask();
		}

		private: System::Void MainForm_Activated(System::Object^ sender, System::EventArgs^ e)
		{

		}
		private: System::Void menuExit_Click(System::Object^ sender, System::EventArgs^ e)
		{
			exit(0);
		}

		private: System::Void menuMask_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ClearOldTask();
			textboxTitle->Text = "Задание: маска.\r\nВывести числа, удовлетворяющие маске.\r\nДаны 20 элементов, далее нужно ввести маску в диалоговом окне. После чего будет выведен результат.";

			Input_DialogForm^ f_input = gcnew Input_DialogForm;
			f_input->SetLabel("Введите маску");
			if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				cMask mask;
				String^ sResult = f_input->GetDialogData();
				if (sResult == "") return;
				int nResult = Convert::ToInt32(sResult);
				mask.CalcMask(nResult);
				for (int i = 0; i < mask.count; i++)
				{
					listBoxOutput->Items->Add(mask.GetResultNum(i));
				}
				textboxTitle->AppendText("\r\nРезультат приведён в окне под названием Output.");
				f_input->Close();
			}
			else
			{
				f_input->Close();
				return;
			}
		}

		private: System::Void menuAbout_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ClearOldTask();
			textboxTitle->Text = "Данная программа разработана в целях ознакомительной практики в разработке графических программ, основанных на C++ с использованием элементов C#.\r\nНиже представлена вся информация о разработчике.";
			listBoxOutput->Items->Add("Учебное заведение: МАДИ");
			listBoxOutput->Items->Add("Студент: Гоглов Максим Алексеевич");
			listBoxOutput->Items->Add("Группа: бИТС2");
			listBoxOutput->Items->Add("Дата разработки: 2024 год");
		}

		private: System::Void menuEncCaeser_Click(System::Object^ sender, System::EventArgs^ e)
		{
			EncryptionView(0);
		}
		private: System::Void menuEncDynCaeser_Click(System::Object^ sender, System::EventArgs^ e)
		{
			EncryptionView(1);
		}
		private: System::Void menuShiftLeft_Click(System::Object^ sender, System::EventArgs^ e)
		{
			EncryptionView(2);
		}
		private: System::Void menuShiftRight_Click(System::Object^ sender, System::EventArgs^ e)
		{
			EncryptionView(3);
		}

		private: System::Void menuSortChoiceDown_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			SortingView(0);
		}
		private: System::Void menuSortChoiceUp_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			SortingView(1);
		}

		private: System::Void menuSortBubbleDown_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SortingView(2);
		}
		private: System::Void menuSortBubbleUp_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SortingView(3);
		}
		private: System::Void menuSortQuickDown_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SortingView(4);
		}
		private: System::Void menuSortQuickUp_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SortingView(5);
		}

		private: System::Void menuEditArraySort_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ClearOldTask();
			textboxTitle->Text = "Задание: сортировка.\r\nВыбрано: изменить массив.\r\nВведите номер слова, который вы бы хотели изменить.";

			for (int i = 0; i < GetSizeArray(); i++)
			{
				std::string result = GetElementSortingArray(i);
				listBoxOutput->Items->Add((i + 1) + ". " + CharToString(const_cast<char*>(result.c_str())));
			}

			Input_DialogForm^ idf = gcnew Input_DialogForm;
			idf->SetLabel("Введите номер слова, который Вы хотите изменить");
			if (idf->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				idf->Close();
				textboxTitle->AppendText("\r\nОтменено!");
				return;
			}
			int nResult = Convert::ToInt32(idf->GetDialogData());
			idf->Close();
			textboxTitle->AppendText("\r\nВведите слово, которое Вы бы хотели видеть в этом месте");

			Input_DialogForm^ idf_second = gcnew Input_DialogForm;
			idf_second->SetLabel("Введите слово");
			if (idf_second->ShowDialog() != System::Windows::Forms::DialogResult::OK)
			{
				idf_second->Close();
				textboxTitle->AppendText("\r\nОтменено!");
				return;
			}
			String^ sResult = idf_second->GetDialogData();
			idf_second->Close();
			std::string ss;
			StringToChar(sResult, ss);
			SetElementSortingArray(ss, nResult - 1);

			ClearOldTask();
			textboxTitle->Text = "Готово! Теперь массив для сортировки выглядит так:";
			for (int i = 0; i < GetSizeArray(); i++)
			{
				std::string result = GetElementSortingArray(i);
				listBoxOutput->Items->Add((i + 1) + ". " + CharToString(const_cast<char*>(result.c_str())));
			}
		}

		private: System::Void menuRecursion_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Recursion();
			onaction = act_RECURSION;
			Refresh();
		}

		private: System::Void MainForm_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) 
		{
			switch (onaction) 
			{
			case act_MAZE: 
			{
				panelOutput->Visible = false;
				onaction = MazeDraw(e->Graphics);
				if (onaction == act_MAZEEXIT) Refresh();
			} break;
			case act_MAZEEXIT:
			{
				panelOutput->Visible = true;
				listBoxOutput->Items->Clear();
				listBoxOutput->Items->Add("Жук достиг выхода лабиринта. Задание окончено.");
				MazeDraw(e->Graphics);
			} break;
			case act_MAZEPATH:
			{
				MazeDraw(e->Graphics);
				StartMoving(e->Graphics);
				onaction = act_MAZE;
			} break;
			case act_BREAK:
			{
				panelOutput->Visible = true;
				listBoxOutput->Items->Clear();
				listBoxOutput->Items->Add("Операция прервана оператором.");
				onaction = DEFAULT;
			} break;
			case act_RECURSION:
			{
				RECT rct{500, 200, 1300, 600};
				panelOutput->Visible = true;
				drawGraph(e->Graphics, RecOut, 10, rct);
				this->Focus();
			} break;
			case act_CLASSES:
			{
				panelOutput->Visible = false;
				if (mng == 0) return;
				mng->Draw(e->Graphics);
				if (ActiveClass != 0)
				{
					Pen^ pen = gcnew Pen(Color::Red, 4);
					System::Drawing::Rectangle rc(ActiveClass->X, ActiveClass->Y, ActiveClass->Width, ActiveClass->Height);
					e->Graphics->DrawRectangle(pen, rc);
				}
			} break;
			case act_UNIT:
			{
				panelOutput->Visible = false;
				if (mng == 0) return;
				mng->Draw(e->Graphics);
				if (ActiveClass)
				{
					Pen^ pen = gcnew Pen(Color::Red, 4);

					pen->Color = Color::Black;
					e->Graphics->DrawLine(pen, ActiveClass->MiddleX, ActiveClass->MiddleY, mx, my);
				}
			} break;
			default:
				panelOutput->Visible = true;
				break;
			}
		}
		private: System::Void MainForm_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			onaction = DEFAULT;
			listBoxOutput->Items->Clear();
			Refresh();
		}

		private: System::Void MainForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
		{
			switch (e->KeyData)
			{
			case System::Windows::Forms::Keys::F5:
				onaction = DEFAULT;
				listBoxOutput->Items->Clear();
				Refresh();
				break;
			case System::Windows::Forms::Keys::F9:
				if (onaction == act_UNIT) onaction = act_CLASSES;
				else if (onaction == act_CLASSES) onaction = act_UNIT;
				Refresh();
				break;
			}

			if (onaction == act_MAZE)
			{
				switch (e->KeyData)
				{
				case System::Windows::Forms::Keys::Escape:
					onaction = act_BREAK; 
					Refresh(); 
					break;
				case System::Windows::Forms::Keys::F:
					onaction = act_MAZEPATH;
					Refresh();
					break;
				case System::Windows::Forms::Keys::Up: case System::Windows::Forms::Keys::Down: case System::Windows::Forms::Keys::Left: case System::Windows::Forms::Keys::Right:
					MazeKeys(e->KeyValue);
					Refresh();
					break;
				}
			}
		}

		private: System::Void MainForm_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) 
		{
			if (onaction == act_MAZE)
			{
				switch (e->KeyChar)
				{
				case 27:
					onaction = act_BREAK;
					Refresh();
					break;
				case 115:
					onaction = act_MAZEPATH;
					Refresh();
					break;
				case 37: case 38: case 39: case 40:
					//Maze.Keys(e->KeyChar);
					//Refresh();
					break;
				}
			}
			else
				char ch = (char)e->KeyChar;
		}
		private: System::Void listBoxOutput_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) 
		{
			MainForm_KeyDown(this, e);
		}
		private: System::Void menuPlayMaze_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ResetMaze();
			panelOutput->Visible = false;
			textboxTitle->Text = "Задача: Лабиринт. Помогите жуку найти выход из лабиринта.\r\n\nУправление: стрелки вверх, вниз, вправо, влево\r\nВыйти из задания: ESC\r\nНайти маршрут: F";
			onaction = act_MAZE;
			this->Focus();
			Refresh();
		}
		private: System::Void menuRouteMaze_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ResetMaze();
			panelOutput->Visible = false;
			textboxTitle->Text = "Задача: Лабиринт.\r\nНайти маршрут из лабиринта.";
			onaction = act_MAZEPATH;
			this->Focus();
			Refresh();
		}

		private: System::Void menuClass_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (mng == 0) { mng = new CManager; }
			onaction = act_CLASSES;
			panelOutput->Visible = false;
			textboxTitle->Text = "Включён режим работы с классами \''Фигуры\''";
		}
		private: System::Void menuCreateTriangle_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (mng == 0) { mng = new CManager; }
			CShape* shape = new CTriangle(rand() % 300, rand() % 300);
			shape->SetID(mng->GetLastId() + 1);
			mng->Add(shape);
			Refresh();

		}
		private: System::Void menuCreateRectangle_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (mng == 0) { mng = new CManager; }
			CShape* shape = new CRectangle(rand() % 300, rand() % 300);
			shape->SetID(mng->GetLastId() + 1);
			mng->Add(shape);
			Refresh();
		}
		private: System::Void menuCreateEllipse_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (mng == 0) { mng = new CManager; }
			CShape* shape = new CEllipse(rand() % 300, rand() % 300);
			shape->SetID(mng->GetLastId() + 1);
			mng->Add(shape);
			Refresh();
		}
		
		private: System::Void menuSaveShapes_Click(System::Object^ sender, System::EventArgs^ e)
		{
			SaveFileDialog^ saveFileDialog = gcnew SaveFileDialog();

			if (saveFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				string sFile;
				StringToChar(saveFileDialog->FileName, sFile);
				mng->SaveArchive(sFile);
				textboxTitle->Text += "\rКарта сохранена в файле: " + saveFileDialog->FileName;
			}

			delete saveFileDialog;
		}
		private: System::Void menuLoadShapes_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			OpenFileDialog^ openFileDialog = gcnew OpenFileDialog();

			if (openFileDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				string sFile;
				StringToChar(openFileDialog->FileName, sFile);
				mng->AllClear();
				mng->LoadArchive(sFile);
				textboxTitle->Text += "\rКарта загружена из файла: " + openFileDialog->FileName;
				Refresh();
			}
			delete openFileDialog;
		}

		private: System::Void menuOnUnion_Click(System::Object^ sender, System::EventArgs^ e)
		{
			onaction = act_UNIT;
			Refresh();
		}
		private: System::Void menuOffUnion_Click(System::Object^ sender, System::EventArgs^ e)
		{
			onaction = act_CLASSES;
			Refresh();
		}
		private: System::Void MainForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			if ((onaction == act_CLASSES) || (onaction == act_UNIT))
			{
				mx = e->Location.X;
				my = e->Location.Y;
				if (e->Button == System::Windows::Forms::MouseButtons::Right)
				{
					contextMenuShapes->Show(e->Location.X, e->Location.Y);
				}
				else if (e->Button == System::Windows::Forms::MouseButtons::Left)
				{
					CShape* shape;
					int x1, x2, y1, y2;
					ActiveClass = 0;
					for (int i = 1; i <= mng->GetCount() + 1; i++)
					{
						shape = mng->GetShape(i);
						x1 = shape->X; x2 = shape->Right;
						y1 = shape->Y; y2 = shape->Bottom;
						if ((x1 <= mx) && (mx <= x2) && (y1 <= my) && (my <= y2))
						{
							ActiveClass = shape;
							dx = mx - ActiveClass->X;
							dy = my - ActiveClass->Y;
							Refresh();
							break;
						}
					}
					Refresh();
				}
			}
		}
		private: System::Void MainForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			if (onaction == act_CLASSES)
			{
				if (e->Button == System::Windows::Forms::MouseButtons::Left)
				{
					if (ActiveClass != 0)
					{
						ActiveClass->X = e->Location.X - dx;
						ActiveClass->Y = e->Location.Y - dy;
						Refresh();
					}
				}
			}
			else if (onaction == act_UNIT)
			{
				if (e->Button == System::Windows::Forms::MouseButtons::Left)
				{
					mx = e->Location.X;
					my = e->Location.Y;
					if (ActiveClass != 0)
					{
						Refresh();
					}
				}
			}
		}

		private: System::Void MainForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
		{
			if (onaction == act_UNIT)
			{
				if (mng == 0) return;
				if (ActiveClass == 0) return;
				if (e->Button == System::Windows::Forms::MouseButtons::Left)
				{
					CShape* shape = mng->GetShape(e->Location.X, e->Location.Y);
					if (shape == 0) return;
					CUnion* unit = new CUnion(ActiveClass, shape);
					unit->SetID(mng->GetLastId() + 1);
					mng->Add(unit);
					ActiveClass = 0;
					Refresh();
				}
			}
		}

		private: System::Void contextMenuCreateRectangle_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (mng == 0) { mng = new CManager; }
			CShape* shape = new CRectangle(mx, my, 30, 40);
			shape->SetID(mng->GetLastId() + 1);
			mng->Add(shape);
			Refresh();
		}

		private: System::Void contextMenuCreateSquare_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (mng == 0) { mng = new CManager; }
			CShape* shape = new CRectangle(mx, my, 50, 50);
			shape->SetID(mng->GetLastId() + 1);
			mng->Add(shape);
			Refresh();
		}

		private: System::Void contextMenuCreateEllipse_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (mng == 0) { mng = new CManager; }
			CShape* shape = new CEllipse(mx, my, 30, 40);
			shape->SetID(mng->GetLastId() + 1);
			mng->Add(shape);
			Refresh();
		}

		private: System::Void contextMenuCreateTriangle_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (mng == 0) { mng = new CManager; }
			CShape* shape = new CTriangle(mx, my, 30, 40);
			shape->SetID(mng->GetLastId() + 1);
			mng->Add(shape);
			Refresh();
		}

		private: System::Void contextMenuEditBackground_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (colorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				CShape* shape = mng->GetShape(mx, my);

				if (shape != 0)
				{
					int clr = colorDialog->Color.ToArgb();
					int clred = (clr & 0x00FFFFFF) >> 16, clgreen = (clr & 0x00FFFFFF) >> 8, clblue(clr & 0x00FFFFFF);

					shape->setBrushColor(RGB(clred, clgreen, clblue));
				}
				else
				{
					panelOutput->Visible = true;
					listBoxOutput->Items->Clear();
					listBoxOutput->Items->Add("Объект не найден!");
				}
				Refresh();
			}
		}

		private: System::Void contextMenuEditPen_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			if (colorDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				CShape* shape = mng->GetShape(mx, my);

				if (shape != 0)
				{
					int clr = colorDialog->Color.ToArgb();
					int clred = (clr & 0x00FFFFFF) >> 16, clgreen = (clr & 0x00FFFFFF) >> 8, clblue(clr & 0x00FFFFFF);

					shape->setPenColor(RGB(clred, clgreen, clblue));
				}
				else
				{
					panelOutput->Visible = true;
					listBoxOutput->Items->Clear();
					listBoxOutput->Items->Add("Объект не найден!");
				}
				Refresh();
			}
		}

		private: System::Void contextMenuEditWidth_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Input_DialogForm^ f_input = gcnew Input_DialogForm;
			f_input->SetLabel("Введите ширину объекта");
			if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ sRes = f_input->GetDialogData();
				if (sRes == "") return;
				int nWid = Convert::ToInt32(sRes);
				CShape* shape = mng->GetShape(mx, my);

				if (shape != 0)
				{
					shape->Width = nWid;
				}
				Refresh();
			}
			delete f_input;
		}

		private: System::Void contextMenuEditHeight_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			Input_DialogForm^ f_input = gcnew Input_DialogForm;
			f_input->SetLabel("Введите высоту объекта");
			if (f_input->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				String^ sRes = f_input->GetDialogData();
				if (sRes == "") return;
				int nHeight = Convert::ToInt32(sRes);
				CShape* shape = mng->GetShape(mx, my);

				if (shape != 0)
				{
					shape->Height = nHeight;
				}
				Refresh();
			}
			delete f_input;
		}
		
		//КНОПКА ОБНОВЛЕНИЯ
		private: System::Void menuUpdateShapes_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ActiveClass = 0;
			Refresh();
		}

		//------------------------------ПЕРВЫЙ СЕМЕСТР---------------------------
		private: System::Void menuParametricFunction_Click(System::Object^ sender, System::EventArgs^ e)
		{
			ClearOldTask();
			ParametricFunction();
			onaction = act_RECURSION;
			Refresh();
		}
		private: System::Void menuLab21_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			ClearOldTask();
			BranchingAlgorithmFirst();
		}
		private: System::Void menuLab22_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			ClearOldTask();
			BranchingAlgorithmSecond();
		}
		private: System::Void menuLab32_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			ClearOldTask();
			ProcessingOneDimensionalArray();
		}
		private: System::Void menuLab4_Click(System::Object^ sender, System::EventArgs^ e) 
		{
			ClearOldTask();
			Matrix();
		}
	};
}