#include<iostream>
#include<algorithm>
using namespace std;
const int N = 310;
struct Student {
	int id;
	int chinese;
	int math;
	int english;
	int sum;
};
Student s[N];
bool better(Student a, Student b)
{
	//总分不同，大的排在前面
	if (a.sum != b.sum) {
		return a.sum > b.sum;
	}
	//总分相同，语文高的排在前面
	if (a.chinese != b.chinese) {
		return a.chinese > b.chinese;
	}
	//总分相同，语文相同，id小的排在前面
	return a.id < b.id;
}
int main()
{
	int n;
	scanf("%d",& n);
	for (int i = 1; i <= n; i++) {
		s[i].id = i;
		scanf("%d%d%d", &s[i].chinese, &s[i].math, &s[i].english);
		s[i].sum = s[i].chinese + s[i].math + s[i].english;
	}
	//sort包左不包右 
	//在排序过程中一直调用better函数 看a与b谁排在前面
	sort(s + 1, s + n + 1, better);
	for (int i = 1; i <= 5; i++) {
		cout << s[i].id << ' ' << s[i].sum << endl;
	}
	return 0;
}
