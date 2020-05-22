
#include <list>
#include <iostream>

using namespace std;


void printList(list<int> lst){
	list<int> :: iterator it = lst.begin();
	while(it != lst.end()){
		cout << *it++ << " ";
	}
	cout << endl;
}


// 初始化
void test01(){
	list<int> lst1(10, 2);
	list<int> lst2(lst1.begin(), lst1.end());
	printList(lst2);
	list<int> lst3(lst2);
	printList (lst3);
}


// 插入和删除操作
void test02(){
	int arr[] = {1, 3, 5, 8};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	list<int> lst(arr, arr + arrLen);
	printList(lst);

	// 在容器尾部加入一个元素
	lst.push_back(7);
	printList(lst);

	// 删除容器中最后一个元素
	lst.pop_back();
	printList(lst);

	// 在容器开头插入一个元素
	lst.push_front(2);
	printList(lst);

	// 删除容器中的第一个元素
	lst.pop_front();
	printList(lst);

	// 在指定位置插入元素，返回新元素位置，第一个参数是迭代器
	list<int>::iterator it = lst.insert(lst.begin(), 10);
	cout << "the pos of new value is " << *it << endl;
	printList(lst);

	// 向指定位置插入多个元素
	lst.insert(lst.begin(), 8, 9);
	printList(lst);

	// 删除指定区间中的元素，返回下一个数据的位置
	list<int>::iterator it2 = lst.erase(lst.begin(), (lst.begin()++));
	cout << "the pos of next value is " << *it2 << endl;
	printList(lst);

	// 移除第一次出现指定值的位置的元素
	lst.remove(1);
	printList(lst);

	// 移除指定位置的元素,返回下一个元素的位置
	lst.erase(lst.begin());
	printList(lst);

	// 清空列表
	lst.clear();
	printList(lst);

}


// 大小操作
void test03(){
	int arr[] = {1, 3, 5, 8};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	list<int> lst(arr, arr + arrLen);
	printList(lst);  // 1 3 5 8 

	// 返回容器中元素的个数
	int num = lst.size();
	cout << "the num of lst ele is " << num << endl;

	// 重新指定容器长度，若长度变长则使用默认值填充，若变短，则删除多余元素
	lst.resize(10);
	printList(lst);  // 1 3 5 8 0 0 0 0 0 0

	// 判断容器是否为空
	if(!lst.empty()){
		cout << "the list is not empty" << endl;
	}
}

// 赋值操作
void test04(){
	list<int> lst;
	lst.assign(10, 8);
	printList(lst);

	// 运算符重载
	list<int> lst1;
	lst1 = lst;
	cout << "this is a copy list" << endl;
	printList(lst1);

	// 将n个ele拷贝给本身
	lst1.assign(10, 2);
	printList(lst1);

	// 链表之间的元素互换
	cout << "swap before" << endl;
	cout << "lst ";
	printList(lst);
	cout << "lst1";
	printList(lst1);
	lst1.swap(lst);
	cout << "swap after" << endl;
	cout << "lst ";
	printList(lst);
	cout << "lst1";
	printList(lst1);
}

// list 数据的存取及反排列
void test05(){
	int arr[] = {1, 3, 5, 8};
	int arrLen = sizeof(arr) / sizeof(arr[0]);
	list<int> lst(arr, arr + arrLen);
	printList(lst);  // 1 3 5 8 

	// 返回链表第一个元素
	int first = lst.front();
	cout << "the first element is " << first << endl;

	// 返回链表最后一个元素
	int last = lst.back();
	cout << "the last element is " << last << endl;

	// 反转链表
	cout << "the list reverse before" << endl;
	printList(lst);	
	cout << "the list reverse after" << endl;
	lst.reverse();
	printList(lst);

	// 链表排序 sort算法 只适用于可以随机访问的容器
	cout << "the list sort before" << endl;
	printList(lst);
	cout << "the list sort after" << endl;
	lst.sort();
	printList(lst);
}


int main(int argc, char const *argv[])
{
	test05();
	return 0;
}