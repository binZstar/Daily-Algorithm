#include<iostream>
#include<algorithm>
using namespace std;
const int INF = 1e9;
const int N = 110;
int a[N][N];
int f[N][N];
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	//从上往下移动
	//因为每步只能往左下和右下移动，所以每一步一定是从上一次的左上和右上转移过来的
	//状态表示：f[i][j]表示从顶部到达a[i][j]的最长路径
	//		                        左上                  右上
	//状态计算：f[i][j] = max(f[i - 1][j - 1] + a[i],f[i - 1][j] + a[i])
	//初始化
	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= i + 1; j++) {
			f[i][j] = -INF;
		}
	}
	//memset(f,-0x3f,sizeof f);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = max(f[i - 1][j - 1], f[i - 1][j]) + a[i][j];
		}
	}
	int res = -INF;
	for (int i = 1; i <= n; i++) {
		res = max(res, f[n][i]);
	}
	cout << res << endl;
	return 0;
}