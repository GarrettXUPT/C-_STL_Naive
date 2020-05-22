
// 异常机制, 异常基本的语法
#include<iostream>
#include<stdlib.h>
using namespace std;

int divide(int x, int y){
    if(y == 0){
        throw y;  // 抛出异常
    }
    return x / y; 
}

void test01(){
    int res = 0;
    try{   // 若存在异常则会捕获异常
        int res = divide(10, 0);
    }catch(int e){  // 异常时根据类型进行匹配
        cout << "divide numer is 0" << e << endl;
    }
    cout << "res = " << res << endl;
}

void CallDiv(int x, int y){
    divide(x, y);  // 若在调用出没有处理异常，程序就会向上找处理异常的，如果就是没有处理异常，程序会崩溃,会调用terminate函数
}

void test02(){
    try
    {
        CallDiv(10, 0);
    }
    catch(int e)
    {
        cout << "divied number is " << e << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    // test01();
    test02();
    system("pause");
    return 0;
}
