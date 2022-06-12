#pragma once
#include "MyString.h"
#include <iostream>

class Vehicle {
	size_t DriverIdentityNumber;
	size_t vehicleID;
	MyString model;
	double battery; //%
	double batteryRange; //kilometers
	double chargingRate; //1.5 km per min
protected:
	enum class ElectricType{
		E_SCOOTER,
		E_CAR,
		E_CITY_BUS,
		E_INTERCITY_BUS,
		UNKNOWN
	}type;
public:
	Vehicle();
	Vehicle(size_t, size_t, MyString, double, double, double);
	virtual ~Vehicle() {};

	bool needCharging() const;
	double getMinutesToCharge() const;
	bool chargeBattery();
	virtual bool driveVehicle(const double) = 0; // km = how many km have you driven
	
	bool setBattery(const double);
	double getBattery() const;
	double getBatteryRange() const;

	virtual MyString getTypeString() const = 0;
	virtual ElectricType getType() const = 0;
	virtual Vehicle* clone() const = 0;

	virtual void display() const;
};