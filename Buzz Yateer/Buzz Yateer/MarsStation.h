#pragma once
#include "../Events/Event.h"
#include "../Events/Formulation.h"
#include "../Events/Promotion.h"
#include"../Events/Cancellation.h"
#include"../Rovers/PolarRover.h"
#include"../Rovers/EmergencyRover.h"
#include"../Rovers/MountainousRover.h"
#include"UI.h"
#include"../Missions/PolarMission.h"
#include"../Missions/MountainousMission.h"
#include"../Missions/EmergencyMission.h"
#include"../DS/LinkedList.h"
#include"../DS/priority_queue.h"
#include"../DS/Queue.h"
#include"../DS/Pair.h"
#include <bits/stdc++.h>
using namespace std;
class Event;
class UI;
class MarsStation
{
	ifstream InputFile;
	ofstream OutputFile;
	Queue<Event*>events;// events
	priority_Queue<PolarRover*>PR;//Polar Rovers
	priority_Queue<EmergencyRover*>ER;//Emergency Rovers
	priority_Queue<MountainousRover*>MR;//Mountainous Rovers
	Queue<PolarMission*>PM;//Polar Mission
	priority_Queue<EmergencyMission*>EM;//Emergency Mission
	LinkedList<MountainousMission*>MM;//Mountainous Mission
	Queue<Mission*>CM; //Completed Mission
	priority_Queue<Rover*>CheukUp;//Rovers In Checkup
	priority_Queue<Pair<Mission*, Rover*>>Execution;//Mission & Rovers in Excution
	Queue<PolarRover*>PolarRoverMaintenence;
	Queue<EmergencyRover*>EmergencyRoverMaintenence;
	Queue<MountainousRover*>MountainousRoverMaintenence;
	int Mode; //Mode of Printing Data
	int MCheckUp;// num days needed for Mountainous rovers 
	int PCheckUp;// num days needed for polar rovers
	int ECheckUp;// num days needed for Emergency rovers
	int NMission2CheckUp;////num mission  nedded to set in CheckUp
	int AutoP;// num days needed to make auto prmote  
	double Ap;//num missions which  prmote
	UI* UI_PTR;//presenter of UI Class
	int NumMM;//num of Mountainous Missions
	int CountDays;// count of days
	int MaxPeriod;//min period make Mission fail
	int nOfCheckUp2Maintenence;//num check up nedded to set in maintenence
	int nOfdays2LeaveMaintenence; // num days nedded to leave maintenence
	string FailedMissions;//used in Mission failed print
	int NM;//num of Mountainous rovers 
	int	NP; //num of polar rovers 
	int NE;//num of emergency rovers
	int NumMDE;//num of Mountainous mission can't done
	int	NumPDE; //num of polar mission can't done
	int NumEDE;//num of emergency mission can't done
	Queue<Pair<int,char>>FailedIDs_Types;
public:

	MarsStation(string input, string output);

	/********Maintainence*********/
	void Add2Maintenence(Rover* R);
	void RemoveFromMaintenence(Rover* R = nullptr);
	void RemoveFromPMaintenence(bool Force = 0);
	void RemoveFromEMaintenence(bool Force = 0);
	void RemoveFromMMaintenence(bool Force = 0);
	void setMaintenenceData(int nOfCheckUp2Maintenence, int nOfdays2LeaveMaintenence);
	/*******************/

	/*********Events**********/
	void AddFormulationEvent(char MissionType, int ED, int ID, int TLOC, int MDUR, int SIG); //Add Formulation Event to List of Events
	void AddPromotionEvent(int ED, int ID); //Add Promotoin Event to List of Events
	void AddCanellationEvent(int ID, int ED); //Add Cancellation Event to List Of Events
	void AddPolarRover(double speed); //Adds a Polar Rover to List of Polar Rovers
	void AddEmergencyRover(double speed); //Adds an Emergency Rover to List of Emergency Rovers
	void AddMountainousRover(double speed); //Adds a Mountainous Rover to List of Mountainous Rovers
	bool CancelMission(int ID); //Cancels a given Mission
	void Promote(int ID);// prmote Mountainous mission 
	/*******************/

	/********Simulation********/
	void Simulate();// simulte all function needed every day
	void DailyEvent();// Excute the events 
	void Add2MM(MountainousMission* M);
	void Add2PM(PolarMission* P);
	void Add2EM(EmergencyMission* E);
	void CheukupSim();//check if the Cheukup done 
	void assigEM();// assign Emergency missions
	void assigPM();// assign Polar missions
	void assigMM();// assign Mountainous missions
	void ExecutionSim();// check if the Execution done 
	void AutoPromote();// auto prmote Mountainous missions
	void setAutoPromotion(int AutoP); //Not Used
	void IncreaseMM();
	/*********************/

	/*********Modes***********/
	int Choose_Mode();		 //return Chosen Mode
	void Set_Mode(int x);	 //set Chosen Mode
	/*********************/

	/********Mission Failed*******/
	string FailedMissionsPrint();
	void resetFailedMission();
	void setMaxPeriod(int MaxPeriod);
	void failMission();
	/*********************/

	/*****Read & Write From/In Files******/
	void ReadInputFile();
	void PrintinOutputFile();
	//Return info of completed Missions, (Ap) should be removed from paramters
	void PrintCompletedInfo(int& CD, int& ID, int& FD, int& ED, int& WD, int& em, int& pm, int& mm);
	/*********************/

	/******Handling Corner Cases Of Rovers****/
	bool CanDoEM();//if can do Emergency missions or not 
	bool CanDoMM();//if can do Mountainous missions or not 
	bool CanDoPM();//if can do Polar missions or not 
	void IncreaseNumMDE();// increase num of  Mountainous mision can't done
	void IncreaseNumPDE();//increse num of polar mission can't done
	void IncreaseNumEDE();//increse num of emergency mission can't done
	int CountRovers(int& Er, int& Mr, int& Pr); //Count Rovers of Each Type
	/********************/

	/****Set The Rovers & Mission Data Before EXE ***/
	void SetDataEX(Mission* m, Rover* R);
	/********************/

	/*******Rovers in Excution*******/
	bool AssigntoER(Mission* m);// asssign missions to emergency rover
	bool AssigntoMR(Mission* m);// asssign missions to Mountainous rover
	bool AssigntoPR(Mission* m);// asssign missions to polar rover
	/********************/

	/******Printing in Console*********/
	Pair<int, string> PrintWaitingMission();
	Pair<int, string> PrintExecetion();
	Pair<int, string>Printavailable();
	Pair<int, string> PrintCompleted();
	Pair<int, string> PrintCheukUp();
	Pair<int, string> PrintMaintenece();
	int getDay();
	/*********************/

	/**********Destructor*******/
	~MarsStation();
	/*********************/

	/*********CheckUp**********/
	void setCheckUpData(int MCheckUp, int PCheckUp, int ECheckUp, int NMission2CheckUp);
	/**************************/
};