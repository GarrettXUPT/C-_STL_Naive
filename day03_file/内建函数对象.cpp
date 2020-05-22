
#include <iostream>
#include <functional>

using namespace std;

void test01(){
	// 加法仿函数
	plus<int> myplus;
	cout << myplus(10, 20) << endl;
	// 减法仿函数
	minus<int> myminute;
	cout << myminute(20, 10) << endl;
	// 乘法仿函数
	multiplies<int> mymul;
	cout << mymul(2, 3) << endl;
	// 除法仿函数
	divides<int> myDiv;
	cout << myDiv(4, 2) << endl;
	// 取模仿函数
	modulus<int> myMod;
	cout << myMod(5, 3) << endl;
	// 取反仿函数
	negate<int> myNeg;
	cout << myNeg(10) << endl;
	// 含有逻辑仿函数和关系仿函数，可上网查找
}

int main(int argc, char const *argv[])
{
	test01();
	return 0;
}