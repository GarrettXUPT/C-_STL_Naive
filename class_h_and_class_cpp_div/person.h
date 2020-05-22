// #ifdef PERSON_H
// #define PERSON_H
#include<string>
#include<iostream>
using namespace std;
// #endif

#pragma once

class Person{
public:
    string mName; 
    int mAge;
    int mId;
public:
    Person();
    Person(string name, int age, int id);
    ~Person();
    void show();
    // 运算符重载
    friend ostream& operator << (ostream& os, Person &p);
};