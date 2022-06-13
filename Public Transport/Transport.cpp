#include <iostream>
#include "Transport.h"
#include "../MyString/MyString.h"
#include "../Electric Vehicles/IntercityBus/InterCityBus.h"
#include "../Electric Vehicles/Electric Car/ElectricCar.h"
#include "../Electric Vehicles/Electric Scooter/ElectricScooter.h"
#include "../Electric Vehicles/CityBus/CityBus.h"

using namespace std;


Vector<Driver> Transport::drivers;
Container Transport::vehicles;

void Transport::menu(){

    MyString command;

    while(true){

        cin.ignore();
        cin >> command;

        if(command == "exit") break;
        if(command == "print") print();
        if(command == "add") add();
        if(command == "remove") remove();
        if(command == "travel") travel();

    }
}

void Transport::travel()
{
    MyString inCity, start, end;
    double km;
    cin >> inCity;
    cin >> start >> end;
    cin >> km;
    
    if(inCity == "city")
    {
        for(size_t i = 0; i < Transport::vehicles.getSize(); i++)
       {    
            if (Transport::vehicles[i] -> getType() != Vehicle::E_INTERCITY_BUS)
                if(Transport::vehicles[i] -> getType() == Vehicle::E_CITY_BUS && dynamic_cast<CityBus *>(Transport::vehicles[i]) -> rideFromTo(start, end) && Transport::vehicles[i]->driveVehicle(km))
                {
                    cout << "You can take " << Transport::vehicles[i]->getTypeString() << '\n';
                    break;
                }
                else if(Transport::vehicles[i]->driveVehicle(km)){

                    cout << "You can take " << Transport::vehicles[i]->getTypeString() << '\n';
                    break;

                }
       }
    }
    else
    {
        for(size_t i = 0; i < Transport::vehicles.getSize(); i++)
        {    
            if (Transport::vehicles[i]->getType() == Vehicle::E_INTERCITY_BUS && dynamic_cast<IntercityBus *>(Transport::vehicles[i])->rideFromTo(start, end) && Transport::vehicles[i]->driveVehicle(km))
            {
                cout << "You can take " << Transport::vehicles[i]->getTypeString() << '\n';
                break;
            }
       }
       
    }  
     
}

void Transport::print(){
    // drivers or vehicle?
    cin.ignore();
    for(size_t i = 0; i < Transport::vehicles.getSize(); i++)
       {    
            cout << i + 1 << ". "; 
            Transport::vehicles[i] -> display();
            cout << endl;
       }

}
void Transport::add(){

    MyString input;

    cin >> input;

    if(input == "driverB"){

        MyString name;

        size_t id, age;
        cin >> name >> id >> age;
        Transport::drivers.pushBack(Driver(name, id, age, Driver::B));
    }
    else if(input == "driverD"){

        MyString name;

        size_t id, age;
        cin >> name >> id >> age;
        Transport::drivers.pushBack(Driver(name, id, age, Driver::D));
    }
    else if(input == "bus"){

        MyString model, start, end, breakStop;
        size_t idDriver, idVehicle, sH, sM, fH, fM, bH, bM, breakMinutes;
        double range, rate;
        cin >> idDriver >> idVehicle >> model >> range >> rate >> start >> end >> sH >> sM >> fH >> fM >> bH >> bM >> breakMinutes >> breakStop;
        Transport::vehicles.pushBack(new IntercityBus(idDriver, idVehicle, model, range, rate, start, end, sH, sM, fH, fM, bH, bM, breakMinutes, breakStop));
    }
    else if(input == "cityBus"){

        MyString model, start, end;
        size_t idDriver, idVehicle, sH, sM, fH, fM, capacity;
        double range, rate;
        cin >> idDriver >> idVehicle >> model >> range >> rate >> start >> end >> sH >> sM >> fH >> fM >> capacity;
        Transport::vehicles.pushBack(new CityBus(idDriver, idVehicle, model, range, rate, start, end, sH, sM, fH, fM, capacity));
    }
    else if(input == "car"){

        MyString model;
        size_t idDriver, idVehicle, seats;
        double range, rate;
        cin >> idDriver >> idVehicle >> model >> range >> rate >> seats;
        Transport::vehicles.pushBack(new ElectricCar(idDriver, idVehicle, seats, model, range, rate));
    }
    else if(input == "scoter"){

        MyString model;
        size_t idVehicle;
        double range, rate;
        cin >> idVehicle >> model >> range >> rate;
        Transport::vehicles.pushBack(new ElectricScooter(idVehicle, model, range, rate));
    }
    

    cout << "Successfully created " << input << ")\n";
    cin.ignore();
    
}

void Transport::remove(){

    size_t index;

    cin >> index;
    cin.ignore();

    --index;

    if(Transport::vehicles.getSize() <= index){

        cout << "There is no vehicle number " << index + 1 << "!\n";
        return;
    }

    Transport::vehicles.popAt(index);
    cout << "Erased a vehicle" << ")\n"; 
}