#include "String.h"
#include <iostream>
#define LINE cout<<"----------------------\n";
using namespace std;


// - -

template <typename T>
void mySwap(T& first, T& second) {
    T temp = move(first);
    first = move(second);
    second = move(temp);
}

// - -


int main(int argc, const char * argv[]) {
    //01.06.2017 DZ
//    String hello;
//    hello = "Hello";
//    String newHello(hello);
//    //cin>>newHello;
//    cout<<newHello<<endl;
//    
//    String microsoft = "1.25Microsoft";
//    String windows = "Windows";
//    cout<<microsoft*windows<<endl;
//    cout<<microsoft/windows<<endl;
//    LINE
//    cout<<microsoft+windows<<endl;
//    cout<<"Microsoft "+windows<<endl;
//    cout<<microsoft+" Windows"<<endl;
//    cout<<"finish : "<<microsoft<<windows<<endl;
//    
//    LINE
//    cout<<boolalpha<<(microsoft == windows )<<endl;
//    cout<<boolalpha<<(microsoft != windows )<<endl;
//    cout<<boolalpha<<(microsoft > windows )<<endl;
//    cout<<boolalpha<<(microsoft < windows )<<endl;
//    LINE
//    cout<<int(microsoft)<<endl;
//    cout<<double(microsoft)<<endl;
//    
//    LINE LINE LINE
//    
//    microsoft[0] = 'Q';
//    cout<<microsoft<<endl;
//    cout<<microsoft[5]<<endl;
//    
//    
//    String winda = "Windows";
//    cout<<!winda<<endl;
//    cout<<winda++<<endl;
//    cout<<winda<<endl;
//    cout<<++winda<<endl;
//    winda = "12.3newWindows";
//    cout<<int(winda)<<endl;
//    cout<<double(winda)<<endl;
//    
//    LINE LINE
//
//    winda = "Windows";
//    winda[7] = 'z';
//    cout<<winda<<endl;
//    cout<<winda(1)<<endl;
//    LINE
//    microsoft = "Microsoft";
//    
//    windows = "Windows";
//    microsoft/=windows;
//
//    cout<<microsoft<<endl;
//    microsoft = "Microsoft";
//    windows = "Windows";
//    
//    microsoft *= windows;
//    cout<<microsoft<<endl;
    
    
    
    String test = "Helloo";

    //cout<<test[10]<<endl;
    
    cout<<test(2,2)<<endl;
    cout<<test(-1,2)<<endl;
    cout<<test(0,100)<<endl;
    
    cout<<test(1,5)<<endl;
   

    
   // int a = int(test);
    
   // cout<<a<<endl;
    
    
    //test.CountChar<char>({'o','r'});
//    test.deleteChar<char>({'o'});
//    test.Print();

 
    return 0;
}
