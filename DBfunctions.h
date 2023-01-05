#include "Table.h"
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace Data;
using namespace Data::SqlClient;
using namespace System::IO;



ref class DBfunctions
{
private:
	SqlConnection^ connection;
	SqlConnectionStringBuilder^ connectionString;
	String^ dbName;
	List<Table^>^ tables;

	void readNamesAndIdentity() {
		String^ sqlQuery = "SELECT TABLE_NAME, OBJECTPROPERTY(OBJECT_ID(TABLE_NAME), 'TableHasIdentity') FROM [" + dbName + "].information_schema.TABLES WHERE TABLE_TYPE LIKE '%TABLE%' order by TABLE_NAME; ";
		SqlCommand command(sqlQuery, connection);
		SqlDataReader^ reader = command.ExecuteReader();
		while (reader->Read()) {
			Table^ T = gcnew Table();
			T->tableName = reader->GetString(0);
			T->identity = reader->GetInt32(1);
			tables->Add(T);
		}
		reader->Close();
	}



	void readRowCount() {
		for each (Table ^ t in tables)
		{
			String^ sqlQuery = "Select count(*) from [" + t->tableName +"]";
			SqlCommand command(sqlQuery, connection);
			SqlDataReader^ reader = command.ExecuteReader();
			reader->Read();
			t->rowCount = reader->GetInt32(0);
			reader->Close();
		}
	}
	void readPrimaryKey() {
		String^ sqlQuery = "select schema_name(tab.schema_id) as [schema_name], tab.[name] as table_name, ISNULL(pk.[name],'No primary key') as pk_name,  ISNULL(substring(column_names, 1, len(column_names)-1),'No primary key') as[columns] from [" + dbName + "].sys.tables tab left outer join [" + dbName + "].sys.indexes pk on tab.object_id = pk.object_id and pk.is_primary_key = 1 cross apply(select col.[name] + ', ' from [" + dbName + "].sys.index_columns ic inner join [" + dbName + "].sys.columns col on ic.object_id = col.object_id and ic.column_id = col.column_id where ic.object_id = tab.object_id and ic.index_id = pk.index_id order by col.column_id 		for xml path('')) D(column_names) order by schema_name(tab.schema_id), tab.[name]";
		SqlCommand command(sqlQuery, connection);
		SqlDataReader^ reader = command.ExecuteReader();
		int rowCount = 0;
		while (reader->Read())
		{
			tables[rowCount++]->primaryKey = reader->GetString(3);


		}
		reader->Close();
	}

	void readIndexes() {
		for each (Table ^ tab in tables)
		{
			String^ sqlQuery = "select name from [" + dbName + "].sys.indexes where object_id = (select object_id from [" + dbName + "].sys.objects where name = '" + tab->tableName + "')";
			SqlCommand command(sqlQuery, connection);
			SqlDataReader^ reader = command.ExecuteReader();
			while (reader->Read()) {
				try
				{
					tab->indexes->Add(reader->GetString(0));
				}
				catch (...)
				{
					tab->indexes->Add("No indexes");
				}
			}
			reader->Close();
		}
	}
	void readColumns() {
		String^ sqlQuery = "SELECT s.name AS SchemaName	, t.name AS TableName, c.name AS ColumnName,Ty.Name AS ColumnDataType	FROM [" + dbName + "].sys.schemas AS s JOIN [" + dbName + "].sys.tables AS t ON t.schema_id = s.schema_id JOIN [" + dbName + "].sys.columns AS c ON c.object_id = t.object_id JOIN [" + dbName + "].sys.types as Ty ON C.system_type_id = Ty.system_type_id WHERE Ty.Name != 'sysname' ORDER BY SchemaName , TableName, ColumnName;";
		SqlCommand command(sqlQuery, connection);
		SqlDataReader^ reader = command.ExecuteReader();
		int rowCount = 0;
		while (rowCount < tables->Count) {
			while (reader->Read() && tables[rowCount]->tableName == reader->GetString(1)) {
				tables[rowCount]->columns->Add(reader->GetString(2) + " " + reader->GetString(3));
			}
			rowCount++;
			if (rowCount < tables->Count)
				tables[rowCount]->columns->Add(reader->GetString(2) + " " + reader->GetString(3));
		}
		reader->Close();
	}
public:
	DBfunctions() {
		tables = gcnew List<Table^>();
	}
	void connectToDB(String^ dbServer, String^ dbName, String^ username, String^ password) {
		this->dbName = dbName;
		String^ connString = "Data Source = " + dbServer + "; Initial Catalog = " + dbName + "; User ID = " + username + "; Password = " + password;
		/*String^ connString = "Data Source = AntonDesktop; Initial Catalog = TestDB; User ID = User1; Password = sa";*/

		connection = gcnew SqlConnection(connString);
		connection->Open();
	}
	void readData() {
		readNamesAndIdentity();
		readRowCount();
		readPrimaryKey();
		readIndexes();
		readColumns();
	}
	void dataToGrid(DataGridView^ grid) {
		for (int i = 0; i < tables->Count; i++) {
			grid->Rows->Add();
			grid->Rows[i]->Cells[0]->Value = tables[i]->tableName;
			grid->Rows[i]->Cells[1]->Value = tables[i]->rowCount;
			grid->Rows[i]->Cells[2]->Value = tables[i]->identity;
			grid->Rows[i]->Cells[3]->Value = tables[i]->primaryKey;
			grid->Rows[i]->Cells[4]->Value = tables[i]->getIndexes();
			grid->Rows[i]->Cells[5]->Value = tables[i]->getColumns();
		}
	}

	void writeToCSV() {
		String^ Title = "Table Name, Row Count, Has Identity, Primary Key, Table Indexes, Table Columns";
		StreamWriter^ sw = gcnew StreamWriter("data.csv");
		sw->WriteLine(Title);
		for each (Table ^ tab in tables)
		{
			String^ s = tab->tableName + ", " + tab->rowCount + ", " + tab->identity + ", " + tab->primaryKey + ", " + tab->getIndexes() + ", " + tab->getColumns();
			sw->WriteLine(s);
		}
		sw->Close();
	}

};
