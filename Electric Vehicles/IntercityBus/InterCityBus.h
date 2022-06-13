#pragma once
#include "../ElectricBus/ElectricBus.h"
class IntercityBus : public ElectricBus {

public:
	IntercityBus();
	IntercityBus(size_t, size_t, MyString, double, double, MyString, MyString, size_t, size_t, size_t, size_t, size_t, size_t, size_t, MyString);

	bool isItWorkingAt(size_t, size_t) const override;

	MyString getTypeString() const override;
	ElectricType getType() const override;
	Vehicle* clone() const override;

	void setBreak(const MyString &);
	double calculateNeededBatteryForDistance(const double) const;
	void display() const override;

	private:
		MyString breakStop;
		size_t breakMinutes;

};