#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 10010;
const int M = 20010;
int n, m;
int h[N], e[M], ne[M], idx;
int q[N], hh = 0, tt = -1;
int color[N];
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
bool bfs(int start)
{
	//给start染色并入队
	q[++tt] = start;
	color[start] = 1;
	while (tt >= hh)
	{
		//出队
		int t = q[hh++];
		//遍历t的所有邻接点
		for (int i = h[t]; i != -1; i = ne[i]) {
			int j = e[i];
			//若j没有染色 给j染相反的颜色
			if (!color[j]) {
				q[++tt] = j;
				color[j] = 3 - color[t];
			}
			//若j已染色并且与邻接点u染的颜色相同 说明不是二分图
			else if(color[j] == color[t]) {
				return false;
			}
		}
	}
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h);
	while (m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	bool flag = true;
	//给n个点染色
	//图可能不连通，所以每个点都要检查
	for (int i = 1; i <= n; i++) {
		if (!color[i]) {
			if (!bfs(i)) {
				flag = false;
				break;
			}
		}
	}
	if (flag) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
	
}
