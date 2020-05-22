
#define _CRT_SECRE_NO_WARNINGS

#include <iostream>

using namespace std;

#if 0
cin:
	char ch = cin.get() 通过缓冲区读取单个字符
cout是个全局流对象，自动与显示器关联
cerr：标准错误，输出数据到显示器，没有缓冲区
clog：标准日志，输出数据到显示器，有缓冲区
endl：刷新缓冲区
#endif

// 标准输入流
void test01(){  
	char ch1;
	// 由缓冲区中拿到数据
	while((ch1 = cin.get()) != EOF){
		cout << ch1;
	}

	char ch2;
	cin.get(ch2);  // 读取一个字符

	// 读取固定长度的字符串
	char buf[256] = { 0 };
	int len = sizeof(buf) / sizeof(buf[0]);
	// cin.get(buf, len);
	// cout << buf << endl;

	// 读取一行数据,但是不会读取换行符
	cin.getline(buf, len);
	cout << buf << endl;
}

// cin.ignore() 忽略当前的字符
void test02(){
	char ch;
	cin.get(ch);  // 从缓冲区中读取数据,输入asdf，当前获取的是a
	cout << ch << endl;
	cin.ignore();  // 忽略当前字符，忽略的是s  cin.ignore(10)表示的是忽略10个字符
	cin.get(ch);    // 此处读取的是d
	cout << ch << endl;
}

// cin.peek仅仅是查看缓冲区中输入的内容，而不是取走
void test03(){
	cout << "input number or string" << endl;
	char ch;
	ch = cin.peek();   // 查看缓冲区中输入的内容，会返回第一个字符
	if(ch >= '0' && ch <= '9'){
		int number;
		cin >> number;  // 将缓冲区中的字符读取到number中
		cout << "this is a number: " << number <<endl;
	}else{
		char buf[256] = { 0 };
		cin >> buf;
		cout << "this is a string: " << buf << endl;
	}
}

// cin.putback 可以和cin.get 一块使用,cin.get()将字符从缓冲区中拿出，cin.putback()将字符放回缓冲区
void test04(){
	cout << "input string or number please" <<endl;
	char ch;
	cin.get(ch);  // 从缓冲区中获取
	if(ch >= '0' && ch <= '9'){
		cin.putback(ch); // 将字符放回缓冲区
		int number;
		cin >> number;
		cout << "this is a number: " << number <<endl;
	}else{
		cin.putback(ch); // 将字符放回缓冲区
		char buf[256] = { 0 };
		cin >> buf;
		cout << "this is a string: " << buf << endl;
	}
}
 
int main(int argc, char const *argv[])
{
	test04();
	return 0;
}