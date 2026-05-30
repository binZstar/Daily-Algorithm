#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
//gcd约分(找最大公约数)
LL gcd(LL a, LL b)
{
	a = abs(a);
	b = abs(b);   //abs取绝对值
	while (b) {
		LL t = a % b;
		a = b;
		b = t;
	}
	return a;
}
int main()
{
	int n;
	cin >> n;
	LL sum_num = 0, sum_den = 1;  //sum_num代表分子，sum_den代表分母 初始和为0/1
	while (n--) {
		LL a, b;
		char slash;
		cin >> a >> slash >> b;
		//分数相加
		sum_num = sum_num * b + a * sum_den;
		sum_den = sum_den * b;
		//求最大公约数
		LL g = gcd(sum_num, sum_den);
		//约分
		sum_num /= g;
		sum_den /= g;
	}
	//将假分数 -> 整数 + 真分数
	//保证分母为正
	if (sum_den < 0) {
		sum_den = -sum_den;
		sum_num = -sum_num;
	}
	//如果结果为0
	if (sum_num == 0) {
		cout << 0 << endl;
		return 0;
	}
	//求整数部分
	LL integer = sum_num / sum_den;    //整数部分
	LL rest = abs(sum_num % sum_den);  //真分数的分子部分
	if (!rest) {
		//只有整数部分
		cout << integer << endl;
	}
	else if (!integer) {
		//只有分数部分
		cout << sum_num << "/" << sum_den;
	}
	else {
		cout << integer << ' ' <<rest << "/" << sum_den << endl;
	}

	return 0;
}