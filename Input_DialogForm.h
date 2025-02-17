#pragma once

namespace IntroductoryPractice {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Input_DialogForm : public System::Windows::Forms::Form
	{
	public:
		Input_DialogForm(void)
		{
			InitializeComponent();
		}

	protected:
		~Input_DialogForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label_Input;
	private: System::Windows::Forms::TextBox^ textBox_Input;
	private: System::Windows::Forms::Button^ button_Accept;
	private: System::Windows::Forms::Button^ button_Cancel;
	private: System::Windows::Forms::Panel^ panelButtons;


	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Input_DialogForm::typeid));
			this->label_Input = (gcnew System::Windows::Forms::Label());
			this->textBox_Input = (gcnew System::Windows::Forms::TextBox());
			this->button_Accept = (gcnew System::Windows::Forms::Button());
			this->button_Cancel = (gcnew System::Windows::Forms::Button());
			this->panelButtons = (gcnew System::Windows::Forms::Panel());
			this->panelButtons->SuspendLayout();
			this->SuspendLayout();
			// 
			// label_Input
			// 
			this->label_Input->AutoSize = true;
			this->label_Input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label_Input->Location = System::Drawing::Point(12, 9);
			this->label_Input->Name = L"label_Input";
			this->label_Input->Size = System::Drawing::Size(137, 23);
			this->label_Input->TabIndex = 0;
			this->label_Input->Text = L"¬ведите данные";
			// 
			// textBox_Input
			// 
			this->textBox_Input->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_Input->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->textBox_Input->Location = System::Drawing::Point(16, 35);
			this->textBox_Input->Name = L"textBox_Input";
			this->textBox_Input->Size = System::Drawing::Size(954, 30);
			this->textBox_Input->TabIndex = 1;
			// 
			// button_Accept
			// 
			this->button_Accept->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_Accept->AutoSize = true;
			this->button_Accept->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->button_Accept->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Accept.Image")));
			this->button_Accept->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button_Accept->Location = System::Drawing::Point(792, 22);
			this->button_Accept->Name = L"button_Accept";
			this->button_Accept->Size = System::Drawing::Size(178, 54);
			this->button_Accept->TabIndex = 2;
			this->button_Accept->Text = L"ѕрин€ть";
			this->button_Accept->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button_Accept->UseVisualStyleBackColor = true;
			// 
			// button_Cancel
			// 
			this->button_Cancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button_Cancel->AutoSize = true;
			this->button_Cancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->button_Cancel->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button_Cancel.Image")));
			this->button_Cancel->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button_Cancel->Location = System::Drawing::Point(591, 22);
			this->button_Cancel->Name = L"button_Cancel";
			this->button_Cancel->Size = System::Drawing::Size(195, 54);
			this->button_Cancel->TabIndex = 3;
			this->button_Cancel->Text = L"ќтмена";
			this->button_Cancel->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button_Cancel->UseVisualStyleBackColor = true;
			// 
			// panelButtons
			// 
			this->panelButtons->AutoSize = true;
			this->panelButtons->BackColor = System::Drawing::SystemColors::ControlLight;
			this->panelButtons->Controls->Add(this->button_Accept);
			this->panelButtons->Controls->Add(this->button_Cancel);
			this->panelButtons->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panelButtons->Location = System::Drawing::Point(0, 115);
			this->panelButtons->Margin = System::Windows::Forms::Padding(10);
			this->panelButtons->Name = L"panelButtons";
			this->panelButtons->Size = System::Drawing::Size(982, 88);
			this->panelButtons->TabIndex = 4;
			// 
			// Input_DialogForm
			// 
			this->AcceptButton = this->button_Accept;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->CancelButton = this->button_Cancel;
			this->ClientSize = System::Drawing::Size(982, 203);
			this->ControlBox = false;
			this->Controls->Add(this->panelButtons);
			this->Controls->Add(this->textBox_Input);
			this->Controls->Add(this->label_Input);
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1000, 250);
			this->MinimumSize = System::Drawing::Size(500, 200);
			this->Name = L"Input_DialogForm";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"¬вод параметров";
			this->TopMost = true;
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->panelButtons->ResumeLayout(false);
			this->panelButtons->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		public: String^ GetDialogData() { return textBox_Input->Text; }
		public: void SetLabel(String^ newLabel) { label_Input->Text = newLabel; }
	};
}
