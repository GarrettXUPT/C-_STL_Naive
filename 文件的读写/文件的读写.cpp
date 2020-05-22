
#include <iostream> 
#include <fstream>
#include "Person.cpp"

using namespace std;

// 文本文件读写
void test01(){
	// 文件的路径
	char* sourceFileName = (char*)"source.txt";
	char* targetFileName = (char*)"target.txt";

	ifstream ism(sourceFileName, ios::in);  // 以只读方式打开文件
	ofstream osm(targetFileName, ios::out | ios::app); // 以追加写入的模式打开文件

	// 使用成员方法进行打印
	// ifstream ism;
	// ism.open(sourceFileName, ios::in);

	if(! ism){
		cout << "open file fail !!" << endl;
		return;
	}
	// 读文件
	char ch;
	while(ism.get(ch)){
		cout << ch;
		// 将读取的字符串写入文件
		osm.put(ch);
	}
	// 关闭文件
	ism.close();
	osm.close();
}

// 二进制文件操作
void test02(){
	// 文本模式读的是文本文件，二进制模式读取的是二进制文件
	Person p1(10, 20);
	Person p2(11, 22);
	// 将对象写入文件中，对象的序列化
	char* targetFileName = (char*)"Person";
	ofstream osm(targetFileName, ios::out | ios :: binary);
	osm.write((char*)&p1, sizeof(Person));  // 二进制的写文件
	osm.write((char*)&p2, sizeof(Person));  // 二进制的写文件
	// 对象写入完毕
	osm.close();

	// 将写入的对象读取出来
	ifstream ism(targetFileName, ios::in | ios::binary);
	Person person1, person2;
	ism.read((char*)&person1, sizeof(Person));  
	ism.read((char*)&person2 , sizeof(Person));  
	p1.show();
	p2.show();
	// 对象读取完毕
	ism.close();
}

int main(int argc, char const *argv[])
{
	test02();
	return 0;
}