#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
typedef pair<int, int> PII;  //第一个int代表的是dist,第二个int代表的是节点
const int N = 100010;
const int M = 100010;
int n, m;
int h[N], e[M], ne[M], w[M], idx;  //邻接表
int dist[N];  //最短距离
bool st[N];   //最短距离是否已被确定
void add(int a, int b, int c)
{
	e[idx] = b;
	w[idx] = c;
	ne[idx] = h[a];
	h[a] = idx++;
}
int dijkstra()
{
	//所有距离全部初始化为
	memset(dist, 0x3f, sizeof dist);
	dist[1] = 0;
	//小根堆
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({ 0, 1 });
	while (!heap.empty())
	{
		//取出当前距离最小的节点
		PII t = heap.top();
		heap.pop(); //出队
		int distance = t.second, ver = t.second;
		if (st[ver])  continue;   //如果这个节点已经确定最短距离 就跳过
		//确定ver的最短距离
		st[ver] = true;
		//更新ver的所有出边
		for (int i = h[ver]; i != -1; i = ne[i]) {
			int j = e[i];
			//松弛操作
			if (dist[j] > distance + w[i]) {
				dist[j] = distance + w[i];
				//新距离入队
				heap.push({ dist[j],j });
			}
		}
	}
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
	cout << dijkstra() << endl;
	return 0;
}