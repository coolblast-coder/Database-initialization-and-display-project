#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Collections;
using namespace System::Collections::Generic;
ref class Table
{
public:
	String^ tableName;
	int rowCount = 0;
	bool identity = false;
	String^ primaryKey;
	List<String^>^ indexes;
	List<String^>^ columns;
	Table() {
		indexes = gcnew List<String^>();
		columns = gcnew List<String^>();
	}

	String^ getColumns() {
		String^ s = "";
		for each (String ^ col in columns)
		{
			s += col + "; ";
		}
		return s;
	}
	String^ getIndexes() {
		String^ s = "";
		for each (String ^ idx in indexes)
		{
			s += idx + "; ";
		}
		return s;
	}
};

