
#include <iostream>
#include <map>
#include <string>

using namespace std;

class MyKey
{
public:
	MyKey(int index, int id){
		this->mIndex = index;
		this->mID = id;
	};
	~MyKey(){};
public:
	int mIndex;
	int mID;
};


struct myCompare
{
	bool operator()(MyKey key1, MyKey key2){
		return key1.mIndex > key2.mIndex;
	}
};


void printMap(std::map<string, int> map1){
	std::map<string, int> :: iterator it = map1.begin();
	while(it != map1.end()){
		cout << (*it).first << " : " << (*it).second << endl;
		it++;
	}
}

void printMap(std::map<MyKey, int, myCompare> map1){
	std::map<MyKey, int, myCompare> :: iterator it = map1.begin();
	while(it != map1.end()){
		cout << (*it).first.mID << " : " << (*it).second << endl;
		it++;
	}
}

// 初始化
void test01(){
	std::map<string, int> map1;

	// 第一种方式插入数据
	pair<std::map<string, int>::iterator, bool> ret = map1.insert(pair<string, int>("Garrett", 10));
	if (ret.second)
	{
		cout << "insert seccussful" << endl;
	}else{
		cout << "insert fail" << endl;
	}	
	// 第二种方式插入数据
	pair<std::map<string, int>::iterator, bool> ret1 = map1.insert(make_pair("Walker", 11));
	if (ret1.second)
	{
		cout << "insert seccussful" << endl;
	}else{
		cout << "insert fail" << endl;
	}	
	// 第三种方式插入数据
	pair<std::map<string, int>::iterator, bool> ret2 = map1.insert(std::map<string, int>::value_type("Shiyu", 12));
	if (ret2.second)
	{
		cout << "insert seccussful" << endl;
	}else{
		cout << "insert fail" << endl;
	}	
	// 第四种方式插入数据
	map1["caicai"] = 13;
	// 给已有键值赋值，会更新该键值对应的实值
	map1["Garrett"] = 32;
	// printMap(map1);
}


void test02(){
	map<MyKey, int, myCompare> mymap;  // 自定义数据类型，要自定义排列规则
	mymap.insert(make_pair(MyKey(1, 2), 10));
	mymap.insert(make_pair(MyKey(4, 5), 11));
	printMap(mymap);
}

// equal_range
void test03(){
	map<int, int> mymap;
	mymap.insert(make_pair(1, 4));
	mymap.insert(make_pair(2, 5));
	mymap.insert(make_pair(3, 6));
	pair<std::map<int, int>::iterator, std::map<int, int>::iterator> ret = mymap.equal_range(2);
	if(ret.first != mymap.end()){
		cout << "lower have be found" << endl;
	}else{
		cout << "lower fail found" << endl;
	}

	if(ret.first != mymap.end()){
		cout << "upper have be found" << endl;
	}else{
		cout << "upper fail found" << endl;
	}

}

int main(int argc, char const *argv[])
{
	test03();
	return 0;
}
