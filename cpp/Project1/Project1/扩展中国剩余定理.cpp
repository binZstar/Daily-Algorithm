#include<iostream>
using namespace std;
typedef long long LL;
const int N = 25;
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
//扩展中国剩余定理 
//x ≡ a[i]​(mod m[i]​) m[i]不两两互质
//线性同余方程两两合并 x ≡ a[1]​(mod m[1]​)  x ≡ a[2]​(mod m[3]​)
//x = a[1] + m[1]*k 将x带入得到
//a[1] + m[1]*k ≡ a[2]​(mod m[3]​) 化简得-> m[1]*k ≡ a[2] - a[1]​(mod m[3]​)
LL excrt(LL a[],LL m[], int n)
{
	for (int i = 1; i <= n; i++) {

	}
}
int main()
{
	int n;
	scanf("%d", &n);
	LL a[N], m[N];
	//LL M = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &m[i]);
		//M *= m[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	LL x = excrt(a, m, n);
	cout << x << endl;
	return 0;
}