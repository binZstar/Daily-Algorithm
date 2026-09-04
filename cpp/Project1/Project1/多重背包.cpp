#include<iostream>
using namespace std;
const int N = 110;
int v[N], w[N];
int s[N];
int f[N][N];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v[i] >> w[i] >> s[i];
	}
	//多重背包问题：从n件物品中选择不超过背包容量m的物品，每件物品不能超过s件
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			for (int k = 0; k <= s[i] && k <= j / v[i]; j++) {
				f[i][j] = max(f[i][j], f[i - 1][j - k * v[i]] + k * w[i]);
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}