#pragma once

#include<iostream>
#include<string>
using namespace std;

template<class T1, class T2>
class person
{
private:
    /* data */
public:
    person(T1 name, T2 id, T2 age);
    ~person();
    void show();
public:
    T1 mName;
    T2 mID;
    T2 mAge;
};
