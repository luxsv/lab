//
//  Grandpa.cpp
//  0407-1
//
//  Created by Serg on 7/4/17.
//  Copyright © 2017 Sergii Kushnir. All rights reserved.
//

#include "Grandpa.hpp"

using namespace grandpa;

void Grandpa::Sleep() const {
    
    cout<<"Sleep : "<<typeid(*this).name()<<endl;
    
    cout<<"name = "<< name<<endl;
    string* p = const_cast<string*>(&name);
    *p = "i edit const func name";
}
