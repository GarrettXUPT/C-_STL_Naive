
#include <iostream>
#include <deque>

using namespace std;

void printDeque(deque<int> deq){
	deque<int>::iterator it = deq.begin();
	while(it != deq.end()){
		cout << *it++ << " ";
	}
	cout << endl;
}

// 初始化 
void test01(){
	int arr[] = {1, 3, 4, 6, 2, 9};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	deque<int> deqint1;  // 默认构造
	deque<int> deqint2(arr, arr + arrLen);
	printDeque(deqint2);

	deque<int> deqint3(10, 2);  // deque(n, elem);将n个elem拷贝给deque3本身
	printDeque(deqint3);

	deque<int> deqint4(deqint2);  // 拷贝构造函数
	printDeque(deqint4);
}

// 赋值 大小操作
void test02(){
	

	deque<int> deqint1;
	deqint1.assign(10, 3);  // 将10个3赋值给双端数组
	printDeque(deqint1);

	deque<int> deqint2;
	deqint2.assign(deqint1.begin(), deqint1.end() - 4);
	printDeque(deqint2);


	deque<int> deqint3 = deqint1;  // 重载=操作符
	printDeque(deqint3);

	cout << "swap before " << endl;
	cout << "deqint1: ";
	printDeque(deqint1);
	cout << "deqint2: ";
	printDeque(deqint2);
	deqint1.swap(deqint2);  // 将deque1和deque2数组交换
	cout << "swap after " << endl;
	cout << "deqint1: ";
	printDeque(deqint1);
	cout << "deqint2: ";
	printDeque(deqint2);

	int arr[] = {1, 3, 4, 6, 2, 9};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	deque<int> deqint4(arr, arr + arrLen);
	cout << "the size of deqint4 is " << deqint4.size() << endl;
	
	if (!deqint4.empty()){
		cout << "the deque is not empty" << endl;
	}

	deqint4.resize(10);  // 将指定容器长度指定为10
	cout << "the size of deqint4 is " << deqint4.size() << endl;

	deqint4.resize(20, 4); // 重新指定容器的长度，若容器变长，则以4填充新位置，若变短，则舍弃元素
	cout << "the size of deqint4 is " << deqint4.size() << endl;

	printDeque(deqint4);
}

// 插入和删除
void test03(){
	int arr[] = {1, 3, 4, 6, 2, 9};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	deque<int> deqint1(arr, arr + arrLen);

	// 向容器尾部插入元素
	deqint1.push_back(10);
	printDeque(deqint1);
	// 向容器头部插入元素
	deqint1.push_front(13);
	printDeque(deqint1);
	// 删除容器最后一个元素
	int val1 = deqint1.back();
	deqint1.pop_back();
	cout << "had be delet element is " << val1 << endl;
	printDeque(deqint1);
	// 删除容器读一个元素
	int val2 = deqint1.front();
	deqint1.pop_front();
	cout << "had be delet element is " << val2 << endl;
	printDeque(deqint1);

}

int main(int argc, char const *argv[])
{
	test03();
	return 0;
}