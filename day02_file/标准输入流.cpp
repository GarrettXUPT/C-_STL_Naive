
#define _CRT_SECRE_NO_WARNINGS

#include <iostream>

using namespace std;

#if 0
cin:
	char ch = cin.get() ͨ����������ȡ�����ַ�
cout�Ǹ�ȫ���������Զ�����ʾ������
cerr����׼����������ݵ���ʾ����û�л�����
clog����׼��־��������ݵ���ʾ�����л�����
endl��ˢ�»�����
#endif

// ��׼������
void test01(){  
	char ch1;
	// �ɻ��������õ�����
	while((ch1 = cin.get()) != EOF){
		cout << ch1;
	}

	char ch2;
	cin.get(ch2);  // ��ȡһ���ַ�

	// ��ȡ�̶����ȵ��ַ���
	char buf[256] = { 0 };
	int len = sizeof(buf) / sizeof(buf[0]);
	// cin.get(buf, len);
	// cout << buf << endl;

	// ��ȡһ������,���ǲ����ȡ���з�
	cin.getline(buf, len);
	cout << buf << endl;
}

// cin.ignore() ���Ե�ǰ���ַ�
void test02(){
	char ch;
	cin.get(ch);  // �ӻ������ж�ȡ����,����asdf����ǰ��ȡ����a
	cout << ch << endl;
	cin.ignore();  // ���Ե�ǰ�ַ������Ե���s  cin.ignore(10)��ʾ���Ǻ���10���ַ�
	cin.get(ch);    // �˴���ȡ����d
	cout << ch << endl;
}

// cin.peek�����ǲ鿴����������������ݣ�������ȡ��
void test03(){
	cout << "input number or string" << endl;
	char ch;
	ch = cin.peek();   // �鿴����������������ݣ��᷵�ص�һ���ַ�
	if(ch >= '0' && ch <= '9'){
		int number;
		cin >> number;  // ���������е��ַ���ȡ��number��
		cout << "this is a number: " << number <<endl;
	}else{
		char buf[256] = { 0 };
		cin >> buf;
		cout << "this is a string: " << buf << endl;
	}
}

// cin.putback ���Ժ�cin.get һ��ʹ��,cin.get()���ַ��ӻ��������ó���cin.putback()���ַ��Żػ�����
void test04(){
	cout << "input string or number please" <<endl;
	char ch;
	cin.get(ch);  // �ӻ������л�ȡ
	if(ch >= '0' && ch <= '9'){
		cin.putback(ch); // ���ַ��Żػ�����
		int number;
		cin >> number;
		cout << "this is a number: " << number <<endl;
	}else{
		cin.putback(ch); // ���ַ��Żػ�����
		char buf[256] = { 0 };
		cin >> buf;
		cout << "this is a string: " << buf << endl;
	}
}
 
int main(int argc, char const *argv[])
{
	test04();
	return 0;
}