#pragma once
#include "DataDictionary.h"
#include "Table.h"
#include "DBfunctions.h"
namespace eQubeCtestproject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnClose;
	protected:



	private: System::Windows::Forms::Button^ btnLogin;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ DBServerName;
	private: System::Windows::Forms::TextBox^ DBName;
	private: System::Windows::Forms::TextBox^ Username;
	private: System::Windows::Forms::TextBox^ Password;




	protected:

	private:
		DBfunctions^ dbF;
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->btnClose = (gcnew System::Windows::Forms::Button());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->DBServerName = (gcnew System::Windows::Forms::TextBox());
			this->DBName = (gcnew System::Windows::Forms::TextBox());
			this->Username = (gcnew System::Windows::Forms::TextBox());
			this->Password = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// btnClose
			// 
			this->btnClose->Location = System::Drawing::Point(423, 222);
			this->btnClose->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnClose->Name = L"btnClose";
			this->btnClose->Size = System::Drawing::Size(112, 35);
			this->btnClose->TabIndex = 0;
			this->btnClose->Text = L"Close";
			this->btnClose->UseVisualStyleBackColor = true;
			this->btnClose->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// btnLogin
			// 
			this->btnLogin->Location = System::Drawing::Point(254, 222);
			this->btnLogin->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(112, 35);
			this->btnLogin->TabIndex = 1;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// label1
			// 
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(523, 40);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Database Connection ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label2
			// 
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(12, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(177, 28);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Database Server Name";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
			// 
			// label3
			// 
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(14, 110);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(177, 28);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Database Name";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label4
			// 
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(14, 138);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(177, 28);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Username";
			this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label5
			// 
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(14, 166);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(177, 28);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Password";
			this->label5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// DBServerName
			// 
			this->DBServerName->Location = System::Drawing::Point(254, 82);
			this->DBServerName->Name = L"DBServerName";
			this->DBServerName->Size = System::Drawing::Size(281, 26);
			this->DBServerName->TabIndex = 7;
			// 
			// DBName
			// 
			this->DBName->Location = System::Drawing::Point(254, 110);
			this->DBName->Name = L"DBName";
			this->DBName->Size = System::Drawing::Size(281, 26);
			this->DBName->TabIndex = 8;
			// 
			// Username
			// 
			this->Username->Location = System::Drawing::Point(254, 140);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(281, 26);
			this->Username->TabIndex = 9;
			// 
			// Password
			// 
			this->Password->Location = System::Drawing::Point(254, 168);
			this->Password->Name = L"Password";
			this->Password->Size = System::Drawing::Size(281, 26);
			this->Password->TabIndex = 10;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(547, 297);
			this->Controls->Add(this->Password);
			this->Controls->Add(this->Username);
			this->Controls->Add(this->DBName);
			this->Controls->Add(this->DBServerName);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->btnClose);
			this->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"MyForm";
			this->Text = L"Database connection ";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ DBServerName = this->DBServerName->Text;
		String^ DBName = this->DBName->Text;
		String^ UserName = this->Username->Text;
		String^ Password = this->Password->Text;


		if (DBServerName->Length == 0 || DBName->Length == 0 || UserName->Length == 0 || Password->Length == 0) {
			MessageBox::Show("Please enter all fields in the form!");
			return;
		}
		dbF = gcnew DBfunctions();
		try
		{
			dbF->connectToDB(DBServerName, DBName, UserName, Password);
			dbF->readData();
			DataDictionary^ dataDictionary = gcnew DataDictionary();
			dbF->dataToGrid(dataDictionary->dataGridView1);
			dataDictionary->Show();
			dataDictionary->writeToCSV->Click += gcnew System::EventHandler(this, &eQubeCtestproject::MyForm::OnClick);
		}
		catch (Exception^ e) {
			MessageBox::Show("Failed to connect to database", "Database connection error");
		}

	}

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
		   void OnClick(System::Object^ sender, System::EventArgs^ e)
		   {
			   dbF->writeToCSV();
			   MessageBox::Show("Data has been successfully exported to CSV file");
		   }
	};
}


