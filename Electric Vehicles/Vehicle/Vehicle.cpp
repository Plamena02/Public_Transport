#include "Vehicle.h"

bool Vehicle::needCharging() const {
	if (battery >= 100) {
		return false;
	}
	return true;
}

double Vehicle::getMinutesToCharge() const {
	double kilometers = (batteryRange * battery) / 100;
	double minutes = kilometers / chargingRate;
	return minutes;
}
bool Vehicle::chargeBattery() {
	if (!needCharging()) {
		// std::cout << "Battery is full!\n";
		return false;
	}
	double minutes = getMinutesToCharge();
	std::cout << "Battery charged! It took" << minutes << " minutes. \n";
	battery = 100;
	return true;
}

void Vehicle::setBattery(const double battery) {
	this->battery = battery;
}

double Vehicle::getBattery() const {
	return battery;
}

double Vehicle::getBatteryRange() const {
	return batteryRange;
}

Vehicle::Vehicle() : DriverIdentityNumber(0), vehicleID(0), model(""), battery(100), batteryRange(0), chargingRate(0) {
	type = ElectricType::UNKNOWN;
}

Vehicle::Vehicle(size_t DriverIdentityNumber,size_t vehicleID,MyString model, double battery, double batteryRange, double chargingRate) :
	DriverIdentityNumber(DriverIdentityNumber), model(""), vehicleID(vehicleID), battery(battery), batteryRange(batteryRange), chargingRate(chargingRate) {
	type = ElectricType::UNKNOWN;
}

void Vehicle::display() const {
	std::cout << " Id: " << vehicleID << "\n Model: " << model
		<< "\n Battery at the moment: " << battery << "\n Battery range: " << batteryRange
		<< "\n Chargint rate kilometer per minute: " << chargingRate << "\n";
}

