#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstring>
#include <exception>

using namespace std;

class String{
    
    
public:
    
    
    class out_of_range {
        std::string error;
    public:
        out_of_range() : error("Error index permission") {};
        const std::string What() const {
            return error;
        }
    };
    
    class bad_start_position : public logic_error
    {
    public:
        bad_start_position() : logic_error("bad_start_position") {};
    };
    
    
    class bad_lern : public logic_error
    {
    public:
        bad_lern() : logic_error("bad_lern") {};
    };
    
    
    
    
    String(int size = 80);
    String(String&&);
    String(const char* str2);
    String(const String& st);
    
    ~String();
    
    char* GetStr() const { return str; }
    void Print() const;
    
    String& operator = (String&& st2);
    String operator + (const String& st2);
    String operator + (const char* st2);
    String operator * (const String& st2);
    String operator / (const String& st2);
    
    friend ostream& operator << (std::ostream& os, const String& st) {
        if(st.str == nullptr) { os<<"!!object not exist!!!\n";}
        os <<st.GetStr();
        return os;
    }
    friend istream& operator >> (std::istream& is, const String& st) {
        is >> st.str;
        return is;
    }
  
    
    char& operator [] (int index);
   
    
    const String operator() (int position, int lern=1000);
    
    String& operator = (const char* st2);
    String& operator = (char && st2);
    String operator = (const String& st2);
    String operator += (const String& st2);
    String operator *= (const String& st2);
    String operator /= (const String& st2);
    String operator ! ();
    String operator ++ ();
    String operator ++ (int);
    
    bool operator == (const String& st2);
    bool operator != (const String& st2);
    bool operator >= (const String& st2);
    bool operator > (const String& st2);
    bool operator < (const String& st2);
    bool operator <= (const String& st2);
    operator int();
    operator double();
    operator float();
//    template <typename T>
//    void CountChar(const initializer_list<T> &list) {
//        for (auto p = list.begin(); p < list.end();++p) {
//            auto *ptr = strchr(str, *p);
//            int count = 0;
//            while(ptr !=nullptr) {
//                ++count;
//                ptr = strchr(ptr+1, *p);
//            }
//            if (count) {
//                cout<<*p<<" = "<<count<<endl;
//            }
//        }
//    }
//
//    template <typename T>
//    void deleteChar(const initializer_list<T> &list) {
//        
//        for (auto p = list.begin(); p < list.end();++p) {
//            auto *ptr = strchr(str, *p);
//            int count = 0;
//            while(ptr !=nullptr) {
//                ++count;
//                //
//                
//                
//                ptr = strchr(ptr+1, *p);
//            }
//            if (count) {
//                cout<<*p<<" = "<<count<<endl;
//            }
//        }
//    }
    
    
    
    
private:
    char * str;

};

String operator + (const char* st2, const String& st1);


#endif
