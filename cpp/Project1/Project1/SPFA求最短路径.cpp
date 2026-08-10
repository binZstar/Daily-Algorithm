#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int n, m;
const int N = 501;
const int M = 10010;
int h[N], e[M], ne[M], w[M], idx;   //邻接表
int dist[N];  //最短距离
bool st[N];   //st[j]表示j点是否入队
void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}
int spfa()
{
	memset(dist, 0x3f, sizeof sizeof dist);
	dist[1] = 0;
	queue<int> q;
	//起点入队
	q.push(1);
	st[1] = true; //表示起点已入队
	while (!q.empty())
	{
		//取出队头t
		int t = q.front();
		q.pop();
		//t出队
		st[t] = false;
		//更新t的所有出边
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			//松弛操作
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				//如果j不在队列中，让它入队
				if (!st[j]) {
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	if (dist[n] == 0x3f3f3f3f) return -1;
	return dist[n];
}
int main()
{
	memset(h, -1, sizeof h);
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
	}
	int t = spfa();
	if (t == -1)  cout << "impossible" << endl;
	else cout << t << endl;
	return 0;
}