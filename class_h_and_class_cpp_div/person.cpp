#include "person.h"

    Person::Person(){}

    Person::Person(string name, int age, int id){
        this->mAge = age;
        this->mId = id;
        this->mName = name;
    }

    Person::~Person(){
        cout << "this is a desiable" << endl;
    }
    
    void Person::show(){
        cout << "name = " << this->mName << " Id = " << this->mId << " age = " << mAge << endl;
    }

    // 运算符重载
    ostream& operator << (ostream& os, Person &p){
        os << "name = " << p.mName << " Id = " << p.mId << " age = " << p.mAge << endl;
    }