
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct MyPrint
{
public:
	MyPrint(){};
	 void operator()(int val){
		cout << val << endl;
		num++;
	}
	int getNum(){
		return num;
	}
private:
	int num = 0;
};

void test01(){
	MyPrint print;
	print(10);

	// 函数对象可以像普通函数一样调用，函数对象可以像普通函数那样接收参数，函数对象可以保存函数调用的状态
}

int num = 0; // 在开发中尽量不使用全局变量，要给全局变量加锁
void MyPrint01(int val){
	cout << val << endl;
	num++;
}

void test02(){
	std::vector<int> v;
	v.push_back(10);
	v.push_back(11);
	v.push_back(12);
	
#if 0
	MyPrint print;
	print(10);
	print(20);
	// 打印调用次数,使用函数对象可以避免使用全局变量
	cout << print.getNum() << endl;
# endif
	MyPrint print;
	MyPrint print01 = for_each(v.begin(), v.end(), print);
	cout << "the num of used of print is " << print01.getNum() << endl;
}

int main(int argc, char const *argv[])
{
	test02();
	return 0;
}