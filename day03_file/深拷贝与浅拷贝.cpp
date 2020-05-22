
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

/*
	STL容器提供的是值寓意的，而不是引用寓意的，也就是我们给容器插入元素的时候，容器内部实施了拷贝工作
	将我们要插入的元素再另行拷贝一份放入到容器中，而不是将原数据元素直接放进容器，此时也就要求我们提供的
	元素必须是能够被拷贝的
*/


class Person
{
public:
	Person(char* name, int age){
		this->pName = new char[strlen(name) + 1];
		strcpy(this->pName, name);
		this->mAge = age;
	}

	Person(const Person& p){
		this->pName = new char[strlen(p.name) + 1];
		strcpy(this->pName, p.pName);
		this->mAge = age;
	}

	Person& operator=(const Person& p){
		if(this->pName != NULL){
			delete[] this->pName;
		}
		this->pName = new char[strlen(p.name) + 1];
		strcpy(this->pName, p.pName);
		this->mAge = age;	
		return *this;
	}

	~Person(){
		if（this->pName != NULL){
			delete[] this->pName;
		}
	};
public:
	char* pName;  // 若出现指针，那么就容易出现浅拷贝的问题
 	int mAge;
};

void test01(){
	Person p1((char*)"Garrett", 22);
	std::vector<Person> vPerson;
	vPerson.push_back(p1);

}