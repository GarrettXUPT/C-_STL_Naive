#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
#include"person.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    Person person("GARRETT", 12, 3);
    // person.show(); 
    // 使用运算符重载打印
    cout << person << endl;
    system("pause");
    return 0;
}
