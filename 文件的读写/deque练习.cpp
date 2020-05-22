
#include <iostream>
#include <deque>
#include <algorithm>  // 算法库
#include <vector>


using namespace std;

class Student
{
public:
	Student(int id){
		this->_id = id;
	};
	~Student(){};
	void Bejudge(std::vector<int> score){
		std::vector<int>::iterator it = score.begin();
		while(it != score.end()){
			sorcList.push_back(*it++);
		}
	}

	void showScoreList(){
		sortDeque();
		delScore();
		cout << "the score list is " << endl;
		printSorceList();
		computeAverage();
	}

	void showStudent(){
		cout << "Student id: " << this->_id << endl;
		showScoreList();
		cout << "average score is " << this->average << endl;
	}

	void computeAverage(){
		int sum = 0;
		deque<int>::iterator it = sorcList.begin();
		while(it != sorcList.end()){
			sum = *it++ + sum;
		}
		// cout << sum << " " << sorcList.size() << endl;
		average = (float(sum) / float(sorcList.size()));
	}
		
private:
	int _id;
	double average;
	deque<int> sorcList;

	void sortDeque(){
		deque<int>::iterator it = sorcList.begin();
		sort(it, sorcList.end());
	}

	void delScore(){
		sorcList.pop_back();
		sorcList.pop_front();
	}

	void printSorceList(){
		deque<int>::iterator it = sorcList.begin();
		while(it != sorcList.end()){
			cout << *it++ << " "; 
		}
		cout << endl;
	}
};


class Judger
{
public:
	Judger(int id){
		this->_id = id;
	};
	~Judger(){};
	void judgeScore(int i){
		judgeList.push_back(i);
	}

	std::vector<int> ScoreList(){
		cout << "this is id : " << this->_id << "judger judgeList" << endl;
		std::vector<int>::iterator it = judgeList.begin();
		while(it != judgeList.end()){
			cout << *it++ << " ";
		} 
		cout << endl;
		return judgeList;
	}
private:
	int _id;
	std::vector<int> judgeList;	
};


std::vector<int> judgeDuring(Judger judger){
	for(int i = 0; i < 10; i++){
		judger.judgeScore(i);
	}
	std::vector<int> tmp = judger.ScoreList();
	return tmp;
}

int main(int argc, char const *argv[])
{
	Judger j1(1);
	Student s1(1);
	std::vector<int> soreLst = judgeDuring(j1);
	s1.Bejudge(soreLst);
	s1.showStudent();
	
	return 0;
}