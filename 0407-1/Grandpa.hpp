//
//  Grandpa.hpp
//  0407-1
//
//  Created by Serg on 7/4/17.
//  Copyright © 2017 Sergii Kushnir. All rights reserved.
//

#ifndef Grandpa_hpp
#define Grandpa_hpp


#include <iostream>
#include <string.h>
using namespace std;

namespace grandpa {
    
    class Grandpa {
    protected:
        string name;
    public:
        Grandpa(const string& name) : name(name) {}
        virtual void Sleep() const;
        
    };
    
}


#endif /* Grandpa_hpp */
