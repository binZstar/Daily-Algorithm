#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int, int> PII;
const int N = 10010;
int g[N][N];  //表示该迷宫 为0表示允许通过 为1表示不允许通过
int d[N][N];  //d[x][y]作用一：起点到(x,y)点的距离 作用二：表示(x,y)位置是否被访问
int n, m;
int bfs()
{
	memset(d, -1, sizeof d); //所有位置初始化为未被访问
	queue<PII> q;
	q.push({ 0,0 });
	d[0][0] = 0;  //起点已被访问 且到起点到起点的距离为0
	//坐标移动方向 上~右~下~左
	int dx[4] = { -1,0,1,0 };  //行移动
	int dy[4] = { 0,1,0,-1 };  //列移动
	while (!q.empty())
	{	
		PII t = q.front(); //取出队头
		q.pop();//出队
		//访问t位置的邻接位置
		for (int i = 0; i < 4; i++) {
			int x = t.first + dx[0];
			int y = t.second + dy[0];
			//判断下一个位置是否合法
			if (x >= 0 && x < n && y >= 0 && y < m && g[x][y] == 0 && !d[x][y]) {
				//更新最短距离
				d[x][y] = d[t.first][t.second] + 1;
				//t的邻接位置入队
				q.push({ x,y });  
			}
		}
	}
	//返回终点到起点的距离
	return d[n - 1][m - 1];
}
int main()
{
	//n行m列的迷宫
	scanf("%d%d", &n, &m);
	//迷宫初始化 0表示允许通过 1表示不允许通过
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &g[i][j]);
		}
	}
	//BFS求从迷宫左上角起点到右下角终点的最短距离
	cout << bfs() << endl;
	return 0;
}
