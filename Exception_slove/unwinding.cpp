#include<iostream>
#include<stdlib.h>
// 栈解璇 
using namespace std;

class Person{

public:
    Person(){cout << "the obj have be construct" << endl;}
    ~Person(){cout << "the obj have be destory" << endl;}
};

int divide(int x, int y){
    Person p1, p2;  // 创建两个类对象，但是当异常抛出时候，这两个类对象会自动析构
    if(y == 0){
        throw y;
    }
    return x / y; 
}

void test01(){
    try
    {
        divide(10, 0);
    }
    catch(int e)
    {
        cout << "the divied number is " << e << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    test01();
    system("pause");
    return 0;
}


