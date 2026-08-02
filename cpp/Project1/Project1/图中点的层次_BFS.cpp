#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010;
const int M = 200010;
int h[N];
int e[M], ne[M], idx;
int q[N];
int hh = 0, tt = -1;
int d[N];  //d[i]代表i点在图中的层次
int n, m;
void add(int a,int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void bfs()
{
	memset(d, -1, sizeof d);
	d[0] = 0;    //起点的层次为0 同时表示q[0]已被访问
	q[++tt] = 1; //起点入队
	while (hh <= tt)
	{
		int u = q[hh++]; //取出队头
		//访问u的所有邻接点
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			if (d[j] == -1) {
				//更新j点在图中的层次
				d[j] = d[u] + 1;
				//j点入队
				q[++tt] = j;
			}
		}
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int a, b;
		memset(h, -1, sizeof h);
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	bfs();
	for (int i = 0; i < n; i++)
	{
		cout << d[i] << ' ';
	}
	cout << endl;
	return 0;
}