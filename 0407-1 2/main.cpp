//
//  main.cpp
//  0407-1
//
//  Created by Serg on 7/4/17.
//  Copyright © 2017 Sergii Kushnir. All rights reserved.
//

#include <iostream>


#include "Son.hpp"

using namespace std;
using namespace grandpa;
using namespace daddy;
using namespace son;




void func(Grandpa* arr[] )   {
    for (int i = 0; i < 3; i++) {
        arr[i]->Sleep();
        if (Daddy *temp  = dynamic_cast<Daddy*>(arr[i])) {
            temp->Walk();
        }
        if (son::Son *temp  = dynamic_cast<Son*>(arr[i])) {
            temp->Play();
        }
    }
}


void func2(Grandpa* arr[] ) {
    for (int i = 0; i < 3; i++) {
        arr[i]->Sleep();
        
        if (typeid(Daddy) == typeid(*arr[i])) {
            dynamic_cast<Daddy*>(arr[i])->Walk();
        }
        
        if (typeid(Son) == typeid(*arr[i])) {
            dynamic_cast<Son*>(arr[i])->Play();
        }
    }
}


using namespace grandpa;

int main(int argc, const char * argv[]) {
    
    Grandpa * arr[] = {new Grandpa("BOB"), new Daddy("Onufrii"),new son::Son("Tom")};
    
    
    func2(arr);
    
    cout<<"================\n";
    
    //func(arr);
    
    for (auto a : arr) {
        delete a;
    }

    return 0;
}
