#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int v[N], w[N];
int f[N][N];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i] >> w[i];
	}
	//完全背包问题：从n件物品中选择不超过背包容量m的物品，每件物品可以选择若干次
	//状态表示：f[i][j]从前i件物品中选择，选出的物品的总体积不能超过j
	//状态计算：f[i][j] = max(f[i - 1][j],f[i - 1][j - v] + w,f[i - 1][j - 2*v] + 2*w，......,f[i - 1][j - k*v] + k*w);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= j / v[i]; k++) {
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}