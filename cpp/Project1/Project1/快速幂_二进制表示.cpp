#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
//返回a^k%p  时间复杂度为O(log k)
//原理为把a^k转换为a^(2^0) a^(2^1) a^(2^2).... a^(2^(log k))中有限项的相乘
LL qmi(int a, int k, int p)
{
	int res = 1;
	//把k转换成二进制
	while (k)
	{
		//如果该位的二进制为1
		if (k & 1) 	res = (LL)res * a % p;
		//二进制位运算右移
		k >>= 1;
		a = (LL)(a * a) % p;
	}
	return res;
}
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a, k, p;
		scanf("%d%d%d", &a, &k, &p);
		LL res = qmi(a, k, p);
		cout << res << endl;
	}
	return 0;
}