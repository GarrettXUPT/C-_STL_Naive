#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdlib.h>

using namespace std;

// 定义一个异常接口，表示这个接口只能抛出int float char类型的异常
// void func() throw(int, float, char){
//     throw "abc";
// }

int main(int argc, char const *argv[])
{
    try
    {
        // func();
    }
    catch(char* e)
    {
        cout << "Exception is " << e << endl;
    }catch(int e){
        cout << "Exception is " << e << endl;
    }catch(...){
        cout << "Inknow exception" << endl;
    }
    system("pause");
    return 0;
}
