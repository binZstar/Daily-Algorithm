#include<iostream>
using namespace std;
const int N = 1000;
int a[N];
int f[N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//状态表示：f[j]表示从0到j的子序列中最长的单调上升序列
	//状态计算：f[i] = max(f[i],f[i - 1] + 1)
	//1 2 3 4 1 5 2
	for (int i = 1; i <= n; i++) {
		f[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
		}
	}
	int res = 0;
	for (int i = 1; i <= n; i++) max(res, f[i]);
	cout << res << endl;
	return 0;
}