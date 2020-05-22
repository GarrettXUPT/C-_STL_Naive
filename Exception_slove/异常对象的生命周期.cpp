#include <iostream>
#include <stdlib.h>

// 异常对象的生命周期 
using namespace  std;

class MyException
{
public:
	MyException();
	MyException(const MyException& ex);
	~MyException();
	void show();
};

MyException::MyException(){
	cout << "this is a constructor" << endl;
}

MyException::MyException(const MyException& ex){
	cout <<"this is a copy constructor" << endl;
}

MyException::~MyException(){
	cout << "this is a destory" << endl;
}

void MyException::show(){
	cout << "this is a exception" <<endl;
}

void func(){
	// 一般抛出
	// throw MyException();
	
	// 若抛出的是指针型异常 
	throw new MyException();
}

// 捕获异常 普通类型的元素，引用，指针
// 普通类型元素：异常对象的catch处理过之后就析构
// 引用：不用调用拷贝的话，异常对象catch处理过后就析构
// 指针：要注意抛出对象被提前析构

/*
	抛出普通类型元素
*/
#if 0
void MyExceptionTest(){
	try{
		func();
	}catch(MyException me){
		me.show();
	}
}
#endif

/*
	指针元素抛出
*/
void MyExceptionTest(){
	try{
		func();
	}catch(MyException*  me){
		cout << "this is a exception" << endl;
		delete  me;
	}
}
 
int main(int argc, char const *argv[])
{
	MyExceptionTest();
	return 0;
}