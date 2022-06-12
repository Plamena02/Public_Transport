#include <iostream>
#include "Transport.h"
#include "MyString/MyString.h"
#include "Electric Vehicles/IntercityBus/IntercityBus.h"
#include "Electric Vehicles/Electric Car/ElectricCar.h"
#include "Electric Vehicles/ElectricBus/ElectricBus.h"
#include "Electric Vehicles/Electric Scooter/ElectricScooter.h"
#include "Electric Vehicles/CityBus/CityBus.h"

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
    MyString input;
    cin >> input;
    /*
    if(input == "city")
    {
        size_t h, m;
        for(size_t i = 0; i < Transport::vehicles.getSize(); i++)
       {    
            if (Transport::vehicles[i])
            {
                
            }
            
            Transport::vehicles[i] -> display();
            cout << endl;
       }
    }
    else
    {
        MyString end;
        cin >> end;
        for(size_t i = 0; i < Transport::vehicles.getSize(); i++)
        {    
            if (Transport::vehicles[i].)
            {
                
            }
            
            Transport::vehicles[i] -> display();
            cout << endl;
       }
       
    }   TO DO
    */ 
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

        MyString model, start, end;
        size_t idDriver, idVehicle, sH, sM, fH, fM, bH, bM;
        double battery, range, rate;
        cin >> idDriver >> idVehicle >> model >> battery >> range >> rate >> start >> end >> sH >> sM >> fH >> fM >> bH >> bM;
        Transport::vehicles.pushBack(new IntercityBus(idDriver, idVehicle, model, battery, range, rate, start, end, sH, sM, fH, fM, bH, bM));
    }
    else if(input == "cityBus"){

        MyString model, start, end;
        size_t idDriver, idVehicle, sH, sM, fH, fM, bH, bM;
        double battery, range, rate;
        cin >> idDriver >> idVehicle >> model >> battery >> range >> rate >> start >> end >> sH >> sM >> fH >> fM;
        Transport::vehicles.pushBack(new CityBus(idDriver, idVehicle, model, battery, range, rate, start, end, sH, sM, fH, fM));
    }
    else if(input == "car"){

        MyString model;
        size_t idDriver, idVehicle, seats;
        double battery, range, rate;
        cin >> idDriver >> idVehicle >> model >> battery >> range >> rate;
        Transport::vehicles.pushBack(new ElectricCar(idDriver, idVehicle, model, battery, range, rate, seats));
    }
    else if(input == "scoter"){

        MyString model;
        size_t idVehicle;
        double battery, range, rate;
        cin >> idVehicle >> model >> battery >> range >> rate;
        Transport::vehicles.pushBack(new ElectricScooter(idVehicle, model, battery, range, rate));
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