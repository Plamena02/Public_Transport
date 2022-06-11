#pragma once
#include "ElectricBus.h"
#include "vector.hpp"
class CityBus : public ElectricBus {
	Vector<MyString> listOfStops;
public:
	CityBus();
	CityBus(size_t, size_t, MyString, double, double, double, MyString, MyString, size_t, size_t, size_t, size_t);
	// Does the bus work at that time or it is at garage
	bool isItWorkingAt(Time&) const override;

	MyString getTypeString() const override;
	ElectricType getType() const override;
	Vehicle* clone() const override;

	void setStops(Vector<MyString>& stops);

	void addStop(MyString);
	bool addStopAtIndex(size_t index, MyString);
	bool removeStop(size_t);

	void display() const override;
};