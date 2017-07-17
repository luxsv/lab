#include "String.h"

using namespace std;

String::String(int size) {
    str = new char[size]{};
}


String::String(const char* str2) {
    str = new char[strlen(str2)+1];
    strcpy(str,str2);
}


String::String(const String& st) {
    str = new char[strlen(st.str)+1];
    strcpy(str,st.str);
}

const String String::operator() (int position, int lern) {
    String temp((int)strlen(str)+1);
    
    try {
        
    if (position < 0 || position > strlen(str)-1)
        throw bad_start_position();
        
    if (lern+position >= strlen(str)+1 || lern <=0 )
        throw bad_lern();
    }
    
    
    catch(const bad_start_position& mess) {
        cout<< mess.what()<<endl;
        return temp;
    }
    
    catch(const bad_lern& mess) {
        cout<< mess.what()<<endl;
        return temp;
    }
    
    strncpy(temp.str, str+position, lern);
    
    return temp;
}



String::String(String&& st2) {
    str = st2.str;
    st2.str = nullptr;
    cout<<"work ctor copy\n";
}

String::~String() {
    if (this->str) {
        delete str;
    }
}


String String::operator + (const char* st2){
    char *newStr = new char[strlen(str) + strlen(st2)];
    strcpy(newStr, str);
    strcat(newStr,st2);
    return newStr;
}


String String::operator + (const String& st2) {
    char *newStr = new char[strlen(str) + strlen(st2.str)];
    strcpy(newStr, str);
    strcat(newStr,st2.str);
    return newStr;
}


String operator + (const char* st2 ,const String& st1) {
    char newStr [strlen(st2) + strlen(st1.GetStr())];
    strcpy(newStr,st2);
    return (String)strcat(newStr, st1.GetStr());
}


String& String::operator = (String && st2) {
    if(this == &st2) {
        cout<<"movet self"<<endl;
        return *this;
    
    }
    if(str) { delete str; }
    
    str = st2.str;
    st2.str = nullptr;
    
    //cout<<"operator &&  - work\n";
    return *this;
}


String& String::operator = (const char* st2) {
    if(str) { delete str; }
    str = new char [strlen(st2)+1];
    strcpy(str,st2);
    return *this;
}


char& String::operator [] (int index) {
    static char err = '\n';
    try {
        if (index < 0 || index > strlen(str)-1) {
            throw out_of_range();
        }
    } catch(const out_of_range& mess) {
        std::cout<<mess.What()<<endl;
        return err;
    }
    
    return this->str[index];
}


//String String::operator = (const String& st2) {
//    if (str) {delete[] str;}
//    str = new char[strlen(st2.str)+1];
//    strcpy(str, st2.str);
//    return (String) str ;
//}


String String::operator * (const String& st2) {
    char temp[80];
    char *p = strpbrk(str,st2.str);
    int i=0;
    while (p != NULL) {
        sprintf(temp+i ,"%c", *p);
        ++i;
        p = strpbrk(p+1,st2.str);
    }
    return String(temp);
}

String String::operator *= (const String& st2) {
    *this = *this * st2;
    return String(*this);
}

String String::operator /= (const String& st2) {
    *this = *this / st2;
    return String(*this);
}



String String::operator / (const String& st2) {
    char temp[80];
    for (int i = 0, j = 0; str[i] != 0; i++) {
        if (!strchr(st2.str,str[i])) {
            sprintf(temp+j ,"%c", str[i]);
            ++j;
        }
    }
    return String(temp);
}


String String::operator += (const String& st2) {
    String temp(*this);
    if (str) {delete[] str;}
    str = new char[strlen(st2.str)+1 +strlen(str)];
    strcpy(str, temp.str);
    strcat(str, st2.str);
    return (String) str ;
}


String String::operator ! () {
    int size = (int)strlen(str);
    static String rever(size+1);
    for (int i = 0, j = size-1; i < size; i++, j--) {
        rever.str[i] = str[j];
    }
    return rever;
}


String String::operator ++ () {
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[i] +1;
    }
    return *this;
}


String String::operator ++ (int) {
    String a(*this);
    for (int i = 0; i < strlen(str); i++) {
        str[i] = str[i] +1;
    }
    return a;
}


bool String::operator == (const String& st2) {
    return !strcmp(str, st2.str);
}


bool String::operator != (const String& st2) {
    return !(*this == st2);
}


bool String::operator > (const String& st2) {
    return strcmp(str, st2.str) >  0 ? true: false;
}


bool String::operator >= (const String& st2) {
    return (*this == st2 || *this > st2);
}


bool String::operator < (const String& st2) {
    return !(*this == st2 || *this > st2);
}


bool String::operator <= (const String& st2) {
    return (*this == st2 || *this < st2);
}


void String::Print() const {
    cout<<str<<endl;
}




String::operator int() {
    try {
        if(!isdigit(*this->str))
            throw bad_cast();
            
    } catch (bad_cast& bc) {
        cout<<bc.what()<<endl;
        return 0;
    }
        
    return atoi(str);
}
        
        
    String::operator double() {
        try {
            if(!isdigit(*this->str))
                throw bad_cast();
            
        } catch (bad_cast& bc) {
            cout<<bc.what()<<endl;
            return 0;
        }
        
        return atof(str);
    }
        

        

//template <typename T>
//void String::CountChar(const initializer_list<T> &list) {
//    for (auto p = list.begen(); p < list.end();++p) {
//        auto *ptr = strchr(str, *p);
//        int count = 0;
//        while(ptr !=nullptr) {
//            ++count;
//            ptr = strchr(ptr+1, *p);
//        }
//        if (count) {
//            cout<<*p<<" = "<<count<<endl;
//        }
//    }
//}









