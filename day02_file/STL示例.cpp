
#include <iostream>
#include <vector>  // 动态数组，可变数组
#include <algorithm>  // 算法库
#include "Person.cpp"

using namespace std;

void printVector(int v){
	cout << v << endl;
}


void printObjVector(Person obj){
	obj.show();
}

// STL基本语法
void test01(){
	std::vector<int> vec;  // 定义了一个容器，并且指定了该容器存放的数据类型
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(4);
	// 创建迭代器
	std::vector<int>::iterator pBegin = vec.begin();
	std::vector<int>::iterator pEnd = vec.end();
	// 通过STL提供的for_each算法，对容器进行遍历
	// 容器中既可以存放基础的数据类型也可以存放自定义的数据类型
	for_each(pBegin, pEnd, printVector); 
}

// 容器存放自定义类型数据
void test02(){
	Person p1(10, 18), p2(11, 20), p3(12, 23);
	std::vector<Person> vec;
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);
	std::vector<Person>::iterator pBegin = vec.begin();
	std::vector<Person>::iterator pEnd = vec.end();
	for_each(pBegin, pEnd, printObjVector);
	std::vector<Person>::iterator it1 = vec.begin();
	for(std::vector<Person>::iterator it = vec.begin(); it != vec.end(); it++){
		cout << (*it).id << " " << (*it).age << endl;
	}

	while(it1 != vec.end()){
		printObjVector(*it1++);
	}
}

int main(int argc, char const *argv[])
{
	test02();
	return 0;
}