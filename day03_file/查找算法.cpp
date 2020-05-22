
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person
{
public:
	Person(int id, int age){
		mAge = age;
		mId = id;
	};
	~Person(){};
	bool operator==(const Person& p) const {
		return p.mId == this->mId && p.mAge == this->mAge;
	}

	bool operator!=(const Person& p) const {
		return p.mId != this->mId && p.mAge != this->mAge;
	}
public:
	int mAge;
	int mId;
};

// find(iterator beg, iterator end, val)
void test01(){
	std::vector<int> v;
	for(int i = 0; i < 10; i++){
		v.push_back(i);
	}
	std::vector<int> :: iterator ret = find(v.begin(), v.end(), 5);
	if (ret != v.end())
	{
		cout << "have be found " << endl;
		cout << *ret << endl;
	}else{
		cout << "have be found " << endl;
	}
	cout << *ret << endl;

	Person p1(1, 20), p2(2, 30), p3(3, 25);
	std::vector<Person> vec;
	vec.push_back(p1);
	vec.push_back(p2);
	vec.push_back(p3);
	std::vector<Person>::iterator ret1 = find(vec.begin(), vec.end(), p1);
	if (ret1 == vec.end())  // 需要在自定义类型中重载该运算符
	{
		cout << "have be found " << endl;
	}else{
		cout << "have be found " << endl;
	}
}

// binary_search 二分查找法,只返回有没有，而不是告知位置
void test02(){
	std::vector<int> v;
	for(int i = 0; i < 10; i++){
		v.push_back(i);
	}
	bool ret = binary_search(v.begin(), v.end(), 5);
	if(ret){
		cout << "have be found " << endl;
	}else{
		cout << "have not be found" << endl;
	}
}

// adjacent_find()查找相邻重复的元素
void test03(){
	std::vector<int> v;
	for(int i = 0; i < 10; i++){
		v.push_back(i);
	}
	v.push_back(9);
	std::vector<int> :: iterator ret = adjacent_find(v.begin(), v.end());
	if(ret != v.end()){
		cout << "have be found " << endl;
	}else{
		cout << "have not be found" << endl;	
	}
}

bool Mysearch(int val){
	return val > 5;
}

// find_if条件查找
void test04(){
	std::vector<int> v;
	for(int i = 0; i < 10; i++){
		v.push_back(i);
	}
	// 会根据条件，返回第一个满足条件的元素的迭代器
	std::vector<int> :: iterator it = find_if(v.begin(), v.end(), Mysearch);
	if(it != v.end()){
		cout << "have be found " << "val = " << *it << endl;
	}else{
		cout << "have not be found" << endl;
	}
}

// count和count_if  // 统计次数
void test05(){
	std::vector<int> v;
	for(int i = 0; i < 10; i++){
		v.push_back(i);
	}
	int num1 = count(v.begin(), v.end(), 6);
	int num2 = count_if(v.begin(), v.end(), Mysearch);
	cout << "the number of element equal six is " << num1 << endl;
	cout << "the number of element greater six is " << num2 << endl; 

}


int main(int argc, char const *argv[])
{
	test05();
	return 0;
}