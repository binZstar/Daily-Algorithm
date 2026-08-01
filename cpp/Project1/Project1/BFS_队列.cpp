#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>;
using namespace std;
const int N = 100010;
const int M = 200010;
int h[N];
int e[M], ne[M], idx;
bool st[N];
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void bfs(int start)
{
	queue<int> q;
	q.push(start);   //起点入队
	st[start] = true;//该节点已被访问
	while (!q.empty()){
		int u = q.front();//取出队头
		q.pop();//队头出队
		//访问队头u的所有邻接点
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = e[i];
			if (!st[j]) {
				st[j] = true;//标记已被访问
				q.push(j); //未被访问过则入队
			}
		}
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	bfs(1);
	return 0;
}