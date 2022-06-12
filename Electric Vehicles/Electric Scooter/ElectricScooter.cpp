#include "ElectricScooter.h"

ElectricScooter::ElectricScooter() : Vehicle() {
	type = ElectricType::E_SCOOTER;
}

ElectricScooter::ElectricScooter(size_t DriverIdentityNumber, size_t vehicleID, MyString model, double battery, double batteryRange, double chargingRate) : Vehicle(DriverIdentityNumber, vehicleID, model, battery, batteryRange, chargingRate) {
	type = ElectricType::E_SCOOTER;
}

bool ElectricScooter::driveVehicle(const double km) {
	if (getBattery() <= 5)
		return false;
	double possibleDrivenDistance = (getBatteryRange() * getBattery()) / 100;
	if (km > possibleDrivenDistance) {
		return false;
	}
	double battery = ((getBatteryRange() - km) * 100) / getBatteryRange();
	setBattery(battery);
	return true;
}

MyString ElectricScooter::getTypeString() const {
	return "Electric Scooter";
}

Vehicle::ElectricType ElectricScooter::getType() const {
	return ElectricType::E_SCOOTER;
}

Vehicle* ElectricScooter::clone() const {
	return new ElectricScooter(*this);
}

void ElectricScooter::display() const{
	std::cout << "Scooter's";
	Vehicle::display();
}