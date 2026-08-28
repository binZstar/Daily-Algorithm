#include<iostream>
#include<string>
#include<cmath>
using namespace std;
string s;
void solve(int score)
{
	//模拟的思想：每打一球，比分发生变化，并看这局比赛是否结束
	int a = 0, b = 0;
	for (char c : s) {
		if (c == 'W') {
			a++;
		}
		else {
			b++;
		}
		if ((a >= score || b >= score) && abs(a - b) >= 2) {
			cout << a << ':' << b << endl;
			a = 0;
			b = 0;
		}
	}
	cout << a << ':' << b << endl;
}
int main()
{
	char c;
	//cin忽略空格和换行符号
	while (cin >> c) {
		if (c == 'E') {
			break;
		}
		s += c;
	}
	//11分制
	solve(11);
	cout << endl;
	//21分制
	solve(21);
	return 0;
}