#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n, m,k;
const int N = 10010;
const int INF = 0x3f3f3f3f;
int dist[N][N];
int floyd()
{
	//k表示中转节点
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
 			}
		}
	}
}
int main()
{
	scanf("%d%d%d", &n, &m,&k);
	memset(dist, 0x3f, sizeof dist);
	//自己到自己的距离为0
	for (int i = 1; i <= n; i++) {
		dist[i][i] = 0;
	}
	//m条边
	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		dist[a][b] = c;
	}
	floyd();
	//k次询问
	while (k--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		if (dist[a][b] > INF / 2) {
			cout << "impossible" << endl;
		}
		else {
			cout << dist[a][b] << endl;
		}
	}
	return 0;
}