#pragma once
#include "Vehicle.h"

class ElectricCar : public Vehicle { //Electric Taxi car

	public:
		ElectricCar();
		ElectricCar(size_t, size_t, MyString, double, double, double, size_t);

		bool driveVehicle(const double) override; 

		MyString getTypeString() const override;
		ElectricType getType() const override;
		Vehicle* clone() const override;
		void occupy();
		void free();
		bool isOccupied() const;

		void display() const override;
	
	private:
		size_t numberOfSeats;
		bool isFree;

};