//
//  Grandpha.h
//  0407-1
//
//  Created by Serg on 7/4/17.
//  Copyright © 2017 Sergii Kushnir. All rights reserved.
//

#ifndef Grandpha_h
#define Grandpha_h
#include <iostream>
#include <string.h>
using namespace std;

namespace grandpa {
    
class Grandpa {
protected:
    string name;
public:
    Grandpa(const string& name) : name(name) {}
    virtual void Sleep() const {
        
        cout<<"Sleep : "<<typeid(*this).name()+9<<endl;
        
        cout<<"name = "<< name<<endl;
        string* p = const_cast<string*>(&name);
        *p = "i edit const func name";
    }
    
};

}

#endif /* Grandpha_h */
