#include "game_GUI.h"
#include "about_GUI.h"
#include "help_GUI.h"
#include "choose_level.h"
#include "warning_GUI.h"
#include "winning_GUI.h"

#include <Windows.h>
#include <iomanip>
#include <cstdlib> 
#include <ctime>
#include <iostream>

int X = 0;
int Y = 0;
bool flag_PR = false;
bool flag_warning = false;
bool flag_winning = false;
int size = 0;
NodeData * p;
SLL sll_data;

void RanD(SLL * sll_data);

//// "Winning" section implement ////
//---------------------------//
	////Play Again button implement////
System::Void GameDemSo::winning_GUI::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	flag_winning = true;
	this->Close();
}

	////Quit button implement////
System::Void GameDemSo::winning_GUI::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	this->Close();
}

//-------------end-----------//

//// "Warning" section implement ////
//---------------------------//
	////Ok button implement////
System::Void GameDemSo::warning_GUI::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	flag_warning = true;
	this->Close();
}

	////Cancel button implement////
System::Void GameDemSo::warning_GUI::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Close();
}
//-------------end-----------//

//// "About" section implement ////
//---------------------------//
	////Exit button implement////
System::Void GameDemSo::about_GUI::button8_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Close();
}
//-------------end-----------//

//// "Choose Level" section implement ////
//---------------------------//
	////Easy button implement////
System::Void GameDemSo::choose_level::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	X = 5;
	Y = 5;
	this->Close();
}

	////Medium button implement////
System::Void GameDemSo::choose_level::button5_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	X = 10;
	Y = 10;
	this->Close();
}

	////Hard button implement////
System::Void GameDemSo::choose_level::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	X = 15;
	Y = 15;
	this->Close();
}
//-------------end-----------//


//// "Help" section implement ////
//---------------------------//
	////Exit button implement////
System::Void GameDemSo::help_GUI::button8_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Close();
}

	////Next Page button implement////
System::Void GameDemSo::help_GUI::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	panel2->Visible = true;
	panel1->Visible = false;
}

	////Previous Page button implement////
System::Void GameDemSo::help_GUI::button2_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	panel2->Visible = false;
	panel1->Visible = true;
}
//-------------end-----------//


//// "Game" section implement////
//---------------------------//
	////About button implement////
System::Void GameDemSo::game_GUI::button3_Click(System::Object^  sender, System::EventArgs^  e) {
	GameDemSo::about_GUI^ about = gcnew GameDemSo::about_GUI();
	bool flag = false;
	if (this->timer1->Enabled == true)
	{
		this->timer1->Stop();
		flag = true;
	}
	about->ShowDialog();
	if (flag)
	{
		this->timer1->Start();
	}
}

	////Help button implement////
System::Void GameDemSo::game_GUI::button4_Click(System::Object^  sender, System::EventArgs^  e) {
	GameDemSo::help_GUI^ help = gcnew GameDemSo::help_GUI();
	bool flag = false;
	if (this->timer1->Enabled == true)
	{
		this->timer1->Stop();
		flag = true;
	}
	help->ShowDialog();
	if (flag)
	{
		this->timer1->Start();
	}
}

	////Exit button implement////
System::Void GameDemSo::game_GUI::button8_Click(System::Object^  sender, System::EventArgs^  e) {
	this->Close();
}

	////New Game button implement////
System::Void GameDemSo::game_GUI::button1_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	bool flag = false;
	if (this->timer1->Enabled == true)
	{
		this->timer1->Stop();
		flag = true;
	}

	if (panel3->Visible == true)
	{
		GameDemSo::warning_GUI^ warning = gcnew GameDemSo::warning_GUI();
		warning->ShowDialog();
		if (flag_warning)
		{
			GameDemSo::choose_level^ choose_level = gcnew GameDemSo::choose_level();
			choose_level->ShowDialog();
			Second = 0;
			Minute = 0;
			Hour = 0;
			Sec = "00";
			Min = "00";
			Hor = "00";
			
			sll_data.SLL::SLL();

			label2->Text = Hor + ":" + Min + ":" + Sec;
			timer1->Enabled = true;
			panel3->Controls->Clear();
			RanD(&sll_data);
			this->DrawBoard(&sll_data);
		}
		else
		{
			this->timer1->Start();
		}
	}
	else
	{
		GameDemSo::choose_level^ choose_level = gcnew GameDemSo::choose_level();
		choose_level->ShowDialog();
		panel1->Visible = false;
		panel3->Visible = true;
		timer1->Enabled = true;
		RanD(&sll_data);
		this->DrawBoard(&sll_data);
	}
	
}

	////Counting Time and Display Time////
