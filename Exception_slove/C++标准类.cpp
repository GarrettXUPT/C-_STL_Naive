#include <iostream>
#include <stdlib.h>
#include <stdexcept>
#include <string.h>

using namespace std;

/* 
	编写自己的异常类的时候，要继承c++自己的异常类基类Exception，重写what函数
*/

class Person 
{
public:
	Person();
	~Person();
	int getAge();
	void setAge(int age);
	void show();
private:
	int _mAge;
};

Person::Person(){

}

Person::~Person(){

}

int Person::getAge(){
	return this->_mAge;
}

void Person::setAge(int age){
	if (age < 0 || age >= 100)
	{
		throw out_of_range("age out of range");
	}
	this->_mAge = age;
}

void Person::show(){
	cout << "garrett's age is " << getAge() << endl; 
}

class MyOutOfRange
{
public:
	char *what(){
		return pError;
	};

	MyOutOfRange(char* error){
		pError = new char[strlen(error) + 1];
		strc py(pError, error); 
	}

	MyOutOfRange(){}

	~MyOutOfRange(){
		if (pError != NULL)
		{
			delete[] pError;
		}
	}
public:
	char* pError;
	
};



template <typename T>
int divdied(T a, T b){
	if (b == 0)
	{
		throw out_of_range("divdied number is zero");
	}
}

void test01(){
	Person person;
	try{
		person.setAge(10);		
	}catch(exception e){ // exception是所有异常类的父类，所在一直保持exception即可
		cout << e.what() << endl;	
	}
	person.show();
}

void funct2(){
	throw MyOutOfRange((char*)"this is a out of range exception");
}

void test02(){
	try{
		funct2();
	}catch(MyOutOfRange ex){
		cout << ex.what() << endl;
	}
}


int main(int argc, char const *argv[])
{
	// test01();
	test02();
	return 0;
}