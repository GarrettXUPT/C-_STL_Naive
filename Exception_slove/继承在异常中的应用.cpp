
#include <iostream>
#include <string.h>
#include <string>

using namespace std;

// 异常基类
class BaseMyException
{
public:
	virtual void what() = 0;
	virtual ~BaseMyException(){
		cout << "base class destory" << endl;
	};
	
};

class TargetSpaceNULLException : public BaseMyException
{
public:
	TargetSpaceNULLException(){};
	~TargetSpaceNULLException(){};
	virtual void what(){
		cout << "the target room is empty" << endl;	
	}
	
};

class SourceSpaceNULLException : public BaseMyException
{
public:
	SourceSpaceNULLException(){};
	~SourceSpaceNULLException(){};
	virtual void what(){
		cout << "the source room is empty" << endl;
	}
};

void strCopy(char* source, char* to){
	if (to == NULL)
	{
		throw TargetSpaceNULLException();
		return;
	}
	if(source == NULL){
		throw SourceSpaceNULLException();
		return;
	}
	// int len = strlen(source) + 1;  // 注意一定要加上结束符
	while(*source != '\0'){
		*to++ = *source++; 
	}
}

void printStr(char* str, int len){
	// cout << len << endl;
	for (int i = 0; i < len; ++i)
	{
		cout << str[i];
	}
}

int main(int argc, char const *argv[])
{
	char* source = (char*)"abcdef";
	char* buf = (char* )malloc(sizeof(char) * strlen(source));
	// char* sourceTest = NULL;
	int len = strlen(source);
	try{
		// 将source中的内容拷贝到buf中
		strCopy(source, buf);	
	}catch(BaseMyException& be){
		be.what();
	}
	
	// cout << buf << endl;
	printStr(buf, len);
	return 0;
}