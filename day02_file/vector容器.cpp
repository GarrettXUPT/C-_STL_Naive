
#include <iostream>
#include <vector>

using namespace std;

void printVector(vector<int> vec){
	std::vector<int>::iterator it = vec.begin();
	while(it != vec.end()){
		cout << *it++ << " ";
	}
	cout << endl;
}

// 初始化
void test01(){
	int arr[] = {1, 2, 4, 6, 7};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> v1(arr, arr + arrLen);  // 创建新的数组
    printVector(v1);
    // vector(v.begin(), v.end()) 将该区间内元素拷贝到本身，即使用一个vector初始化另一个vector
    std::vector<int> v2(v1.begin(), v1.end());
    printVector(v2);
    // vector(n, elem) 使用n个elem进行初始化
    std::vector<int> v3(10, 2);
    printVector(v3);
    // vector(const vector& vec) 拷贝构造函数
    std::vector<int> v4(v2);
    printVector(v4);
}

// 赋值操作
void test02(){
	int arr[] = {1, 2, 4, 6, 7};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> v1(arr, arr + arrLen);  // 创建新的数组
    // 使用迭代器赋值
    std::vector<int> v2(v1.begin(), v1.end() - 2);
    printVector(v2);  // 124
    // 重载=
    std::vector<int> v3 = v1;
    printVector(v3);  // 12467
    // swap交换两个vector中的元素
    int ar[] = {2, 5, 6, 8, 0};
    int arLen = sizeof(ar) / sizeof(ar[0]);
    std::vector<int> v4(ar, ar + arLen);
    v4.swap(v1);
    printVector(v1);
    printVector(v4);
}

// vector的大小操作
void test03(){
	int arr[] = {1, 2, 4, 6, 7};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> v1(arr, arr + arrLen);  // 创建新的数组
    // 返回容器中元素的个数
    int num = v1.size();
    cout << "the size of vector is " << num << endl;
    if (!v1.empty())
    {
		cout << "the vector is not empty" << endl;
    }
    // 调整容器的大小
    cout << "this is resize of vector before" << endl;
    printVector(v1);  // 1 2 4 6 7
    v1.resize(3);
    cout << "this is resize of vector after" << endl;	    
    printVector(v1);  // 1 2 4
    // 返回vector的容量
    cout << v1.capacity() << endl; // 5
}

// 存取数据
void test04(){
	int arr[] = {1, 2, 4, 6, 7};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
    std::vector<int> v1(arr, arr + arrLen);  // 创建新的数组
    int v1Len = v1.size();
// [] 与 at() 的区别在于[] 溢出会报错， at()溢出会抛出异常
    for(int i = 0; i < v1Len; i++){
    	cout << v1.at(i) << " ";
    }
    cout << endl;

    for(int i = 0; i < v1Len; i++){
    	cout << v1[i] << " ";
    }
    cout << endl;
	// front返回的是第一个元素,back返回的是最后一个元素
    cout << "the first element is " << v1.front() << endl; // the first element is 1
    cout << "the last element is " << v1.back() << endl; // the last element is 7
}

// 插入和删除
void test05(){
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(10);
	vec.push_back(100);
	printVector(vec);
	// 头插法
	vec.insert(vec.begin(), 1000);
	printVector(vec);
	// 尾插法
	vec.insert(vec.end(), 10000);
	printVector(vec);
	// vector是支持随机访问的,所以可以这样添加元素 
	vec.insert(vec.begin() + 2, 10001);
	printVector(vec);
	// 删除最后一个元素
	vec.pop_back();
	printVector(vec);
	// 删除一个区间
	vec.erase(vec.begin(), vec.begin() + 3);
	printVector(vec);
	// 删除迭代器指定元素
	vec.erase(vec.end());
	printVector(vec);
	// 删除全部元素
	vec.clear();
	printVector(vec);
}

// 巧用swap()缩减空间
void test06(){
	// 在向容器中添加元素，容器的大小会增大，若删除元素，容器大小不会减小
	std::vector<int> v;
	for(int i = 0; i < 1000; i++){
		v.push_back(i);
	}
	cout << "the size of vector: " << v.size() << endl;  // 1000
	cout << "the capacity is : " << v.capacity() << endl;  // 1024 
	v.resize(10);
	cout << "the size of vector: " << v.size() << endl;  // 10
	cout << "the capacity is : " << v.capacity() << endl;  // 1024 
	// 使用swap缩减空间
	std::vector<int> (v).swap(v);
	cout << "the size of vector: " << v.size() << endl;  // 10
	cout << "the capacity is : " << v.capacity() << endl;  // 10
}

void test07(){
	// reserve预留空间,若在开始就知道要存储的元素个数，可以使用reserve预留空间
	int num = 0;
	int* address = NULL;
	std::vector<int> v;
	v.reserve(1000);
	for (int i = 0; i < 1000; ++i)
	{
		v.push_back(i);
		if (address != &(v[0]))
		{
			address = &(v[0]);
			num++;
		}
	}
	cout << "num = " << num << endl; // 11	
}


int main(int argc, char const *argv[])
{
	test07();
	return 0;
}