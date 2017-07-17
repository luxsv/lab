//
//  Son.hpp
//  0407-1
//
//  Created by Serg on 7/4/17.
//  Copyright © 2017 Sergii Kushnir. All rights reserved.
//

#ifndef Son_hpp
#define Son_hpp
#include "Daddy.hpp"

using namespace std;
using namespace grandpa;
using namespace daddy;

namespace son {
    class Son : public Daddy  {
    public:
        Son(const string& name) : Daddy(name) {}
        virtual void Walk() const ;
        
        virtual void Play() const {
            cout<<"Play Son"<<endl;
        }
        
        
    };
}


#endif /* Son_hpp */
