#include<iostream>
#include<algorithm>
using namespace std;
const int N = 110;
int s[N];
int v[N][N], w[N][N];
int f[N];
int main()
{
	int n, m;
	cin >> n >> m;
	//分组背包问题：一共有n组物品，从n组物品中选出不超过背包容量m的物品，每组物品最多选出一个物品
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
		for (int j = 1; j <= s[i]; j++) {
			cin >> v[i][j] >> w[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= 0; j--) {
			for (int k = 1; k <= s[i]; k++) {
				if (j >= v[i][k]) f[j] = max(f[j], f[j - v[i][k]] + w[i][k]);
			}
		}
	}
	cout << f[m] << endl;
	return 0;
}