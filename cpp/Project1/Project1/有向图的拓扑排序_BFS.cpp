#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010;
int h[N];
int e[N], ne[N], idx;
int q[N];
int hh = 0, tt = -1;
int d[N]; //d[i]代表i节点的入度数
int n, m;
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
//拓扑排序
int topsort()
{
	//入度为0的节点先入队
	for (int i = 1; i <= n; i++) {
		if (!d[i]) {
			q[++tt] = i;
		}
	}
	while (hh <= tt)
	{
		int u = q[hh++]; //取出队头
		//访问u节点的所有出边
		for (int i = h[u]; i != -1; i = ne[i])
		{
			int j = ne[i];
			//删除边u->j 相当于j点的入度-1
			d[j]--;
			//如果j的入度为0 则入队
			if (d[j] == 0) {
				q[++tt] = j;
			}
		}
	}
	return tt == n - 1;
}
int main()
{
	//n个节点 m条边
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		//添加边 a->b
		add(a, b);
		//b节点的入度+1
		d[b]++;
	}
	if (topsort()) {
		for (int i = 0; i < n; i++) {
			cout << q[i] << ' ';
		}
	}
	else {
		cout << "图中存在环，没有拓扑排序" << endl;
	}
	return 0;
}