#include "ElectricCar.h"

ElectricCar::ElectricCar() : Vehicle(), numberOfSeats(4) {
	type = ElectricType::E_CAR;
}

ElectricCar::ElectricCar(size_t DriverIdentityNumber, size_t vehicleID, MyString model, double battery, double batteryRange, double chargingRate, size_t numberOfSeats) :
	Vehicle(DriverIdentityNumber, vehicleID, model, battery, batteryRange, chargingRate), numberOfSeats(numberOfSeats){
	type = ElectricType::E_CAR;
}

bool ElectricCar::driveVehicle(const double km) {
	if (getBattery() <= 10) return false;
	double possibleDrivenDistance = (getBatteryRange() * getBattery()) / 100;
	if (km > possibleDrivenDistance) return false;
	double battery = ((getBatteryRange() - km) * 100) / getBatteryRange();
	setBattery(battery);
	return true;
}

MyString ElectricCar::getTypeString() const {
	return "Electric Car";
}

Vehicle::ElectricType ElectricCar::getType() const {
	return ElectricType::E_CAR;
}

Vehicle* ElectricCar::clone() const {
	return new ElectricCar(*this);
}

void ElectricCar::display() const {
	std::cout << "Electric Taxi car's";
	Vehicle::display();
	std::cout << "Number of seats " << numberOfSeats << '\n';
}

void ElectricCar::occupy(){ isFree = false; }
void ElectricCar::free(){ isFree = true; }
bool ElectricCar::isOccupied() const{ return isFree; }