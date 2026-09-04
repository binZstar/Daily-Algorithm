#include<iostream>
#include<algorithm>
using namespace std;
//假设有n个物品，每个物品最多选择s次
//拆分后最多有n * log s个物品
const int N = 25000, M = 2010;
int v[N], w[N];
int f[N];
int main()
{
	int n, m;
	cin >> n >> m;
	//完全背包问题：从n件物品中选出不超过背包容量m的物品，每件物品最多可以选择s件
	//假设第i件物品最多选择s件
	// s = 1 + 2 + 4 + 8 + 16 + 32 + 64 + ···· + c
	//将第i件物品最多选择s件拆分为1，2，4，8，16····c 将每一个拆分的数看做一个物品，在选择的过程中是否选择这件物品
	//cnt表示拆分过后的物品数量
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		int a, b, s;
		cin >> a >> b >> s;
		int k = 1;
		if (k <= s) {
			cnt++;
			v[cnt] = k * a;
			w[cnt] = k * b;
			s -= k;
			k *= 2;
		}
		if (s > 0) {
			cnt++;
			v[cnt] = s * a;
			w[cnt] = s * b;
		}
	}
	//从转化后的cnt件物品中选出不超过背包容量m的物品，每件物品做多选择1次
	// 最后转换为0/1背包问题
	//属性：选出物品的价值最高
	n = cnt;
	for (int i = 1; i <= n; i++) {
		for (int j = m; j >= v[i]; j--) {
			f[j] = max(f[j], f[j - v[i]] + w[i]);
		}
	}
	cout << f[m] << endl;
	return 0;
}