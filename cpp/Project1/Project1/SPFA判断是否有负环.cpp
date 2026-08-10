#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n, m;
const int N = 501;
const int M = 10010;
int h[N], e[M], ne[M], w[M], idx;
int dist[N];
//cnt[x]表示当前得到的到达x节点的最短路径经过了多少条边
int cnt[N];
bool st[N];   //st[j]代表j节点是否入队
void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}
int spfa()
{
	queue<int> q;
	//判断整张图是否有负环
	//将所有节点都入队
	for (int i = 1; i <= n; i++) {
		q.push(i);
		st[i] = true;
	}
	while (!q.empty())
	{
		int t = q.front();
		q.pop();
		st[t] = false;
		for (int i = h[t]; i != -1; i = ne[i])
		{
			int j = e[i];
			//松弛操作
			if (dist[j] > dist[t] + w[i]) {
				dist[j] = dist[t] + w[i];
				cnt[j] = cnt[t] + 1;
				//共有n个节点，一条简单路径最多有n-1条边
				//如果已经用了 >= n条边，那么一定出现重复节点
				if (cnt[j] >= n) {
					return true;
				}
				//j不在队列中才入队
				if (!st[j]) {
					q.push(j);
				}
			}
		}
	}
	return false;
}
int main()
{
	memset(h, -1, sizeof h);
	while (m--)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		add(a, b, c);
	}
	if (spfa())  cout << "Yes" << endl;  //有负环
	else cout << "No" << endl;           //无负环
	return 0;
}