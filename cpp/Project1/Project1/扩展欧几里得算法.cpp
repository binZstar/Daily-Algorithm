#include<iostream>
#include<cstring>
using namespace std;
//gcd(a,b) = gcd(b,a%b) 欧几里得
//a*x + b*y = gcd(a,b)存在x和y满足方程的充要条件为等号右边是a和b的最大公约数的倍数
int exgcd(int a, int b, int &x, int &y)
{
	if (!b) {
		x = a, y = 0;
		return a;
	}
	//直接引用
	int d = exgcd(b, a % b, y, x);   
	y = y - a / b * x;				 
	return d;
}									 
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a, b, x, y;
		scanf("%d%d", &a, &b);
		exgcd(a, b, x, y);
		printf("%d %d\n", x, y);
	}
	return 0;
}