#include "ElectricCar.h"

ElectricCar::ElectricCar() : Vehicle(), babyChair(false), smallCar(true) {
	type = ElectricType::E_CAR;
}

ElectricCar::ElectricCar(size_t DriverIdentityNumber, size_t vehicleID, MyString model, double battery, double batteryRange, double chargingRate, bool chair, bool size) :
	Vehicle(DriverIdentityNumber, vehicleID, model, battery, batteryRange, chargingRate), babyChair(chair), smallCar(size) {
	type = ElectricType::E_CAR;
}

bool ElectricCar::driveVehicle(const double km) {
	if (getBattery() <= 10)
		return false;
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
	std::cout << "BabyChair: " << std::boolalpha << babyChair << "\n This Car is: ";
	if (smallCar) {
		std::cout << "Small \n";
	}
	else {
		std::cout << "Big \n";
	}
}