#pragma once

#include <msclr/marshal_cppstd.h>
#include "Tester.h"
#include "Compressor.h"

namespace CLRtry1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	/// <summary>
	/// —водка дл€ MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  buttonSelectFile;
	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBoxFilePath;
	private: System::Windows::Forms::Button^  buttonCompress;
	private: System::Windows::Forms::TextBox^  textBoxResultName;


	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::ComboBox^  comboBoxAlgoSelector;
	private: System::Windows::Forms::CheckBox^  checkBoxBWT;
	private: System::Windows::Forms::Button^  buttonDecompress;
	private: System::Windows::Forms::Button^  buttonTest;
	private: System::Windows::Forms::Label^  labelTestResult;
	private: System::Windows::Forms::Label^  label3;




	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->buttonSelectFile = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBoxFilePath = (gcnew System::Windows::Forms::TextBox());
			this->buttonCompress = (gcnew System::Windows::Forms::Button());
			this->textBoxResultName = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->comboBoxAlgoSelector = (gcnew System::Windows::Forms::ComboBox());
			this->checkBoxBWT = (gcnew System::Windows::Forms::CheckBox());
			this->buttonDecompress = (gcnew System::Windows::Forms::Button());
			this->buttonTest = (gcnew System::Windows::Forms::Button());
			this->labelTestResult = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// buttonSelectFile
			// 
			this->buttonSelectFile->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->buttonSelectFile->Location = System::Drawing::Point(340, 9);
			this->buttonSelectFile->Name = L"buttonSelectFile";
			this->buttonSelectFile->Size = System::Drawing::Size(87, 28);
			this->buttonSelectFile->TabIndex = 0;
			this->buttonSelectFile->Text = L"Select file";
			this->buttonSelectFile->UseVisualStyleBackColor = true;
			this->buttonSelectFile->Click += gcnew System::EventHandler(this, &MyForm::buttonSelectFile_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label1->Location = System::Drawing::Point(12, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 20);
			this->label1->TabIndex = 1;
			this->label1->Text = L"FilePath:";
			// 
			// textBoxFilePath
			// 
			this->textBoxFilePath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBoxFilePath->Location = System::Drawing::Point(80, 9);
			this->textBoxFilePath->Name = L"textBoxFilePath";
			this->textBoxFilePath->ReadOnly = true;
			this->textBoxFilePath->Size = System::Drawing::Size(254, 26);
			this->textBoxFilePath->TabIndex = 2;
			// 
			// buttonCompress
			// 
			this->buttonCompress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->buttonCompress->Location = System::Drawing::Point(12, 73);
			this->buttonCompress->Name = L"buttonCompress";
			this->buttonCompress->Size = System::Drawing::Size(120, 28);
			this->buttonCompress->TabIndex = 3;
			this->buttonCompress->Text = L"Compress";
			this->buttonCompress->UseVisualStyleBackColor = true;
			this->buttonCompress->Click += gcnew System::EventHandler(this, &MyForm::buttonCompress_Click);
			// 
			// textBoxResultName
			// 
			this->textBoxResultName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBoxResultName->Location = System::Drawing::Point(145, 41);
			this->textBoxResultName->Name = L"textBoxResultName";
			this->textBoxResultName->Size = System::Drawing::Size(189, 26);
			this->textBoxResultName->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->label2->Location = System::Drawing::Point(12, 44);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Result file name:";
			// 
			// comboBoxAlgoSelector
			// 
			this->comboBoxAlgoSelector->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxAlgoSelector->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->comboBoxAlgoSelector->FormattingEnabled = true;
			this->comboBoxAlgoSelector->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"RLE", L"Huff", L"LZW" });
			this->comboBoxAlgoSelector->Location = System::Drawing::Point(138, 74);
			this->comboBoxAlgoSelector->Name = L"comboBoxAlgoSelector";
			this->comboBoxAlgoSelector->Size = System::Drawing::Size(61, 28);
			this->comboBoxAlgoSelector->TabIndex = 6;
			this->comboBoxAlgoSelector->SelectedIndex = 0;
			// 
			// checkBoxBWT
			// 
			this->checkBoxBWT->AutoSize = true;
			this->checkBoxBWT->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->checkBoxBWT->Location = System::Drawing::Point(205, 76);
			this->checkBoxBWT->Name = L"checkBoxBWT";
			this->checkBoxBWT->Size = System::Drawing::Size(96, 24);
			this->checkBoxBWT->TabIndex = 7;
			this->checkBoxBWT->Text = L"Use BWT";
			this->checkBoxBWT->UseVisualStyleBackColor = true;
			// 
			// buttonDecompress
			// 
			this->buttonDecompress->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->buttonDecompress->Location = System::Drawing::Point(307, 73);
			this->buttonDecompress->Name = L"buttonDecompress";
			this->buttonDecompress->Size = System::Drawing::Size(120, 28);
			this->buttonDecompress->TabIndex = 8;
			this->buttonDecompress->Text = L"Decompress";
			this->buttonDecompress->UseVisualStyleBackColor = true;
			this->buttonDecompress->Click += gcnew System::EventHandler(this, &MyForm::buttonDecompress_Click);
			// 
			// buttonTest
			// 
			this->buttonTest->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->buttonTest->Location = System::Drawing::Point(12, 107);
			this->buttonTest->Name = L"buttonTest";
			this->buttonTest->Size = System::Drawing::Size(120, 28);
			this->buttonTest->TabIndex = 9;
			this->buttonTest->Text = L"Test";
			this->buttonTest->UseVisualStyleBackColor = true;
			this->buttonTest->Click += gcnew System::EventHandler(this, &MyForm::buttonTest_Click);
			// 
			// labelTestResult
			// 
			this->labelTestResult->AutoSize = true;
			this->labelTestResult->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->labelTestResult->Location = System::Drawing::Point(138, 111);
			this->labelTestResult->Name = L"labelTestResult";
			this->labelTestResult->Size = System::Drawing::Size(83, 20);
			this->labelTestResult->TabIndex = 10;
			this->labelTestResult->Text = L"Test result";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::SystemColors::ControlDark;
			this->label3->Location = System::Drawing::Point(291, 239);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(136, 13);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Copyright Hutarevych 2020";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(434, 261);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->labelTestResult);
			this->Controls->Add(this->buttonTest);
			this->Controls->Add(this->buttonDecompress);
			this->Controls->Add(this->checkBoxBWT);
			this->Controls->Add(this->comboBoxAlgoSelector);
			this->Controls->Add(this->textBoxResultName);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->buttonCompress);
			this->Controls->Add(this->textBoxFilePath);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->buttonSelectFile);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CompressionTester";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void buttonSelectFile_Click(System::Object^  sender, System::EventArgs^  e) {
		OpenFileDialog fileDial;
		fileDial.InitialDirectory = "../CompressedFiles/";
		fileDial.Filter = "all files (*.*)|*.*";
		fileDial.FilterIndex = 2;
		fileDial.RestoreDirectory = true;
		if (fileDial.ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			textBoxFilePath->Text = fileDial.FileName;
		}

	}
	private: System::Void buttonCompress_Click(System::Object^  sender, System::EventArgs^  e) {
		std::string filePath = msclr::interop::marshal_as< std::string >(textBoxFilePath->Text);
		std::string resPath = msclr::interop::marshal_as< std::string >(textBoxResultName->Text);
		if (filePath.length() == 0)
		{
			System::Windows::Forms::MessageBox^ mess;
			mess->Show("File not selected");
			return;
		}
		if (resPath.length() == 0)
		{
			System::Windows::Forms::MessageBox^ mess;
			mess->Show("Print file name first");
			return;
		}
		const std::string outFilePath = "../CompressedFiles/";
		resPath = outFilePath + resPath;
		switch (comboBoxAlgoSelector->SelectedIndex)
		{
		case 0:
			resPath += ".rln";
			if (checkBoxBWT->Checked)
				resPath += "b";
			Compressor::compress(filePath, resPath, 'R', checkBoxBWT->Checked);
			break;
		case 1:
			resPath += ".hff";
			if (checkBoxBWT->Checked)
				resPath += "b";
			Compressor::compress(filePath, resPath, 'H', checkBoxBWT->Checked);
			break;
		case 2:
			resPath += ".lzw";
			if (checkBoxBWT->Checked)
				resPath += "b";
			Compressor::compress(filePath, resPath, 'L', checkBoxBWT->Checked);
			break;
		default:
			break;
		}
	}
