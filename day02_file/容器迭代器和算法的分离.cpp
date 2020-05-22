
#include <iostream>

using namespace std;

// 统计某个元素的个数
int myCount(int* start, int* end, int val){
	int count = 0;
	while(start != end){
		if(*start == val){
			count++;
		}
		start++;
	}
	return count;
}


int main(int argc, char const *argv[])
{
	// 数组
	int arr[] = {0, 5, 6, 9, 2, 4, 2, 9, 2};
	int* pBegin = arr;  // 迭代器的开始位置
	int* pEnd = &arr[sizeof(arr) / sizeof(int)];  // 获取的是最后一个元素，下一个元素的位置
	int res = myCount(pBegin, pEnd, 2);
	cout << "count = " << res << endl;

	return 0;
}
