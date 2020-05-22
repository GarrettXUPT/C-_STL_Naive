
#include <iostream>
#include <string.h>
#include <iomanip>

using namespace std;

// 标准输出流
// cout.flush()刷新缓冲区
// cout.put() 获取一个字符并输出 
// cout.write() 写一个字符串
void test01(){
	cout << "hello world" << endl; 
	// cout.flush();
	cout.put('h').put('e').put('l').put('l').put('o') << endl; 
	cout.write("Garrett Walker", strlen("Garrett Walker"));
}

// 格式化输出
void test02(){
	int number = 10;
	cout << number << endl;	
	// 使用成员方法的方式设置输出的格式
	cout.unsetf(ios::dec);  // 卸载当前默认的十进制输出方式
	cout.setf(ios::oct);  // 将输出格式设置为八进制输出
	cout.setf(ios::showbase);  // 将十六进制中的0x 或者是 八进制的0 显示出来
	cout << number << endl;  // 12 10的八进制形式

	// 进行十六进制输出
	cout.unsetf(ios::oct);
	cout.setf(ios::hex);
	cout.setf(ios::showbase);
	cout << number << endl;

	cout.width(10);  // 将输出宽度设置为10
	cout.fill('*');  // 将出输出数据的剩余位置使用*来代替 
	cout.setf(ios::left); // 设置为左对齐
	cout << number << endl;

	// 通过控制符方式
	int number2 = 15;
	cout << hex << setiosflags(ios::showbase) << setw(10) << setfill('&') << number2 << endl;
	// 上述表示将number2以十六进制，带上进制标志符0x，宽度为10，其他地方以&填充得格式进行输出

}

int main(int argc, char const *argv[])
{
	test02(); 
	return 0;
}