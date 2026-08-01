#include<iostream>
#include<cstring>
using namespace std;
const int N = 10010;
const int M = 20010;
int q[N];
int tt = -1, hh;  //数组模拟队列
int d[N];  //作用1：d[j]表示起点到j的距离  作用2：表示j节点是否被访问
int h[N];
int e[N], ne[N], idx;
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void bfs(int start)
{
	memset(d, -1, sizeof d); //初始化：任一点到起点的距离都为-1 同样表示所有节点未被访问
	q[++tt] = start;
	d[start] = 0;  //起点被访问 起点到起点的距离为0
	while (tt >= hh) {
		int u = q[hh++]; //取出队头
		//访问u节点的所有邻接点
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = ne[i]; 
			if (d[j] == -1) {
				q[++tt] = j;    //邻接点入队
				d[j] = d[u] + 1;//更新j点到起点的距离 同时表示该节点已被访问
			}
		}
	}
	
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	bfs(1);
	for (int i = 1; i <= n; i++) {
		cout << d[1] << ' ';
	}
	cout << endl;
	return 0;
}