#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
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
	//状态表示：f[i][j]表示从 (i,j) 这个位置出发，走到底部能得到的最大路径和。
	//初始化
	for (int i = 1; i <= n; i++) {
		f[n][i] = a[n][i];
	}
	for (int i = n - 1; i >= 1; i--) {
		for (int j = 1; j <= i; j++) {
			f[i][j] = max(f[i + 1][j] + a[i][j], f[i + 1][j + 1] + a[i][j]);
		}
	}
	cout << f[1][1] << endl;
	return 0;
}