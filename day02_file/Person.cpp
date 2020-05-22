
#include <iostream>

using namespace std;

class Person
{
public:
	Person(){}; // 空参构造函数可创建功能对象，不实现任何
	Person(int id, int age):age(age), id(id){};
	~Person(){};
	void show(){
		cout <<"id : "<< this->id << " age : " << this->age << endl;
	}
public:
	int age;
	int id;	
};