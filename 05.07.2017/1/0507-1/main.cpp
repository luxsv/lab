//
//  main.cpp
//  0507-1
//
//  Created by Serg on 7/5/17.
//  Copyright © 2017 Sergii Kushnir. All rights reserved.
//

#include <iostream>
#include <cmath>

using namespace std;


bool isValidTrian(int a, int b, int c ) {
    if(a > 0 && b > 0 && c > 0) {
        if(a+b > c && a+c >b && c+b >a && c+a > b) {
            return true;
        }
    }
    return false;
};



double squareTrian(int a, int b, int c) {
    try {
        if (!isValidTrian(a, b, b)) {
            throw "Trian is nod valid\n";
        }
        double p = (a+b+c)/2;
        return sqrt(p*(p-a)*(p-b)*(p-c));
        
    } catch (const char* mes) {
        cout<<mes<<endl;
    }
    
    return 0;
}


int main(int argc, const char * argv[]) {
    
    
    cout<<"squareTrian = "<<squareTrian(3, 3, 3)<<endl;
    
    
    cout<<"squareTrian = "<<squareTrian(3, 1, 1)<<endl;
    
    
    return 0;
}
