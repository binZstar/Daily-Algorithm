#include<iostream>
using namespace std;
const int N = 1010;
int a[N][N], s[N][N];  //二维前缀和
int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n;i++) {
		for (int j = 1;j <= m; j++) {
			scanf("%d", &a[i][i]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + a[i][j];  //求二维前缀和
		}
	}
	while (q--) {
		int x1, y1, x2, y2;
		scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
		cout << s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1];  //求任意二维区间的和
	}
}