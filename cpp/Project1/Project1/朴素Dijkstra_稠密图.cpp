#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510;
int n, m;     //n个点 m条边
int g[N][N];  //邻接矩阵
int dist[N];  //dist[j] 表示j点到起点的距离
bool st[N];   //st[j] 表示j到起点的最短距离是否已被确定
//dijkstra求最短路径核心在与 ：先找一个没有确定最短距离且距离最小的点t，然后根据点t更新其他所有节点 (dist[t] + g[t][j])和(dist[j])谁数值更小 然后不断迭代
int dijkstra()
{
	//距离全部初始化为0x3f3f3f3f
	memset(dist, 0x3f, sizeof dist);
	//起点到起点的距离为0
	dist[1] = 0;
	//迭代n个点
	for (int i = 0; i < n; i++) {
		//t表示没有确定最短距离且距离最小的节点
		int t = -1;
		//找没有确定最短距离，且距离最小的节点
		for (int j = 1; j <= n; j++) {
			if (!st[j] && (t == -1 || dist[t] > dist[j])) {
				t = j;
			}
		}
		//标记：t的最短距离已经被确定
		st[t] = true;
		if (t == n) {
			return dist[n];
		}
		//用t更新其他所有节点
		for (int j = 1; j <= n; j++) {
			dist[j] = min(dist[j], dist[t] + g[t][j]);
		}
	}
	if (dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];    
}
int main()
{
	scanf("%d%d", &n, &m);
	//邻接矩阵全部初始化为0x3f3f3f3f
	memset(g, 0x3f, sizeof g);
	//给m条边赋值
	while (m--)
	{
		int a, b, w;
		scanf("%d%d%d", &a, &b, &w);
		g[a][b] = min(g[a][b], w);
	}
	cout << dijkstra() << endl;
	return 0;
}