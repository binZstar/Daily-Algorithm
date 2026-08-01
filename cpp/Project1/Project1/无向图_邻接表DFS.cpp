#include<iostream>
#include<cstring>
using namespace std;
const int N = 100010;
const int M = 200010;   //无向边的存储是节点数量的2倍
int h[N];
int e[M];
int ne[M];
bool st[N];
int idx;
//添加一条边
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
void dfs(int u)
{
	st[u] = true;     //u表示当前节点已被访问
	cout << u << " ";
	//遍历u节点的所有邻接点
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!j) {
			dfs(j);
		}
	}
}
int main()
{
	int n, m;         //n节点数 m边数
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);      //初始化-1表示当前节点没有出边
	while (m--) {
			int a, b;
			scanf("%d%d", &a, &b);
			add(a, b);
			add(b, a);  //无向图两边都要添加
	}
	//时间复杂度O(n + m)
	dfs(1);
	return 0;
}
