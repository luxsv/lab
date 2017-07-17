//
//  Daddy.hpp
//  0407-1
//
//  Created by Serg on 7/4/17.
//  Copyright © 2017 Sergii Kushnir. All rights reserved.
//

#ifndef Daddy_hpp
#define Daddy_hpp

#include "Grandpa.hpp"

using namespace std;
using namespace grandpa;

namespace daddy {
    class Daddy : public Grandpa {
    public:
        Daddy(const std::string& name) : Grandpa(name) {}
        virtual void Walk() const;    };
    
}
#endif /* Daddy_hpp */
