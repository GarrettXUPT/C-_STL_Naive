
#include <set>
#include <iostream>


using namespace std;

class Person
{
public:
	Person(int id, int age){
		this->_id = id;
		this->_age = age;
	};
	~Person(){};
public:
	int _id;
	int _age;
	
};


// 更改set默认排序顺序，仿函数
class MyCompare
{
public:
	bool operator()(int v1, int v2){
		return v1 > v2;  // 降序排序
	}
	
};

class MyCompare2
{
public:
	bool operator()(const Person& p1,const Person&p2){
		return p1._id > p2._id;  // 降序排序
	}
};

// 以自定义类型 使用自定义的规则进行排序
void printSet(set<Person, MyCompare2> st){
	set<Person, MyCompare2>::iterator it = st.begin();
	while(it != st.end()){
		cout << "id " << (*it)._id << " age " << (*it)._age << endl;
		*it++;
	}
}

void printSet(set<int> st){
	set<int>::iterator it = st.begin();
	while(it != st.end()){
		cout << *it++ << " ";
	}
	cout << endl;
}

void printSet(set<int, MyCompare> st){
	set<int, MyCompare>::iterator it = st.begin();
	while(it != st.end()){
		cout << *it++ << " ";
	}
	cout << endl;
}

// set容器初始化
void test01(){
	int arr[] = {5, 3 , 7, 2};  // 若初始化时有重复元素，那么会报错
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	set<int> st1(arr, arr + arrLen);
	printSet(st1);  // set会将元素进行自动排序

	// 使用拷贝初始化
	set<int> st2(st1);
	printSet(st2);  // 2 3 5 7

	// 赋值操作
	set<int> st3 = st1;
	printSet(st3);

	// 交换两个容器的元素
	set<int> st4;
	st4.insert(10);	
	st4.insert(11);	
	st4.insert(15);
	cout << "swap before" << endl;
	cout << "st1 ";
	printSet(st1);
	cout << "st4 ";
	printSet(st4);
	cout << "swap after" << endl;
	st4.swap(st1);
	cout << "st1 ";
	printSet(st1);
	cout << "st4 ";
	printSet(st4);

	// 容器大小操作
	cout << "the num of st1 is " << st1.size() << endl;
	if(!st1.empty()){
		cout << "this set is not empty" << endl;
	}

}

// 插入、删除操作
void test02(){
	int arr[] = {5, 3 , 7, 2};  // 若初始化时有重复元素，那么会报错
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	set<int> st1(arr, arr + arrLen);
	printSet(st1);  // set会将元素进行自动排序

	// 向容器中插入元素
	st1.insert(19);
	printSet(st1);

	// 删除迭代器所指的元素
	st1.erase(st1.begin());
	printSet(st1);

	// 删除区间中的所有元素，返回下一个元素的迭代器
	set<int>::iterator it = st1.begin();
	*it++;
	st1.erase(st1.begin(), it);
	// 删除容器中值为elem的元素
	st1.erase(7);
	printSet(st1);

	// 清空容器中所有的元素
	st1.clear();
	printSet(st1);
}

// 查找操作
void test03(){
	int arr[] = {5, 3 , 7, 2};  // 若初始化时有重复元素，那么会报错
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	set<int> st1(arr, arr + arrLen);
	printSet(st1);  // set会将元素进行自动排序
	// 对于set来说，所谓的key就是一个常数值
	// find(key) 查找key是否存在，若存在，返回该键元素的迭代器，若不存在，则返回最后一个元素的下一个元素的迭代器
	set<int> ::iterator it = st1.find(70);
	if(it == st1.end()){
		cout << "not be found" << endl;
	}else{
		cout << *it << endl;
	}

	// lower_bound(keyElem)  返回第一个key >= keyElem元素的迭代器
	set<int>::iterator it1 = st1.lower_bound(3);  // 找 >= 3第一个元素的迭代器
	cout << *it1 << endl;  	
	

	// upper_bound(keyElem) 返回第一个key > keyElem元素的迭代器
	set<int> :: iterator it2 = st1.upper_bound(3);  // 找第一个 > 7的元素对应的迭代器
	cout << *it2 << endl;

	// equal_range(keyElem)  返回容器中key与keyElem相等的两个上下限的迭代器,即upper和lower对应的值
	pair<set<int>::iterator, set<int>::iterator> myret = st1.equal_range(3);
	if(myret.first == st1.end()){
		cout << "not be found" << endl;
	}else{
		cout << "have be found" << endl;
		cout << "myret: " << *(myret.first) << endl;
		cout << "myret: " << *(myret.second) << endl;		
	}
}


void test04(){	
	set<int, MyCompare> st1;
	st1.insert(10);
	st1.insert(11);
	st1.insert(12);
	printSet(st1);
}


// 自定义类型set
void test05(){
	Person p1(10, 20), p2(2, 30), p3(13, 40);
	set<Person, MyCompare2> sp;
	sp.insert(p1);
	sp.insert(p2);
	sp.insert(p3);
	printSet(sp);

	// 查找
	set<Person, MyCompare2>::iterator ret = sp.find(p3);
	if(ret == sp.end()){
		cout << "not be found" <<endl;
	}else{
		cout << "id " << (*ret)._id	<< " age " << (*ret)._age << endl;
	}
}

int main(int argc, char const *argv[])
{
	test03();
	return 0;
}
