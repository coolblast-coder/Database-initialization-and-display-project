
#include "Database Connection.h"
using namespace eQubeCtestproject;
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    MyForm form;
    Application::Run(% form);
}