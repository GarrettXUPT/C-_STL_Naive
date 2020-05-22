
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// 使用打印函数
void printVector(std::vector<int> v){
	std::vector<int> :: iterator it = v.begin();
	while(it != v.end()){
		cout << *it++ << " ";
	}
	cout << endl;
}


struct MyPlus
{
	int operator()(int val){
		return val;
	}
};

// transform 将指定让其区间的元素搬运到另一个容器中
void test01(){
	std::vector<int> v1;
	std::vector<int> v2;

	for(int i = 0; i < 10; i++){
		v1.push_back(i);
	}

	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), MyPlus());
	printVector(v2);

}

int main(int argc, char const *argv[])
{
	test01();
	return 0;
}