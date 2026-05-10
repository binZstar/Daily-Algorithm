#include<iostream>
#include<string>
#include<vector>
using namespace std;
//定义学生结构体
struct student {
	string id;
	int examSeat;
};
int main()
{
	int N;   //学生人数 学生有唯一的id,trySeat,examSeat
	         //题目要求根据trySeat输出id和examSeat,用trySeat作为学生数组的下标，这样可以直接定位这个学生直接输出该学生的id和examSeat，不需要再遍历寻找
	         //这样的时间复杂度是M；但遍历的话时间复杂度是M*N;
	cin >> N;
	vector<student> v(N + 1);
	for (int i = 1; i < N + 1;i++) {
		string id;
		int trySeat, examSeat;
		cin >> id >> trySeat >> examSeat;
		v[trySeat] = { id,examSeat };
	}
	int M;
	cin >> M;
	for (int i = 0; i < M;i++) {
		int findSeat;
		cin >> findSeat;
		cout << v[findSeat].id << " " << v[findSeat].examSeat << endl;
	}
	return 0;
}