
#include<iostream>
#include<stdlib.h>
/*
    表示的数组：
        数组的的容量，当前数组的元素个数，保存数据的首地址
*/

using namespace std;
template<class T>
class MyArray
{
private:
    /* data */
public:
    MyArray(int capacity);
    MyArray();
    MyArray(const MyArray& arr); // 拷贝构造
    T& operator[](int index);  // 当前元素的引用
    MyArray<T> operator= (const MyArray<T>& arr);  // 重载等号
    void pushBack(T& data);  // 向数组中添加元素 
    void PushBack(T data);  // 向数组中添加元素 
    ~MyArray();
public:
    // 数组容量
    int mCapacity;
    // 当前元素个数
    int mSize;
    // 当前保存数据的首地址
    T* pAddr;
};

template<class T>
MyArray<T>::MyArray(int capacity){
    this->mCapacity = capacity;
    this->mSize = 0; // 初始化数组中没有元素
    this->pAddr = new T[this->mCapacity];  // 为该数组申请内存
}

template<class T>
MyArray<T>::MyArray(){

}

template<class T>
T& MyArray<T>::operator[](int index){
    return this->pAddr[index];
}

template<class T>
void MyArray<T>::pushBack(T& data){
    // 判断容器中是否有位置
    if(this->mSize >= this->mCapacity){
        return;
    }
    this->pAddr[this->mSize] = data;
    this->mSize++;
}


template<class T>
void MyArray<T>::PushBack(T data){
    // 判断容器中是否有位置
    if(this->mSize >= this->mCapacity){
        return;
    }
    // 调用拷贝构造操作符，元素必须是可以进行拷贝的
    // 容器都是值寓意，而非引用寓意 即都是将是元素进行拷贝，而不是传入地址
    // 若容器的元素有指针，注意深浅拷贝的区别
    this->pAddr[this->mSize] = data;
    this->mSize++;
}


template<class T>
MyArray<T>::MyArray(const MyArray& arr){
    this->mSize = arr.mSize;
    this->mCapacity = arr.mCapacity; 
    // 内存空间申请
    this->pAddr = new T[this->mCapacity];
    // 执行数据拷贝
    for(int i = 0; i < this->mSize; i++){
        this->pAddr[i] = arr.pAddr[i];
    }
}

template<class T>
 MyArray<T> MyArray<T>::operator= (const MyArray<T>& arr){
    if(this->pAddr != NULL){
        delete[] this->pAddr;  
    }
    this->mSize = arr.mSize;
    this->mCapacity = arr.mCapacity;
    // 内存空间申请
    this->pAddr = new T[this->mCapacity];
    // 执行数据拷贝
    for(int i = 0; i < this->mSize; i++){
        this->pAddr[i] = arr.pAddr[i];
    } 
    return *this;
 }

// 释放资源
template<class T>
MyArray<T>::~MyArray(){
    if(this->pAddr != NULL){
        delete[] this->pAddr;
    }
}

class Test{};

void MyArrayTest(){
    MyArray<int> array(20);  // 创建容量为20的数组
    int a = 10, b = 20, c = 30;
    array.pushBack(a);
    array.pushBack(b);
    array.pushBack(c);
    // 因为pushback方法中传值使用的是引用，所以不能使用array.pushback(10)
    // 但是在方法中存在解引用，所以
    array.PushBack(100);  // 这是合法的
    for(int i = 0; i < array.mSize; i++){
        cout << array[i] << ",";
    }
    cout << endl;

    MyArray<int> array2;
    array2 = array;
    for(int i = 0; i < array2.mSize; i++){
        cout << array2[i] << ","; 
    }
    MyArray<Test> test(20); // 创建容量为20的Test类型保存数组
}


int main(int argc, char const *argv[])
{
    MyArrayTest();
    system("pause");
    return 0;
}
