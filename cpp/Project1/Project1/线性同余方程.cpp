#include<iostream>
#include<cstring>
typedef long long LL;
using namespace std;
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
	int n;
	scanf("%d", &n);
	while (n--)
	{
		LL a, b, m;
		scanf("%d%d%d", &a, &b, &m);
		LL x, y;
		LL d = exgcd(a, m, x, y);
		if (b % d) cout << "impossible" << endl;
		else cout << x * (b / d) % m << endl;
	}
	return 0;
	//a * x = b(mod m) <->  a * x = (a * x / m) * m + b <-> a * x - m * (a * x / m) = b; 求解a和m的最大公约数，若b是该公约数的倍数，则有解
}