#include "UI.h"
#include"../Events/Event.h"
#include"../Events/Formulation.h"
#include <iostream>
#include <limits> 
#undef max
UI::UI(MarsStation* Master) :Master(Master)
{
}

void UI::Interactive_Mode()
{
	cout << "Current Day: " << Master->getDay() << endl;
	Pair<int, string>p = Master->PrintWaitingMission();
	cout << p.first << " Waiting Missions: " << p.second << endl;
	p = Master->PrintExecetion();
	cout << p.first << " In-Execution Missions/Rovers: " << p.second << endl;
	p = Master->Printavailable();
	cout << p.first << " Available Rovers: " << p.second << endl;
	p = Master->PrintCheukUp();
	cout << p.first << " In-Checkup Rovers: " << p.second << endl;
	p = Master->PrintCompleted();
	cout << p.first << " Completed Missions: " << p.second << endl;
	p = Master->PrintMaintenece();
	cout << p.first << " In-Maintenece Rovers: " << p.second << endl;
	if (Master->FailedMissionsPrint().size() != 0)
	{
		cout << "\a\a\a\aMission Failed Today : " << Master->FailedMissionsPrint() << endl;
		Master->resetFailedMission();
	}
	cout << "==========================================\n";
}

void UI::Start()
{
	cout << "\t\t\t\t***********************************************************\n";
	cout << "\t\t\t\t*                                                         *\n";
	cout << "\t\t\t\t*                                                         *\n";
	cout << "\t\t\t\t*             Welcome In Buzz Yateer Station              *\n";
	cout << "\t\t\t\t*                                                         *\n";
	cout << "\t\t\t\t*                                                         *\n";
	cout << "\t\t\t\t***********************************************************\n";
	cout << "\n-Please Choose Mode : \n";
	cout << "\t1)Interactive Mode\n";
	cout << "\t2)Step-By-Step Mode\n";
	cout << "\t3)Silent Mode\n";
	cout << "-Mode : ";
	int Mode;
	cin >> Mode;
	Master->Set_Mode(Mode);
	cout << "***********************************************************\n";
}

void UI::Mode_1()
{
	cin.sync();
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	Interactive_Mode();
}

void UI::Mode_2()
{
	Sleep(1000);
	Interactive_Mode();

}

void UI::Mode_3()
{
	cout << "Silent Mode" << endl;
	cout << "Simulation Starts..." << endl;
	cout << "Simulation ends, Output file created" << endl;
}

void UI::decide()
{
	int x = Master->Choose_Mode();
	if (x == 1)
		Mode_1();
	else if (x == 2)
		Mode_2();
	else if (x == 3) 
	{
		Mode_3();
		Master->Set_Mode(-1);
	}
}
