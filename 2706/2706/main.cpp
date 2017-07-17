//
//  main.cpp
//  2706
//
//  Created by Serg on 6/28/17.
//  Copyright © 2017 Sergii Kushnir. All rights reserved.
//

#include <iostream>
#include <string>
#define LINE printf("========\n");
using namespace std;

class Vehicle {
public:
    enum Fuel {Petrol, Diesel, Other};
protected:
    string id;
    Fuel fuel;
    size_t mass;
    
    string getId() const {
        return id;
    }
    
public:
    Vehicle(const string& id = "0", Fuel fuel = Other, size_t mass = 0 ) : id(id), fuel(fuel), mass(mass)
    { }
};


class Car: virtual public Vehicle {
protected:
    string model;
    string type;
public:
    Car(const string& id = "0" , Fuel fuel = Diesel, size_t mass = 1000, const string& model = "007", const string& type = "Hatchback")
    : Vehicle( id, fuel,mass), model(model + "_Car"), type(type) { }
    
    void setID(const string& newID){
        id = newID;
    }
    
    void setModel(const string& newModel){
        model = newModel;
    }
};

class Ship : virtual public Vehicle {
protected:
    string model;
    string type;
public:
    Ship(const string& id = "0" , Fuel fuel =  Petrol , size_t mass = 1000, const string& model = "AA007", const string& type = "Сutter")
    : Vehicle( id, fuel,mass), model(model + "_Ship"), type(type) { }

    void Show() {
        cout<<"Model : "<<model<<endl;
        cout<<"Type : "<<type<<endl;
        cout<<"Id : "<<Vehicle::id<<endl;
        cout<<"Type : "<<type<<endl;
        cout<<"Fuel : "<<Vehicle::fuel<<endl;
        cout<<"mass : "<<Vehicle::mass<<endl;
    }
    
    void setID(const string& newID){
        id = newID;
    }
    
    void setModel(const string& newModel){
        model = newModel;
    }
    
};


class Amphibia : public Ship, public Car {
public:
    void Show() {
        cout<<"Model : " <<Ship::model<<endl;
        cout<<"Id : "<<id<<endl;
        cout<<"Type : "<<Ship::type<<endl;
        cout<<"Fuel : "<<fuel<<endl;
        cout<<"mass : "<<mass<<endl;
    }
    
    
    void setID(const string& newID){
        id = newID;
    }
    
    void setModel(const string& newModel){
        Ship::model = newModel;
    }
    
    Amphibia() {}
    
};



int main(int argc, const char * argv[]) {
    Ship a("ID90000", Vehicle::Fuel::Petrol, 1000);
    a.Show();
    LINE

    Amphibia b;
    b.setModel("Wcdsfdfdf");
    b.Show();
    
    
    return 0;
}