private: System::Void buttonDecompress_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string filePath = msclr::interop::marshal_as< std::string >(textBoxFilePath->Text);
	if (filePath.length()==0)
	{
		System::Windows::Forms::MessageBox^ mess;
		mess->Show("File not selected");
		return;
	}
	std::string resPath = msclr::interop::marshal_as< std::string >(textBoxResultName->Text);
	if (resPath.length()==0)
	{
		System::Windows::Forms::MessageBox^ mess;
		mess->Show("Print file name first");
		return;
	}
	const std::string outFilePath = "../CompressedFiles/";
	resPath = outFilePath + resPath;
	bool useBWT = filePath.back() == 'b';
	if (useBWT)
		filePath.pop_back();
	std::string fileExt = filePath.substr(filePath.length() - 4, 4);
	if (useBWT)
		filePath.push_back('b');
	if (fileExt.compare(".rln")==0)
	{
		Compressor::decompress(filePath, resPath, 'R', useBWT);
	}
	else if (fileExt.compare(".hff")==0)
	{
		Compressor::decompress(filePath, resPath, 'H', useBWT);
	}
	else if (fileExt.compare(".lzw")==0)
	{
		Compressor::decompress(filePath, resPath, 'L', useBWT);
	}
	else
	{
		System::Windows::Forms::MessageBox^ mess;
		mess->Show("This file is unavailable for decompression");
	}
}
private: System::Void buttonTest_Click(System::Object^  sender, System::EventArgs^  e) {
	std::string filePath = msclr::interop::marshal_as< std::string >(textBoxFilePath->Text);
	if (filePath.length() == 0)
	{
		System::Windows::Forms::MessageBox^ mess;
		mess->Show("File not selected");
		return;
	}

	std::string testres;

	switch (comboBoxAlgoSelector->SelectedIndex)
	{
	case 0:
		testres = Tester::GetTesting(filePath, 'R', checkBoxBWT->Checked);
		break;
	case 1:
		testres = Tester::GetTesting(filePath, 'H', checkBoxBWT->Checked);
		break;
	case 2:
		testres = Tester::GetTesting(filePath, 'L', checkBoxBWT->Checked);
		break;
	default:
		break;
	}

	labelTestResult->Text = gcnew String(testres.c_str());

	/*
	std::vector<std::string> paths;
	const std::string outFilePath = "../CompressedFiles/";
	paths.push_back((outFilePath + "Huffman.h"));
	paths.push_back((outFilePath + "LZW.cpp"));
	paths.push_back((outFilePath + "DBHelper.java"));
	paths.push_back((outFilePath + "BanksController.cs"));
	paths.push_back((outFilePath + "MainActivity.java"));
	paths.push_back((outFilePath + "MyNumber.cpp"));
	paths.push_back((outFilePath + "list.cs"));
	paths.push_back((outFilePath + "ArrList.java"));
	paths.push_back((outFilePath + "stl_vector.cpp"));
	paths.push_back((outFilePath + "sortedset.cs"));

	std::ofstream outf;
	outf.open("../CompressedFiles/testRes.txt");
	if (outf.is_open())
	{
		for (int i = 0; i < paths.size(); ++i)
		{
			std::string testres;

			switch (comboBoxAlgoSelector->SelectedIndex)
			{
			case 0:
				testres = Tester::GetTesting(paths[i], 'R', checkBoxBWT->Checked);
				break;
			case 1:
				testres = Tester::GetTesting(paths[i], 'H', checkBoxBWT->Checked);
				break;
			case 2:
				testres = Tester::GetTesting(paths[i], 'L', checkBoxBWT->Checked);
				break;
			default:
				break;
			}

			outf << testres << '\n';
		}
	}
	outf.close();
	*/
}
};
}
