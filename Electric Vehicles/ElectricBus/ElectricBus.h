#pragma once
#include "Vehicle.h"
#include "vector.hpp"
class ElectricBus : public Vehicle {
protected:
	Vector<MyString> listOfStops;
	struct Time
	{
		size_t hour, minutes;
	} startTime, finalTime;
public:
	ElectricBus();
	ElectricBus(size_t, size_t, MyString, double, double, double, MyString, MyString, size_t, size_t, size_t, size_t);
	// Does the bus work at that time or it is at garage
	virtual bool isItWorkingAt(Time&) const = 0;

	bool setTime(size_t, size_t, size_t, size_t);
	bool driveVehicle(const double) override; // km = how many km have you driven

	void display() const override;
};