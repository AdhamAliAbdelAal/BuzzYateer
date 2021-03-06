#include"Rover.h"
#include<cmath>
int Rover::COUNT = 0;
Rover::Rover(double speed, bool status, bool underMaintenance, int NoOfCheckUps) :noOfMissions(0), Speed(speed), ID(++COUNT),
MaintenenceDuration(0), underMaintenance(0), NoOfCheckUps(0)
{
}

void Rover::operator++()
{
	noOfMissions++;
}

void Rover::resetnoOfMissions()
{
	noOfMissions = 0;
}

void Rover::resetnoOfCheckUps()
{
	NoOfCheckUps = 0;
	resetnoOfMissions();
}

void Rover::NoOfCheckUpsIncrement()
{
	NoOfCheckUps++;
}

void Rover::setMaintenenceDuration(int MaintenenceDuration)
{
	this->MaintenenceDuration = MaintenenceDuration;
}

int Rover::getMaintenenceDuration()
{
	return MaintenenceDuration;
}

double Rover::getSpeed()
{
	if (underMaintenance)
	{
		Speed = ceil(Speed / 2);
		return Speed;
	}
	else
		return Speed;
}

int Rover::getnoOfMissions()
{
	return noOfMissions;
}

Rover::~Rover()
{
}

void Rover::setCheukDuration(int days)
{
	CheukDuration = days;
}

int Rover::getCheukDuration()
{
	return CheukDuration;
}

int Rover::getID()
{
	return ID;
}

int Rover::getNoOfCheckUps()
{
	return NoOfCheckUps;
}

void Rover::setMaintenance(bool x)
{
	underMaintenance = x;
}

bool Rover::geMaintenance()
{
	return underMaintenance;
}