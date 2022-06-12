#include "InterCityBus.h"

IntercityBus::IntercityBus() : ElectricBus() {
	breakTime.hour = 0;
	breakTime.minutes = 0;
}

IntercityBus::IntercityBus(size_t DriverIdentityNumber, size_t vehicleID, MyString model, double battery, double batteryRange, double chargingRate, MyString startDestination, MyString finalDestination, size_t sH, size_t sM, size_t fH, size_t fM, size_t bH, size_t bM) :
	ElectricBus(DriverIdentityNumber, vehicleID, model, battery, batteryRange, chargingRate, startDestination, finalDestination, sH, sM, fH, fM) {
	try{ setBreak(bH, bM); }
	catch(const std::invalid_argument &e){ throw e; }
	type = Vehicle::ElectricType::E_INTERCITY_BUS;
}

void IntercityBus::setBreak(size_t bH, size_t bM) {
	if ((bH < 24 && bM <= 60) && (startTime.hour > bH || startTime.hour * 60 + startTime.minutes > bH * 60 + bM) &&
		(finalTime.hour < bH || finalTime.hour * 60 + finalTime.minutes < bH * 60 + bM)) {
		throw std::invalid_argument("Time period is wrong");
	}
	breakTime.hour = bM;
	breakTime.minutes = bM;
}

bool IntercityBus::isItWorkingAt(Time& time) const {
	if (time.hour * 60 + time.minutes > startTime.hour * 60 + startTime.minutes && time.hour * 60 + time.minutes < finalTime.hour * 60 + finalTime.minutes
		&& time.hour* 60 + time.minutes < breakTime.hour * 60 + breakTime.minutes && time.hour * 60 + time.minutes > breakTime.hour * 60 + breakTime.minutes + breakMinutes)
		return true;
	return false;
}

MyString IntercityBus::getTypeString() const {
	return "Electric Intecrity Bus";
}

Vehicle::ElectricType IntercityBus::getType() const {
	return ElectricType::E_INTERCITY_BUS;
}

Vehicle* IntercityBus::clone() const {
	return new IntercityBus(*this);
}

void IntercityBus::display() const {
	std::cout << "Intercity bus'";
	ElectricBus::display();
	std::cout << "\t Break time: " << breakTime.hour << ":" << breakTime.minutes << " for " << breakMinutes << " minutes\n";
}

double IntercityBus::calculateNeededBatteryForDistance(const double distance) const {
	double res = (distance * 100) / getBatteryRange();
	if (res > 100) {
		return -1; // If it is not possible for the battery to withstand the entire distance
	}
	return res; 
}