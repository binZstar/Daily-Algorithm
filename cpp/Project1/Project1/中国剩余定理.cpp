#include<iostream>
typedef long long LL;
using namespace std;
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
//经典中国剩余定理 x ≡ a[i]​(mod m[i]​)  要求m[i]两两互质
LL crt(LL M,LL a[], LL m[],int n)
{
	LL sum = 0;
	for (int i = 1; i <= n; i++) {
		//求解ti使得 Mi*ti ≡ 1(mod m[i]) 等价于Mi*ti + m[i]*y = 1 利用exgcd
		LL Mi = M / m[i];
		LL x, y;
		exgcd(Mi, m[i], x, y);
		LL ti = x;
		//把a[i]*Mi*ti累加起来
		sum = (sum + a[i] * Mi % M * ti % M) % M;
	}
	//把累加起来的sum%M   
	LL x = (sum % M + M) % M;  //调整为最小非负答案
	return x;
}
int main()
{
	int n;
	scanf("%d", &n);
	LL a[N], m[N];
	LL M = 1;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &m[i]);
		M *= m[i];
	}
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
    }
	LL x = crt(M,a,m,n);
	cout << x << endl;
	return 0;
}