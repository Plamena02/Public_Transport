#pragma once
#include "Vehicle.h"

class ElectricCar : public Vehicle { //Electric Taxi car
	bool babyChair;
	bool smallCar;
public:
	ElectricCar();
	ElectricCar(size_t, size_t, MyString, double, double, double, bool, bool);

	bool driveVehicle(const double) override; // km = how many km have you driven

	MyString getTypeString() const override;
	ElectricType getType() const override;
	Vehicle* clone() const override;

	void display() const override;

};