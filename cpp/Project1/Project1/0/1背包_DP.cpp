#include<iostream>
#include<algorithm>
using namespace std;
const int N = 25;
int f[N][N];
int v[N], w[N];  //v[i]代表物品i的体积 w[i]代表物品i的价格
int main()
{
	//物品数量为n
	//背包容量为m;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> v[i] >> w[i];
	}
	//0/1背包问题每个物品最多选择一次
	//状态表示：f[i][j]表示从前i个物品中选择，选择物品的总体积不能超过j
	//状态计算：f[i - 1][j]表示不选i物品 f[i - 1][j - v[i]] + w[i]表示选择i物品
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			//不选i物品
			f[i][j] = f[i - 1][j];
			//选择i物品
			if (j >= v[i]) f[i][j] = max(f[i][j], f[i - 1][j - v[i]] + w[i]);
		}
	}
	cout << f[n][m] << endl;
	return 0;
}