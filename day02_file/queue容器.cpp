#include <iostream>
#include <queue>

using namespace std;

void printQueue(queue<int> q){
	while(q.size() > 0){
		cout << q.front() << " ";
		q.pop();  // 删除队头
	}
	cout << endl;
}

void test01(){
	queue<int> q1; // 创建队列
	queue<int> q2(q1); // 使用q1初始哈q2

	// 向对列中添加元素
	q1.push(10);
	q1.push(20);
	q1.push(30);

	cout << "the last elem is " << q1.back() << endl;
	printQueue(q1);

}

int main(int argc, char const *argv[])
{
	test01();
	return 0;
}