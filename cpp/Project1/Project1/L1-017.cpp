#include<iostream>
#include<string>
#include<iomanip>        //保留几位小数
using namespace std;
int main()
{
	string s;
	cin >> s;
	int cnt = 0;  //2的个数
	int len = 0;  //位数
	for (int i = 0; i < s.size();i++) {
		if (s[i] = '-') {  //有负号不计入位数
			continue;      //continue跳过后面的从新的循环开始进行
		}
		len++;
		if (s[i] == '2') {
			cnt++;
		}
	}
	double ans = cnt / len;
	//有没有负号
	if (s[0] == '-') {
		ans *= 1.5;
	}
	//判断该数是否是偶数
	int last = s[s.size() - 1] - '0';
	if (last % 2 == 0) {
		ans *= 2;
	}
	cout << fixed << setprecision(2) << ans * 100 << "%" << endl;
	return 0;
}