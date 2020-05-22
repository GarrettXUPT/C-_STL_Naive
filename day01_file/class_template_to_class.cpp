// 类模板派生普通类及模板类

#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>

using namespace std;

template<class T>
class Person
{
private:
    /* data */
public:
    Person(T age, T id){
        this->mId = id;
        this->mAge = age;
    };
   
    Person(){};  // 构造函数 空参和全餐都要有
    ~Person();
    void print(int id, int age){
        cout << "ID = " << mId << " age = " << mAge << endl;
    }
public:
    T mAge;
    T mId;
};

template<class T>
Person<T>::~Person(){
    cout << "release" << endl;
}

// 实用类定义对象，对象需要分配内存，所以要指定泛型的具体类型
template<class T>  // 若是普通类 将Person<int> 替换加入函数即可
class Personality : public Person<T>{
public:
    Personality(T a, T b){
        Person<T>::mId = a;
        Person<T>::mAge = b;
        this->mId = Person<T>::mId;
        this->mAge = Person<T>::mAge;
        };
    ~Personality(){};
    void print(int mId, int mAge){
        Person<T>::print(mId, mAge);
        cout << Person<T>::mId << "  " << Person<T>::mAge << endl;
    }
    T mAge;
    T mId;
private:

};

void personTest(){
    // Person<int> per(12, 12);
    // per.print();
    Personality<int> person1(12, 12); 
    person1.print(person1.mId, person1.mAge);

}

int main(int argc, char const *argv[])
{
    personTest();
    system("pause");
    return 0;
}


