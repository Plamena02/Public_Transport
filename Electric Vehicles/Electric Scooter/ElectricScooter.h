#pragma once
#include "Vehicle.h"

class ElectricScooter : public Vehicle {
public:
	ElectricScooter();
	ElectricScooter(size_t, size_t, MyString, double, double, double);

	bool driveVehicle(const double) override; // km = how many km have you driven

	MyString getTypeString() const override;
	ElectricType getType() const override;
	Vehicle* clone() const override;

	void display() const override;
};