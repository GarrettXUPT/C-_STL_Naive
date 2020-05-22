
#include <iostream>
#include <string>

using namespace std;

// pair.first 第一个元素 pair.second 第二个元素
template <class T1, class T2>
void printPair(pair<T1, T2> pa){
	cout << pa.first << " " << pa.second << endl;
}

// 创建对组
void test01(){
	pair<string, int> pair1("name", 20);
	printPair(pair1);

	pair<string, int> pair2 = make_pair("Garrett", 22);
	printPair(pair2);
	// 重载运算符
	pair<string, int> pair3 = pair2;
	printPair(pair3);
}


int main(int argc, char const *argv[])
{
	test01();
	return 0;
}