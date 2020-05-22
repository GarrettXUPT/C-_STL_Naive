
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

/*
	案例说明：
		公司招聘了五个员工，五名员工进入公司之后，需要指派他们到特定的部门里面工作
		人员信息有：姓名、年龄、电话、工资等组成
		通过multimap进行信息的插入，保存，显示
		分部门显示员工的信息，显示全部员工信息
*/
#define SALE_DEPARTMENT 1
#define DEVELOP_DEPARTMENT 2
#define FINACIAL_DEPARTMENT 3
#define ALL_DEPARTMENT 4

// 员工类
class Worker
{
public:
	Worker(){};
	~Worker(){};
public:
	string mName;
	string mTele;
	int mAge;
	int mSalary;
};

void CreatWorker(std::vector<Worker>& vworker){
	string seedName = "ABCDE";
	for (int i = 0; i < 5; ++i)
	{
		Worker worker;
		worker.mName = "employee";
		worker.mName += seedName[i];
		worker.mAge = rand() % 10 + 20;
		worker.mTele = "010-888888";
		worker.mSalary = rand() % 10000 + 10000;
		// 保存员工信息
		vworker.push_back(worker);
	}
}

void WorkerGroup(std::vector<Worker>& vworker, multimap<int, Worker>& group){
	// 将员工随机分派到不同的部门
	for(std::vector<Worker>::iterator it = vworker.begin(); it != vworker.end(); it++){
		int departID = rand() % 3 + 1;
		switch(departID){
			case SALE_DEPARTMENT:
				group.insert(make_pair(SALE_DEPARTMENT, *it)); 
				break;
			case DEVELOP_DEPARTMENT:
				group.insert(make_pair(DEVELOP_DEPARTMENT, *it)); 
				break;
			case FINACIAL_DEPARTMENT:
				group.insert(make_pair(FINACIAL_DEPARTMENT, *it)); 
				break;
			default:
				break;
		}
	}
}

void PrintWorkerByGroup(multimap<int, Worker>& group){
	// 打印销售员工信息
	// 返回SALE_DEPARTMENT第一次出现的位置
	multimap<int, Worker>::iterator it = group.find(SALE_DEPARTMENT);
	// 找当前部门人数
	int num= 0;
	int departCount = group.count(SALE_DEPARTMENT);
	while(it != group.end() && num < departCount){
		cout << "NAME：" << (*it).second.mName << " AGE：" << (*it).second.mAge << 
					" TELE：" << (*it).second.mTele << " SALARY：" << (*it).second.mSalary  << endl;
		it++;
		num++;
	}

	// 打印开发员工信息
	// 返回DEVELOP_DEPARTMENT第一次出现的位置
	multimap<int, Worker>::iterator it1 = group.find(DEVELOP_DEPARTMENT);
	// 找当前部门人数
	int num1= 0;
	int departCount1 = group.count(DEVELOP_DEPARTMENT);
	while(it1 != group.end() && num1 < departCount1){
		cout << "NAME：" << (*it1).second.mName << " AGE：" << (*it1).second.mAge << 
					" TELE：" << (*it1).second.mTele << " SALARY：" << (*it1).second.mSalary  << endl;
		it1++;
		num++;
	}

	// 打印销售员工信息
	// 返回SALE_DEPARTMENT第一次出现的位置
	multimap<int, Worker>::iterator it2 = group.find(FINACIAL_DEPARTMENT);
	// 找当前部门人数
	int num2= 0;
	int departCount2 = group.count(FINACIAL_DEPARTMENT);
	while(it2 != group.end() && num2 < departCount2){
		cout << "NAME：" << (*it2).second.mName << " AGE：" << (*it2).second.mAge << 
					" TELE：" << (*it2).second.mTele << " SALARY：" << (*it2).second.mSalary  << endl;
		it2++;
		num2++;
	}
}

void showWorkerByGroup(multimap<int, Worker>& group, int departID){
	// 打印销售员工信息
	// 返回SALE_DEPARTMENT第一次出现的位置
	multimap<int, Worker>::iterator it = group.find(departID);
	// 找当前部门人数
	int num= 0;
	int departCount = group.count(departID);
	while(it != group.end() && num < departCount){
		cout << "NAME：" << it->second.mName << " AGE：" << it->second.mAge << 
					" TELE：" << it->second.mTele << " SALARY：" << it->second.mSalary  << endl;
		it++;
		num++;
	}
}

int main(int argc, char const *argv[])
{
	// 存放新员工信息
	std::vector<Worker> vworker;
	// multimap保存分组信息
	multimap<int, Worker> group;
	// 创建员工
	CreatWorker(vworker);
	// 员工分组
	WorkerGroup(vworker, group);
	// 打印每一个员工部门的员工信息
	// PrintWorkerByGroup(group);
	showWorkerByGroup(group, SALE_DEPARTMENT);


	return 0;
}

