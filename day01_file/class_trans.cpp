#include<iostream>
#include<stdlib.h>
// 类型转换
// C++在类型转换时，会对类型进行检查，C语言中强制类型转换是没有检查的
using namespace std;

class Building{};

class Animal{};
class Cat : public Animal{};

// static_cast 转换示例
void test01(){
     // 一般的转换,基本类型转换  
    int a = 97;
    char b = static_cast<char>(a);  // 将a转换为char类型 
    cout << " a = " << a << " translation to c = " << b <<endl;

    // 针对基础数据类型指针的转换
    // int* p = NULL;
    // char* sp = static_cast<char*>(p);  // 此处不可转换

    // 针对对象指针的指针转换
    // Building* build = NULL;
    // Animal animal = static_cast<Animal*>(build); // 此处也是不可转换的

    // 针对具有继承关系的对象指针
    // 父类指针转换为子类指针，在此处是可以转换的
    Animal* ani = NULL;
    Cat* cat = static_cast<Cat*>(ani);
    // 子类指针转化为父类指针,此处是可以进行转换的
    Cat* cat1 = NULL;
    Animal* ani1 = static_cast<Animal*>(cat1);

    // 具有继承关系引用之间相互转换,是可以进行转换的
    Animal aniobj;
    Animal& aniref = aniobj;
    Cat& catobj = static_cast<Cat&>(aniobj);
}

// dynamic_cast示例,动态类型转换，转换具有继承关系的指针或者引用，在转换前会进行对象类型的检查
void test02(){
    // 基本数据类型时不可转换的
    Animal* ani = NULL;
    Cat* cat = static_cast<Cat*>(ani);
    // 子类指针转化为父类指针,此处是可以进行转换的
    Cat* cat1 = NULL;
    Animal* ani1 = static_cast<Animal*>(cat1);

    // 具有继承关系引用之间相互转换,是可以进行转换的，将父类指针或者引用转换为子类的，是可以转换的
    // 但是，子类转化为父类是非法的，类型由大到小，转化是安全的，但是由小转大，就是不安全的，这是检查完成的 
    Animal aniobj;
    Animal& aniref = aniobj;
    Cat& catobj = static_cast<Cat&>(aniobj); 
}

 // const_cast 主要针对const的转换,取消const作用，针对指针和引用，或者对象指针
 void test03(){
     // 引用类型转换
    int a = 10;
    const int& b = a;  // a的别名为b
    int& c = const_cast<int&>(b);  // 将b的const作用取消
    int d = c + 1;
    cout << d << "," << a << endl;

    // 指针类型转换
    // 取消const
    const int*p = NULL;  // 指向内存地址不可修改，但是内部存储的值是可以修改的
    int* p1 = const_cast<int*>(p);
    int t = 3;
    p1 = &t;  // p1被指向了t所在的地址
    cout << *p1 << endl;
    // 增加const
    int* q = NULL;
    const int* q1 = const_cast<const int*>(q);
 }  
// reinterpret_cast 进行没有任何关联之间的转换，比如一个字符转换为一个整数
// 任何类型的值都可以转化为其他类型的值，也就是强制类型转换
typedef void(*Func1)(int, int);
typedef int(*Func2)(int, char*);

void test04(){
    // 无关的指针类型想换转换
    Building* build = NULL;
    Animal* ani = reinterpret_cast<Animal*>(build);
    // 两个不同类型函数指针之间的相互转换
    Func1 func1;
    Func2 func2 = reinterpret_cast<Func2>(func1);
 }



int main(int argc, char const *argv[])
{

    test01();

    test02();

    test03();
    // dynamic_cast 通常在基类和派生类之间转化时使用

    // const_cast 主要针对const的转换

    // reinterpret_cast 进行没有任何关联之间的转换，比如一个字符转换为一个整数

    system("pause");
    return 0;
}
