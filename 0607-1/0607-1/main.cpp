//
//  main.cpp
//  0607-1
//
//  Created by Serg on 7/6/17.
//  Copyright © 2017 Sergii Kushnir. All rights reserved.
//

#include <iostream>
#include <cstring>

using namespace std;

class Auto {
public:
    class WrongCtrAuto {
    protected:
        string err;
    public:
        WrongCtrAuto(const string& err = "WrongCtrAuto\n" ) : err(err) {}
        const string& what(){
            return err;
        }
    };
    
    
    class WrongSpeed : public WrongCtrAuto{
    public:
        WrongSpeed() : WrongCtrAuto("WrongSpeed\n") {}
    };
    
    class InvalidNumber : public WrongCtrAuto {
    public:
        InvalidNumber() : WrongCtrAuto("InvalidNumber\n") {}
    };
    

private:
    string _number;
    const int MAX_SPEED = 300;
    const int MIN_SPEED = 0;
    int _speed;

public:
    
    
    Auto(const string& number, const int& speed) {
        if (speed < MIN_SPEED  || speed >= MAX_SPEED || number.size() > 7) {
            throw WrongCtrAuto();
        }
        SetSpeed(speed);
        SetNumber(number);
    }
    
    void UpSpeed(int up = 5) {
        try {
        if (_speed + up >= MAX_SPEED )
            throw WrongSpeed();
        }
        
        catch (WrongSpeed& mess) {
            cout<<mess.what();
            throw ;
        }
        
        
        _speed += up;
    }
    
    void DownSpeed(int up = 5) {
        try {
        if (_speed - up <= MIN_SPEED )
            throw WrongSpeed();
        }
        catch (WrongSpeed& mess) {
            cout<<mess.what();
            throw;
        }
        
        _speed -= up;
    }
    
    void SetSpeed(int speed) {
        try {
        if (speed < MIN_SPEED  || speed >= MAX_SPEED )
            throw WrongSpeed();
        } catch (WrongSpeed& mess) {
            cout<<mess.what();
            throw;
        }
        _speed=speed;
        
    }
    
    void SetNumber(const string& number) {
        try {
        if (number.size() > 7)
            throw InvalidNumber();
        }
        catch (InvalidNumber& mess) {
            cout<<mess.what();
            throw;
        }
        _number = number;
    }
    
    const string& GetNumber() const{
        return _number;
    }
    
    const int& GetSpeed() const{
        return _speed;
    }
    
};

ostream& operator << (ostream& os, Auto& a ) {
    return os <<"Number : " << a.GetNumber()<<" Speed : " <<a.GetSpeed();
    
}


int main(int argc, const char * argv[]) {
    
    try {
    
        Auto a("AA-777", 200);
        
       // a.SetSpeed(400);
       // a.DownSpeed(100);
        cout<<a<<endl;
    }
    
    catch(Auto::WrongSpeed& mess ) {
        cout<<mess.what();
    }
    
    catch(Auto::InvalidNumber& mess ) {
        cout<<mess.what();
    }
    
    catch(Auto::WrongCtrAuto& mess ) {
        cout<<mess.what();
    }
    
    
    
    return 0;
}
