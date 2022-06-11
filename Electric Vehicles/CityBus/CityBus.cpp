#include "CityBus.h"

CityBus::CityBus() : ElectricBus() {
}

CityBus::CityBus(size_t DriverIdentityNumber,size_t vehicleID, MyString model, double battery, double batteryRange, double chargingRate, MyString startDestination, MyString finalDestination, size_t sH, size_t sM, size_t fH, size_t fM) :
	ElectricBus(DriverIdentityNumber, vehicleID, model, battery, batteryRange, chargingRate, startDestination, finalDestination,sH,sM,fH,fM) {
	type = Vehicle::ElectricType::E_CITY_BUS;

}

bool CityBus::isItWorkingAt(Time& time) const {
	if (time.hour * 60 + time.minutes > startTime.hour * 60 + startTime.minutes && time.hour * 60 + time.minutes < finalTime.hour * 60 + finalTime.minutes)
		return true;
	return false;
}

MyString CityBus::getTypeString() const{
	return "Electric City Bus";
}

Vehicle::ElectricType CityBus::getType() const {
	return ElectricType::E_CITY_BUS;
}

Vehicle* CityBus::clone() const {
	return new CityBus(*this);
}

void CityBus::setStops(Vector<MyString>& stops) {
	listOfStops = stops;
}

void CityBus::addStop(MyString stop) {
	listOfStops.pushBack(stop);
}

bool CityBus::addStopAtIndex(size_t index, MyString stop) {
	if (index > listOfStops.getCapacity()) {
		return false;
	}
	listOfStops.pushAt(stop, index - 1);
	return true;
}

bool CityBus::removeStop(size_t index) {
	if (index >= listOfStops.getSize()) {
		return false;
	}
	listOfStops.popAt(index - 1);
	return true;
}

void CityBus::display() const {
	std::cout << "City bus'";
	ElectricBus::display();
	std::cout << "List of stops:\n";
	for (size_t i = 0; i < listOfStops.getSize(); i++) {
		std::cout << "\t\t" << listOfStops[i] << std::endl;
	}
}