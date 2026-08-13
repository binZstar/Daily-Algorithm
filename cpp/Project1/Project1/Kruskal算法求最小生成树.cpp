#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10010;
const int M = 20010;
struct Edge
{
	int a, b, w;
	bool operator< (const Edge& W) const
	{
		return w < W.w;
	}
}edges[M];
int n, m;
int p[N];
int find(int x)
{
	if (p[x] != x) {
		p[x] = find(p[x]);
	}
	return p[x];
}
int kruskal()
{
	//1. 按照边权值从小到大排序
	sort(edges, edges + m);
	//2. 初始化并查集
	for (int i = 0; i < n; i++) {
		p[i] = i;
	}
	int res = 0;  //最小生成树总权值
	int cnt = 0;  //已经加入了多少条边
	//3. 从小到大枚举所有边
	for (int i = 0; i < m; i++) {
		int a = edges[i].a;
		int b = edges[i].b;
		int w = edges[i].w;
		a = find(a);
		b = find(b);
		//若a与b不连通，将这条边加入最小生成树
		if (a != b) {
			//a与b联通合并
			p[a] = b;
			res += w;
			cnt++;
		}
	}
	//n个节点的最小生成树有n-1条边
	if (cnt < n - 1) {
		return -1;
	}
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		edges[i] = { a,b,c };
	}
	int t = kruskal();
	if (t == -1)  cout << "impossible" << endl;
	else cout << t << endl;
	return 0;
}