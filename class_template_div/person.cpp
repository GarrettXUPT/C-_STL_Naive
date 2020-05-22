#include"person.h"

template<class T1, class T2>
person<T1, T2>::person(T1 name, T2 id, T2 age){
    this->mName = name;
    this->mID = id;
    this->mAge = age;
}

template<class T1, class T2>
person<T1, T2>::~person(){
    cout << "release" << endl;
}

template<class T1, class T2> 
void person<T1, T2>::show(){
    cout << "name = " << this->mName << " Id = " << this->mID << " age = " << mAge << endl;
}
