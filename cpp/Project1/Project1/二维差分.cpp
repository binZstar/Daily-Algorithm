#include<iostream>
using namespace std;
const int N = 1010;
int a[N][N], d[N][N];
int main()
{
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1;i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	//构建二维差分数组
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			d[i][j] = a[i][j] - a[i - 1][j - 1];
		}
	}
	//q次修改
	while (q--) {
		int x1, y1, x2, y2, c;
		scanf("%d%d%d%d%d", &x1, &y1, &x2, &y2,&c);
		d[x1][y1] += c;
		d[x2 + 1][y1] -= c;
		d[x1][y2 + 1] -= c;
		d[x2 + 1][y2 + 1] += c;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + d[i][j];
			printf("%d", a[i][j]);
		}
	}
	return 0;
}