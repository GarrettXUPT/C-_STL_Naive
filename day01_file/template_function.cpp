#define _CRT_SECURE_NO_WARNINGS
// 模板函数
#include<iostream>
#include<stdlib.h>

using namespace std;

// 数据交换
int MySwap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

// 模板技术可忽略类型
template<class T>  // template<typename T> 二者效果一致 此处可以template<class T1, classname T2>....
void MySwap(T &a, T &b){
    T tmp = a;
    a = b;
    b = tmp;
}

// 此处运用的是重载技术
void MySwap(int a, double b){
    return;
}

// 函数模板也是可以进行重载的，这里是由于参数个数不同
template<class T>
void MySwap(T &a, T &b, T &c){
    return;
}

void SwapTest(){
    // 1、自动类型推导
    int a = 3;
    int b = 4;
    MySwap(a, b);
    cout << "a = " << a << " b = " << b <<endl;
    // 2、显式指定的类型
    MySwap<int>(a, b);
}



int main(){
    SwapTest();
    system("pause");
    return 0;
}


