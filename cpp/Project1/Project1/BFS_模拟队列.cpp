#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
const int N = 10010;
const int M = 20010;
int h[N];
int e[M], ne[M], idx;
int q[N];    //队列
int hh = 0; //队头
int tt = -1;  //队尾
bool st[N];  //该节点是否访问
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void bfs(int start)
{
	q[++tt] = start;  //起点入队
	st[start] = true; //该节点已被访问
	while (tt >= hh) {
		int u = q[hh++]; //取出队头
		cout << u << ' ';
		//访问u节点节点的所有邻接点
		for (int i = h[u]; i != -1; i++) {
			int j = e[i];
			if (!st[j]) {
				st[j] = true;//该节点已被访问
				q[++tt] = j; //邻接点入队
			}
		}
	}
}
int main()
{
	int n,m;
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	bfs(1);
	return 0;
}