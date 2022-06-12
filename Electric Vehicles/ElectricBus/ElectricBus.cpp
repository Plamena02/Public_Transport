#include "ElectricBus.h"

ElectricBus::ElectricBus() : Vehicle() {
	setTime(0, 0, 0, 0);
}

ElectricBus::ElectricBus(size_t DriverIdentityNumber, size_t vehicleID, MyString model, double battery, double batteryRange, double chargingRate, MyString startDestination, MyString finalDestination, size_t sH, size_t sM, size_t fH, size_t fM) :
	Vehicle(DriverIdentityNumber, vehicleID, model, battery, batteryRange, chargingRate) {
	listOfStops.pushBack(startDestination);
	listOfStops.pushBack(finalDestination);
	if (!setTime(sH, sM, fH, fM)) {
		std::cout << "No, check your time entry!\n";
	}
}

void ElectricBus::display() const {
	Vehicle::display();
	size_t indexFinalDestination = listOfStops.getSize() - 1;
	std::cout << "Starting destination: " << listOfStops[0]
	<< "\n \t At: " << startTime.hour << ":" << startTime.minutes
		<< "\n Final destination: " << listOfStops[indexFinalDestination]
		<< "\n \t At: " << finalTime.hour << ":" << finalTime.minutes << "\n";
}

bool ElectricBus::setTime(size_t sHour, size_t sMin, size_t fHour, size_t fMin) {
	if ((sHour < 24 && fHour < 24 && sMin <= 60 && fMin <= 60) && (sHour * 60 + sMin > fHour * 60 + fMin)) {
		return false;
	}
	startTime.hour = sHour;
	startTime.minutes = sMin;
	finalTime.hour = fHour;
	finalTime.minutes = fMin;
	return true;
}

bool ElectricBus::driveVehicle(const double km) {
	if (getBattery() <= 15)
		return false;
	double possibleDrivenDistance = (getBatteryRange() * getBattery()) / 100;
	if (km > possibleDrivenDistance) {
		return false;
	}
	double battery = ((getBatteryRange() - km) * 100) / getBatteryRange();
	setBattery(battery);
	return true;
}