#include<iostream>
using namespace std;
int lowbit(int x)
{
	return x & -x;  //返回x的二进制中最后一个1所代表的值
}
int main()
{
	int x;
	scanf("%d", &x);
	int res = 0;
	while (x) {
		x -= lowbit(x);
		res++;
	}
	cout << res << endl;
	return 0;
}