#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int a[N];
int f[N]; 
int g[N]; //g[i]表示i是由谁来转移过来的
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	//线性DP：后面的状态由前面已经计算好的状态转移得到。
	//状态表示：f[i]表示以a[i]结尾的最长上升子序列长度
	//状态计算：f[i] = f[j] + 1
	//3 1 2 5 1 4
	for (int i = 1; i <= n; i++) {
		//只有a[i]自己
		f[i] = 1;
		for (int j = 1; j < i; j++) {
			//如果前面的有数比a[i]小，把他们加起来。
			if (a[j] < a[i]) f[i] = max(f[i], f[j] + 1);
		}
	}
	//保存路径
	for (int i = 1; i <= n; i++) {
		f[i] = 1; //只有a[i]自己
		g[i] = 0;
		for (int j = 1; j < i; j++) {
			//如果前面的有数比a[i]小，把他们加起来。
			if (a[j] < a[i]) {
				if (f[i] < f[j] + 1) {
					f[i] = f[j] + 1;
					g[i] = j;
				}
			}
		}
	}
	int k = 1;
	int res = 1;
	for (int i = 1; i <= n; i++) {
		res = max(res, f[i]);
		if (f[i] > f[k]) {
			k = i;
		}
	}
	//输出路径
	for (int i = 1,len = f[k]; i <= len; i++) {
		cout << a[k] << ' ';
		k = g[k];
	}
	cout << res << endl;
	return 0;
}