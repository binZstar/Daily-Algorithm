#include<iostream>
using namespace std;
typedef long long LL;
//快速幂
LL qmi(LL a, LL k, LL p)
{
	LL res = 1;
	while (k)
	{
		if (k & 1) res = res * a % p;
		a = a * a % p;
		k >>= 1;
	}
	return res;
}
//求组合数 C[a][b] = a(a-1)...(a-b+1) / b!
LL C(LL a, LL b,LL p)
{
	LL res = 1;
	for (int i = 1, j = a; i <= b; i++, j--) {
		//阶乘
		res = res * j % p;
		//除以i,等于乘i的逆元
		res *= qmi(i, p - 2, p) % p;
	}
	return res;
}
//lucas定理
LL lucas(LL a,LL b,LL p)
{
	if (b == 0) return 1;
	return C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		LL a, b, p;
		cin >> a >> b >> p;
		cout << lucas(a, b, p) << endl;
	}
	return 0;
}