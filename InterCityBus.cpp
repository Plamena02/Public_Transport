#include "InterCityBus.h"

IntercityBus::IntercityBus() : ElectricBus() {
	breakTime.hour = 0;
	breakTime.minutes = 0;
	distance = 0;
}

IntercityBus::IntercityBus(size_t DriverIdentityNumber, size_t vehicleID, MyString model, double battery, double batteryRange, double chargingRate, MyString startDestination, MyString finalDestination, size_t sH, size_t sM, size_t fH, size_t fM, size_t bH, size_t bM, size_t distance) :
	ElectricBus(DriverIdentityNumber, vehicleID, model, battery, batteryRange, chargingRate, startDestination, finalDestination, sH, sM, fH, fM), distance(distance) {
	if (!setBreak(bH, bM)) {
		std::cout << "No, check your time entry!\n";
	}
	type = Vehicle::ElectricType::E_INTERCITY_BUS;
}

bool IntercityBus::setBreak(size_t bH, size_t bM) {
	if (startTime.hour > bH || startTime.hour * 60 + startTime.minutes > bH * 60 + bM) {
		return false;
	}
	breakTime.hour = bM;
	breakTime.minutes = bM;
	return true;
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
	std::cout << "\t Break time: " << breakTime.hour << ":" << breakTime.minutes << " for " << breakMinutes << " minutes\n" << "\t Distance between cities: " << distance << std::endl;
}