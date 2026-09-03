#include<iostream>
using namespace std;
typedef long long LL;
const int N = 1e5 + 10,mod = 1e9 + 7;
//fact[a]是a的阶乘 infact[a]是a的阶乘的逆元
LL fact[N], infact[N]; 
//a^k % p = a^(2^0 + 2^1 + + 2^n) = a^(2^0) * a^(2^1) * a^(2^2) * * a^(2^n) = a^1 * a^2 * a^4
//费马小定理a^(p - 1) % p = 1; p是质数且与a互质 ax % p = 1; a的逆元是x x=a^(p - 2)
LL qmi(LL a, int k, int p)
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
int main()
{
	//C(a,b)= a!/ [b!(a - b)!] = a! × (b!)⁻¹ × ((a-b)!)⁻¹
	//c[a][b] = a! / (b! * (a - b)!) = a! * b!的逆 * (a - b)的逆
	fact[0] = infact[0] = 1;
	for (int i = 1; i < N; i++) {
		//阶乘
		fact[i] = (fact[i - 1] * i)% mod;
		//逆元
		infact[i] = infact[i - 1] * qmi(i, mod - 2, mod) % mod;
	}
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << fact[a] * infact[b] % mod * infact[a - b] % mod << endl;
	}
	return 0;
}