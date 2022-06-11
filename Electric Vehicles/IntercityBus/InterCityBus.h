#pragma once
#include "ElectricBus.h"
#include "vector.hpp"
class IntercityBus : public ElectricBus {
	double distance;
	ElectricBus::Time breakTime;
	size_t breakMinutes = 30;
public:
	IntercityBus();
	IntercityBus(size_t, size_t, MyString, double, double, double, MyString, MyString, size_t, size_t, size_t, size_t, size_t, size_t, size_t);
	// Does the bus work at that time or it is at garage
	bool isItWorkingAt(Time&) const override;

	MyString getTypeString() const override;
	ElectricType getType() const override;
	Vehicle* clone() const override;

	bool setBreak(size_t, size_t);
	double calculateNeededBatteryForDistance() const;
	void display() const override;
};