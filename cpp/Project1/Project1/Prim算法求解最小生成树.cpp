#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 501;
const int INF = 0x3f3f3f3f;
int n, m;
int g[N][N];  //邻接矩阵
int dist[N];  //dist[j]表示j节点到当前生成树集合内最小的一条边
bool st[N];   //st[j]表示j节点是否加入到当前最小生成树集合
int prim()
{
	memset(dist, 0x3f, sizeof dist);
	int res = 0;
	for (int i = 0; i < n; i++) {
		int t = -1;   //t表示距离当前生成树集合的最小的节点
		//找没有加入集合并且dist最小的节点
		for (int j = 1; j <= n; j++) {
			if (!st[j] && (t == -1 || dist[t] > dist[j])) {
				t = j;
			}
		}
		//若不是第一个节点 并且距离集合的最小距离依然为0x3f3f3f3f，说明剩余节点无法和当前生成树连接
		if (i && dist[t] == INF) {
			return -1;
		}
		//第一个点不需要边连接
		//若不是第一个节点，添加最小生成树的权值
		if (i) {
			res += dist[t];
		}
		//用新加入的t更新其他点到当前生成树集合的最短距离
		for (int j = 1; j <= n; j++) {
			dist[j] = min(dist[j], g[t][j]);
		}
		//标记t加入到生成树集合
		st[t] = true;
	}
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	memset(g, 0x3f, sizeof g);
	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		//无向图 可能存在重边
		g[a][b] = g[b][a] = min(g[a][b], c);
	}
	int t = prim();
	if (t == -1)  cout << "impossible" << endl;
	else cout << t << endl;
	return 0;
}