
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 使用打印函数
void printVector(std::vector<int> v){
	std::vector<int> :: iterator it = v.begin();
	while(it != v.end()){
		cout << *it++ << " ";
	}
	cout << endl;
}

// 适配器
struct MyPrint : public binary_function<int, int, void>{
	void operator()(int v, int val) const {
		cout << v + val << " ";
	}
};

// 绑定适配器bind1st bind2nd
void test01(){
	std::vector<int> v;
	for(int i = 0; i < 10; i++){
		v.push_back(i);
	}
	// printVector(v);
	int addNum = 200;
	// 绑定适配器,将二元函数对象，绑定为一元的函数对象
	for_each(v.begin(), v.end(), bind2nd(MyPrint(), addNum));
	// bind1st, 将addNum绑定为函数对象的第一个参数
	// bind2nd，将addNum绑定为函数对象的第二个参数
}

struct MyCompare : public binary_function<int, int, bool>
{
	bool operator()(int val1, int val2) const{
		return val1 > val2;  // 由大到小排序
	}
};

struct Greater5 : public unary_function<int, bool> {
	bool operator()(int val) const {
		return val > 5;
	}
};

// 仿函数适配器 not1, not2 取反适配器
void test02(){
	std::vector<int> v;
	for(int i = 0; i < 10; i++){
		v.push_back(i);
	}
	// 本来是由大到小，现在取反以后就是从小到大了
	sort(v.begin(), v.end(), not2(MyCompare()));
	printVector(v);

	// not2 not1
	// 二元谓词取反使用not2，一元谓词取反则使用not1

	// 找到容器中第一个大于5元素的索引
	std::vector<int> :: iterator it1 = find_if(v.begin(), v.end(), Greater5());
	cout << *it1 << endl;
	// 取反以后找出第一个小于5元素的索引
	std::vector<int> :: iterator it2 = find_if(v.begin(), v.end(), not1(Greater5()));
	cout << *it2 << endl;
}

void MyPrint01(int val1, int val2){
	cout << val1 << " " << val2 << " ";
}

// 仿函数适配器 ptr_fun
void test03(){
	std::vector<int> v;
	for(int i = 0; i < 10; i++){
		v.push_back(i);
	}
	// 需要将普通函数转成函数对象
	for_each(v.begin(), v.end(), bind2nd(ptr_fun(MyPrint01), 10));
}

class Person
{
public:
	Person(int id, int age){
		this->_id = id;
		this->_age = age;
	};
	~Person(){};
	void show(){
		cout << "age = " << _age << " id = " << _id << endl;
	}
public:
	int _age;
	int _id;
};

// 成员函数适配器mem_fun mem_fun_ref
void test04(){
	// 若容器中存放的是对象或者是对象指针，我们希望在打印时，调用类自己提供的打印函数
	Person p1(1, 12), p2(2, 14), p3(3, 24);
	std::vector<Person> v;
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	// 格式：&类名::函数名
	for_each(v.begin(), v.end(), mem_fun_ref(&Person::show));

	std::vector<Person*> v1;
	v1.push_back(&p1);
	v1.push_back(&p2);
	v1.push_back(&p3);
	for_each(v1.begin(), v1.end(), mem_fun(&Person::show));

	// mem_fun mem_fun_ref的区别，若存放的是对象指针则使用mem_fun，若使用的是对象， 则使用mem_fun_ref

}

int main(int argc, char const *argv[])
{
	test04(); 
	return 0;
}