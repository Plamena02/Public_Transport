#pragma once
#include "ElectricBus.h"
class IntercityBus : public ElectricBus {

public:
	IntercityBus();
	IntercityBus(size_t, size_t, const MyString&, double, double, const MyString&, const MyString&, size_t, size_t, size_t, size_t, size_t, size_t, size_t, const MyString&);

	bool isItWorkingAt(size_t, size_t) const override;

	MyString getTypeString() const override;
	ElectricType getType() const override;
	Vehicle* clone() const override;

	MyString getBreakDestination() const;
	double calculateNeededBatteryForDistance(const double) const;
	void display() const override;

	private:
		MyString breakStop;
		size_t breakMinutes;

};