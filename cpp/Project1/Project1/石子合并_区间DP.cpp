#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 0x3f3f3f3f;
const int N = 310;
int s[N];
int f[N][N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> s[i];
	}
	//前缀和
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + s[i];
	}
	//区间DP：就是从“小区间最优”逐步推出“大区间最优”，但每个大区间通常要枚举所有划分方式，再取最优。
	//石子合并最后一定是由两部分合并而成的
	//这两部分的每一部分又一定是由更小两部分合并而成的
	//要求最终合并的最小代价，就是求更小的两部分的最小代价
	// 状态表示：f[l][r]表示将区间 [l,r] 合并成一堆的最小代价。
	// 状态计算：f[l][r] = min(f[l][r],f[l][k] + f[k + 1][r] + s[r] - s[l - 1])

	//从小到大枚举每个区间的最优解
	for (int len = 2; len <= n; len++) {
		//确定左端点
		for (int l = 1; l + len - 1 <= n; l++) {
			//确定右端点
			int r = l + len - 1;
			f[l][r] = INF;
			//确定区间f[l][r]
			//枚举该区间石子合并的每种划分方式，再从所有方案中找到最优
			for (int k = l; k < r; k++) {
				f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
			}
		}
	}
	cout << f[1][n] << endl;
	return 0;
}