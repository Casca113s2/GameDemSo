#include "game_GUI.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]
int main(int argc, char*argv[])
{
	if (System::IO::File::Exists("Statistic.txt") == 0)
	{
		ofstream File;
		File.open("Statistic.txt");
		File.close();
	}
	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);
	GameDemSo::game_GUI form;
	System::Windows::Forms::Application::Run(%form);

	return 0;
}