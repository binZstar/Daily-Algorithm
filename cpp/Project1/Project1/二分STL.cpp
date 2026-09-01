#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
const int N = 1e5 + 10;
int q[N];
int m, n;
void fun(int x)
{
	//二分STL
	//左边界：找第一个(>=)大于等于x的数的位置
	lower_bound(q, q + n, x) - q;
	//找第一个严格(>)大于x的数的位置
	upper_bound(q, q + n, x) - q;
	//右边界：找第一个(<=)小于等于x的数的位置
	upper_bound(q, q + n, x) - q - 1;
	//找第一个严格(<)小于x的数的位置
	lower_bound(q, q + n, x) - q - 1;
}
int main()
{
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> q[i];
	}
	int sum = 0;
	while (n--)
	{
		int x;
		cin >> x;
		//二分：找到第一个大于等于x的数的下标
		int pos = lower_bound(q, q + n, x) - q;
		int mini = 1e9;
		if (pos < m) {
			mini = min(mini, abs(q[pos] - x));
		}
		if (pos > 0) {
			mini = min(mini, abs(q[pos - 1] - x));
		}
		sum += mini;
	}
	cout << sum << endl;
	return 0;
}