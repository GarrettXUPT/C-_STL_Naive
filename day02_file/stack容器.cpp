
#include <stack>
#include <iostream>

using namespace std;

void printStack(stack<int> s){
	while(!s.empty()){
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

// 初始化及操作
void test01(){
	stack<int> s1;
	stack<int> s2(s1);  // 使用s1初始化s2

	// 操作
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(100);

	cout << "the top of the stack is " << s1.top() << endl;
	printStack(s1);

	s1.pop();
	cout << "has be delete elem after " << endl;
	printStack(s1);
	
	// 容器的元素个数
	cout << "the size of stack is " << s1.size() << endl;
}


int main(int argc, char const *argv[])
{
	test01();
	return 0;
}