
#include <iostream>
#include <string>

using namespace std;

// string的初始化
void test01(){
	string s1;  // 无参构造
	string s2(10, 'a');
	string s3("asdfg");
	string s4(s3);  // s3的拷贝

	cout << s1 << endl; // 
	cout << s2 << endl; // aaaaaaaaaa
	cout << s3 << endl; // asdfg
	cout << s4 << endl; // asdfg
}

// 赋值操作
void test02(){
	string s1;
	string s2("appp");
	s1 = "asdfg";
	cout << s1 << endl;  // asdfg
	s1 = s2;
	cout << s1 << endl;  // appp
	s1 = 'a';
	cout << s1 << endl;  // a
	// 以成员方法的形式进行赋值
	s1.assign("jk1");
	cout << s1 << endl;  // jk1
}

// 取值操作
void test03(){
	string s1 = "abcdefg";
	int s1Len = s1.size();

	// 重载[]操作符
	for(int i  = 0; i < s1Len; i++){
		cout << s1[i] << " ";
	}
	cout << endl;

	// 成员方法
	for(int i = 0; i < s1Len; i++){
		cout << s1.at(i) << " ";
	}
	cout << endl;

// 上述两种方式的区别 []方式，若访问越界，程序直接崩溃 成员方法形式，访问越界，会抛出out_of_rang异常
	try{
		for(int i = 0; i < s1Len; i++){
		cout << s1.at(i + 1) << " ";
		}
		cout << endl;		
	}catch(exception e){
		cout << e.what() << endl;
	}
	// b c d e f g std::exception
}

// 拼接操作
void test04(){
	string s1 = "abcd";
	string s2 = "efgh";
	string s3 = s1 + s2;
	cout << s3 << endl;  // abcdefgh,这里+=被重载，可用作string的直接拼接

	string s4 = "1111";
	s3.append(s4);
	cout << s3 << endl;  // abcdefgh1111

	string s5 = "1234";
	string s6 = "5678";
	s5.append(s6, 0, 3);  // 起始位置，所取的长度 将该范围的字符串追加至s5中
	cout << s5 << endl;  // 1234567
} 

// 查找及替换操作
// find操作，由前向后找,查找第一次出现的位置，rfind操作，从后向前找，查找最后一次出现的位置
void test05(){
	string s1 = "abcdefcdg";
	int pos1 = s1.find("cd");
	cout << "the position of cd is : " << pos1 << endl;  // the position of cd is : 2

	int pos2 = s1.rfind("cd");
	cout << "the position of cd is : " << pos2 << endl;  // the position of cd is : 6				

	string s2 = "Garrett xxxx";
	s2.replace(8, 12, "Walker");
	cout << s2 << endl;
}

// string比较
// compare 函数在 > 时，返回1，< 时，返回-1，== 时返回0
// 该处比较是区分大小写的，比较时按照字典顺序，排在前面的是较小值
void test06(){
	string s1 = "acdb";
	string s2 = "abce";
	if(s1.compare(s2) == 0){
		cout << "the result is equal" << endl;
	}else{
		cout << "the result is not equal" << endl;
	}
}

// 截取string子串 
void test07(){
	string s1 = "abcdefgh";
	string s2 = s1.substr(0, 3);  // substr(起始位置, 结束位置),区间左闭右开
	cout << s2 << endl;  // abc
}

// 字符串的插入和删除
void test08(){
	string s1 = "abcdefgh";
	string s2 = s1.insert(3, "p"); // 在索引为3的位置插入p
	cout << s2 << endl;  // abcpdefgh

	string s3 = s1.erase(2, 4); // 由索引为2的位置删除至索引为4的位置,此处位置时左闭右开
	cout << s3 << endl;  // abfgh

}

int main(int argc, char const *argv[])
{
	test08();
	return 0;
}