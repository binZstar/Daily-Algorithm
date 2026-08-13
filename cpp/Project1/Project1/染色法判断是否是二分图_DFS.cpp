#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10010;
const int M = 20010;
int n, m;
int h[N], e[M], ne[M], idx;
int color[N];
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
bool dfs(int u, int c)
{
	color[u] = c;
	//遍历u的所有邻接点
	for (int i = h[u]; i != -1; i = ne[i]) {
		int j = e[i];
		//若j没有染色
		if (!color[j]) {
			//给j染相反颜色  3-c与邻接点u的染色不同
			if (!dfs(j, 3 - c)) {
				return false;
			}
		}
		//若j已染色并且与邻接点u染色相同 说明不是二分图
		else if (color[j] == c) {
			return false;
		}
	}
	return true;
}
int main()
{
	memset(h, -1, sizeof h);
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		//无向图
		add(a, b);
		add(b, a);
	}
	bool flag = true;
	//给n个节点染色
	//图可能不连通，所以每个点都要检查
	for (int i = 1; i <= n; i++) {
		//给第i个节点染色
		if (!color[i]) {
			if (!dfs(i, 1)) {
				flag = false;
				break;
			}
		}
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}