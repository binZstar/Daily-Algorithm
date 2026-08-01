#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> PII;
const int N = 10010;
int g[N][N];   //迷宫 为0允许通过 为1不允许通过
int d[N][N];   //d[x][y]作用一：表示(X,y)到起点的距离  作用二：表示(x,y)是否被访问
PII q[N * N];  //数组模拟队列
PII pre[N][N]; //pre[x][y]表示(x,y)的前驱节点
int n, m;
int bfs()
{
	int hh = 0;
	int tt = -1;
	memset(d, -1, sizeof d);  //所有位置未被访问 且到起点的距离为-1
	//位置移动方向 上~右~下~左
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	d[0][0] = 0; //起点已被访问
	q[++tt] = { 0,0 }; //起点入队
	while (hh <= tt) {
		//取出队头
		PII t = q[hh++];
		//访问t位置的所有邻接位置
		for (int i = 0; i < 4; i++) {
			int x = t.first + dx[i];
			int y = t.second + dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && !g[x][y] && d[x][y] == -1) {
				//更新(x,y)位置到起点的距离
				d[x][y] = d[t.first][t.second] + 1;
				//当前位置入队
				q[++tt] = { x,y };
				//记录(x,y)的前驱节点
				pre[x][y] = t;
			}
		}
	}
	return d[n - 1][m - 1];
}
int main()
{
	//n行m列的迷宫
	scanf("%d%d", &n, &m);
	//迷宫初始化 0表示允许通过 1 表示不允许通过
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &g[i][j]);
		}
	}
	//BFS求从迷宫左上角起点到右下角终点的最短距离
	cout << bfs() << endl; 
	//输出迷宫路径
	vector<PII> path;
	PII current; //当前位置
	//从终点开始反向寻找前驱
	current = { n - 1 , m - 1 };
	while (current != PII{0,0})
	{
		path.push_back(current);
		current = (pre[current.first][current.second]);
	}
	//加入起点
	path.push_back({ 0,0 });
	//当前路径是从终点到起点，所以翻转
	reverse(path.begin(), path.end());
	//输出路径
	for (auto point : path) {
		cout << "(" << point.first << ',' << point.second << ")" << endl;
	}
	return 0;
}