System::Void GameDemSo::game_GUI::timer1_Tick(System::Object ^ sender, System::EventArgs ^ e)
{
	Second++;

	if (Second == 60)
	{
		Second = 0;
		Minute++;
		
		if (Minute == 60)
		{
			Minute = 0;
			Hour++;
		}
	}

	if (Second < 10)
	{
		Sec = "0" + Convert::ToString(Second);
	}
	else
	{
		Sec = Convert::ToString(Second);
	}

	if (Minute < 10)
	{
		Min = "0" + Convert::ToString(Minute);
	}
	else
	{
		Min = Convert::ToString(Minute);
	}

	if (Hour < 10)
	{
		Hor = "0" + Convert::ToString(Hour);
	}
	else
	{
		Hor = Convert::ToString(Hour);
	}

	label2->Text = Hor + ":" + Min + ":" + Sec;
}

	////Pause button////
System::Void GameDemSo::game_GUI::button6_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (this->timer1->Enabled == true)
	{
		this->timer1->Stop();
		this->panel2->Visible = true;
		panel3->Visible = false;
		flag_PR = true;
	}
}

	////Resume button////
System::Void GameDemSo::game_GUI::button7_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	if (flag_PR)
	{
		this->timer1->Start();
		this->panel2->Visible = false;
		panel3->Visible = true;
		flag_PR = false;
	}
}

	////Draw Board function////
void GameDemSo::game_GUI::DrawBoard(SLL * sll_data)
{
	int width = (600/Y);
	int height = (400/X);
	Button^ old_btn = gcnew Button();
	old_btn->Width = 0;
	old_btn->Location = System::Drawing::Point(0 ,0);
	p = sll_data->get_head();

	for (int i = 0; i < X; i++)
	{
		this->Draw(old_btn, sll_data, width, height);

		old_btn->Width = 0;
		old_btn->Height = 0;
		old_btn->Location = System::Drawing::Point(0, old_btn->Location.Y + height);
	}
	sll_data->sorting();
	p = sll_data->get_head();
}

	////Draw function////
void GameDemSo::game_GUI::Draw(System::Windows::Forms::Button^ old_btn, SLL * sll_data, int width, int height)
{
	for (int j = 0; j < Y; j++)
	{
		Button^ btn = gcnew Button();
		btn->Width = width;
		btn->Height = height;
		btn->Location = System::Drawing::Point((old_btn->Location.X + old_btn->Width), old_btn->Location.Y);
		btn->Text = Convert::ToString(p->get_data());
		btn->Click += gcnew EventHandler(this, &game_GUI::btn_Click);
		panel3->Controls->Add(btn);
		old_btn = btn;
		p = p->get_next_node();
	}
}

	////Random function////
void RanD(SLL * sll_data)
{
	int size = X*Y;
	int temp = 0;
	time_t t;
	srand((unsigned)time(&t));

	for (int i = 0; i < (size); i++)
	{
		bool flag_1 = false;
		while (flag_1 != true)
		{
			temp = (1 + rand() % (size));
			if (sll_data->get_head() == NULL)
			{
				sll_data->addTail(temp);
				flag_1 = true;
				sll_data->set_count(1);
			}
			else
			{
				bool flag_2 = true;
				for (NodeData *p = sll_data->get_head(); p != NULL; p = p->get_next_node())
				{
					if (p->get_data() == temp)
					{
						flag_2 = false;
					}
					else if ((p == sll_data->get_tail()) && (flag_2 == true))
					{
						sll_data->addTail(temp);
						flag_1 = true;
						sll_data->set_count(1);
					}
				}
			}
		}
	}
}

	////Click function for Created Button////
void GameDemSo::game_GUI::btn_Click(System::Object ^ sender, System::EventArgs ^ e)
{
	Button^ btn = safe_cast<Button^>(sender);
	int temp = Convert::ToInt32(btn->Text);
	
	if (( p->get_next_node() == NULL) && (temp == p->get_data()))
	{
		btn->BackColor = System::Drawing::Color::Orange;
		GameDemSo::winning_GUI^ win = gcnew GameDemSo::winning_GUI();
		win->ShowDialog();
		if (flag_winning == true)
		{
			GameDemSo::choose_level^ choose_level = gcnew GameDemSo::choose_level();
			choose_level->ShowDialog();
			Second = 0;
			Minute = 0;
			Hour = 0;
			Sec = "00";
			Min = "00";
			Hor = "00";
			sll_data.SLL::SLL();
			label2->Text = Hor + ":" + Min + ":" + Sec;
			timer1->Enabled = true;
			panel3->Controls->Clear();
			RanD(&sll_data);
			this->DrawBoard(&sll_data);
			flag_winning = false;
		}
		else
		{
			this->Close();
		}
	}
	else if ((temp == p->get_data()))
	{
		btn->BackColor = System::Drawing::Color::Orange;
		p = p->get_next_node();
	}
}
//-------------end-----------//