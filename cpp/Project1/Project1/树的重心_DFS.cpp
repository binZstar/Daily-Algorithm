#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 100010;
const int M = 200010;
int h[N];
int e[M], ne[M], idx;
int q[N];
bool st[N];
int n, m;
int ans = n;  //树的重心的节点
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
//返回删除u节点后剩余的连通图最大节点数
int dfs(int u)
{
	//该节点已被访问
	st[u] = true;
	//以u为根节点的子树的节点个数
	int sum = 1;
	//删除u节点后剩余的连通图最大的节点个数
	int size = 0;
	//遍历以u的邻接点j为根节点的子树的节点个数
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		if (!st[j]) {
			//以j为根节点的子树的节点数量
			int s = dfs(j);
			//找u的邻接点j为根节点子树的节点数量的最大值
			size = max(size, s);
			//更新以u为根节点的子树的节点数量
			sum += s;
		}
	}
	//在以u的邻接点j为根节点子树的节点数量的最大值和删除u以后u上面剩余的节点数量中找最大值
	size = max(size, n - sum);
	//在删除每个节点后的连通图的节点数量中的最大值找最小值 该点为树的重心
	ans = min(ans, size);
	return sum;
}
int main()
{
	//n个节点 m条边
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
		add(b, a);
	}
	dfs(1);
	return 0;
}
//树的重心：给定一棵有 n 个节点的树，删除某个节点后，树会分成若干个连通块。求删除哪个节点，可以使其中节点数最多的连通块尽可能小。
//删除任意一个节点，连通图会有2种情况：假设删除u节点
//情况1：以 u 的每个子节点为根的子树
//情况2：u 的父节点方向剩下的部分