// 类模板
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
    T mId;
    T mAge;
    Person(T id, T age){
        this->mAge = age;
        this->mId = id;
    }
    ~Person(){

    }
    void show(){
        cout << "ID = " << mId << " Age = " << mAge << endl;
    }
};

void PersonTest(){
    // 函数末班在调用的时候，可以自动类型推导
    // 类模板必须显式指定类型
    Person<int> p(12, 14);
    p.show();
}


int main(int argc, char const *argv[])
{
    PersonTest();
    system("pause");
    return 0;
}

