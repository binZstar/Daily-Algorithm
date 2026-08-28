#include<iostream>
using namespace std;
typedef long long LL;
//扩展欧几里得算法
LL exgcd(LL a, LL b, LL& x, LL& y)
{
	if (!b) {
		x = 1;
		y = 0;
		return a;
	}
	LL d = exgcd(b, a % b, y, x);
	y -= a / b * x;
	return d;
}
int main()
{
	//n个线性同余方程 
	//x mod a = m
	int n;
	scanf("%d", &n);
	bool has_answer = true;
	//输入第一个线性同余方程 x mod a = m; x = a1k1 + m1;
	LL a1, m1;
	scanf("%d%d", &a1, &m1);
	for (int i = 1; i <= n; i++) {
		//输入第二个线性同余方程 x mod a2 = m2; x = a2k2 + m2;
		//合并得到 a1k1 - a2k2 = m2 - m1
		//k1与k2有解的充要条件是m2 - m1是a1与a2的最大公约数的倍数
		LL a2, m2;
		scanf("%d%d", &a2, &m2);
		LL k1, k2;
		//d表示a1与a2的最大公约数
		LL d = exgcd(a1, a2, k1, k2);
		//若任意合并后的方程无解，则无解
		if ((m2 - m1) % d) {
			has_answer = false;
			break;
		}
		//x = a1*(k1 + (a2 / d) * k) + m1 = k(a1 * a2 / d) + a1k1 + m1;
		//当前的k1是满足a1k1 - a2k2 = gcd(a1,a2) = d，因此k1需要乘以(m2 - m1)是d的几倍
		k1 *= (m2 - m1) / d;
		LL t = a2 / d;
		k1 = (k1 % t + t) % t;
		m1 = a1 * k1 + m1;
		a1 = abs(a1 / d * a2);
	}
	if (has_answer) {
		cout << (m1 % a1 + a1) % a1 << endl;
	}
	else {
		cout << "impossible" << endl;
	}
	return 0;
}