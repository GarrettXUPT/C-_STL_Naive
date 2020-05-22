#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
// throw 的异常是有类型的，可以使数字，字符串，类对象 

class MyException
{
public:
	MyException(char* str){
		error = new char[strlen(str) + 1];  // 申请内存空间
		strcpy(error, str);
	}

	MyException(const MyException& ex){
		this->error = new char[strlen(ex.error) + 1];
		strcpy(this->error, ex.error);
	};

	MyException& operator=(const MyException& ex){
		if(this->error != NULL){
			delete[] this->error;
			this->error = NULL;
		}
		this->error = new char[strlen(ex.error) + 1];
		strcpy(this->error, ex.error);
	}

	~MyException(){
		if(error != NULL){
			delete[] error;
		}
	}
	void what(){
		cout << error << endl;
	}
	
public:
	char* error;
};

void func1(){
	throw 1; // 抛出的是int类型
}

void func2(){
	throw "exception";
}

void func3(){
	throw MyException((char*)"this is a exception");
}


void test01(){
	// try{
	// 	func1();
	// }catch(int e){
	// 	cout << e << endl;
	// } 

	// try{
	// 	func2();
	// }catch(char* e){
	// 	cout << e << endl;
	// }

	try{
		func3();
	}catch(MyException e){
		e.what();
	}
	

}

int main(int argc, char const *argv[])
{
	test01();
	return 0;
}
