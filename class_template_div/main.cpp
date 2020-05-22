
#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
#include<string>
#include"person.cpp"
using namespace std;

int main(int argc, char const *argv[])
{
    person<string, int> per("Walker", 1, 18);
    per.show();
    system("pause");
    return 0;
}
