#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//边的结构体
struct Edge
{
	int a, b, w;
}edges[M];
//可能有负环，限制路径最长有k条边
int n, m, k;
const int N = 510;
const int M = 10010;
int dist[N]; //最短距离
//备份数组backup[]的作用是当前轮只能在上一轮更新后的最短距离dist[]的基础上更新，所以路径最多比上一轮多使用一条边
int backup[N]; //保存上一次的更新后的最短距离(备份)
//求解有负权边，限制边数的最短路径 时间复杂度为O(nm)
int bellman_Ford()
{
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	//路径最长为k条边，最多遍历k轮
	for (int i = 0; i < k; i++) {
		memcpy(backup, dist, sizeof dist);
		//更新最短距离
		for (int j = 0; j < m; j++) {
			int a = edges[j].a;
			int b = edges[j].b;
			int w = edges[j].w;
			dist[b] = min(dist[b], backup[a] + w);
		}
	}
	////判断是否有负环
	//for (int j = 0; j < m; j++) {
	//	int a = edges[j].a;
	//	int b = edges[j].b;
	//	int w = edges[j].w;
	//	if (dist[b] > backup[a] + w && dist[b] < 0x3f3f3f3f / 2) {
	//		return true; //存在从起点1能够到达的负环
	//	}
	//}
	//return false;
	if (dist[n] >= 0x3f3f3f3f / 2)  return -1;
	return dist[n];
}
int main()
{
	scanf("%d%d%d", &n, &m, &k);
	for(int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edges[i] = { a,b,c };
	}
	int t = bellman_Ford();
	printf("%d", &t);
	return 0;
}