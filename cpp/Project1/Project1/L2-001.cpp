#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>  //用于INT_MAX

const int INF = INT_MAX;
using namespace std;
int main()
{
	int N, M, S, D;  //N城市数量，M通道数量，S出发地，D目的地
	cin >> N >> M >> S >> D;
	vector<int> teams(N); //每个城市救援队的数量
	for (int i = 0; i < N; i++) {
		cin >> teams[i];
	}
	//创建通道路径长度矩阵,初始化为无穷大
	vector<vector<int>> G(N, vector<int>(N, INF));
	//给通道路径长度赋值
	for (int i = 0; i < M;i++) {
		int c1, c2, l;
		cin >> c1 >> c2 >> l;
		G[c1][c2] = l;
		G[c2][c1] = l; //无向图
	}
	//----Dijkstra算法----
	vector<int> dist(N, INF);		 //出发城市到每个城市的最短距离
	vector<int> num_paths(N, 0);     //记录起点到各点最短路径的条数
	vector<int> max_teams(N, 0);     //从起点到各点能召集的最大救援队数
	vector<int> pre(N, -1);          //记录路径的前驱节点
	vector<bool> visited(N, false);  //记录该节点是否被访问
	//对起点初始化
	dist[S] = 0;
	num_paths[S] = 1;
	max_teams[S] = teams[S];
	//找剩余N-1个节点
	for (int i = 1; i < N; i++) {
		//寻找当前未访问且距离最近出发点最近的节点u
		int minDist = INF;
		int u = -1;
		for (int j = 0; j < N; j++) {
			if (dist[j] < minDist && !visited[j]) {
				minDist = dist[j];
				u = j;
			}
		}
		if (u == -1) break;  //剩下的点都不通
		visited[u] = true;     //u节点已被访问
		//更新u的邻居
		for (int v = 0; v < N; v++) {
			if (!visited[v] && G[u][v] != INF) {
				//情况一：找到更短的路径
				if (dist[v] > dist[u] + G[u][v]) {
					dist[v] = dist[u] + G[u][v]; //更新最短路径
					num_paths[v] = num_paths[u]; //继承路径条数
					max_teams[v] = max_teams[u] + teams[v]; //更新最大救援队
					pre[v] = u;  //更新前驱节点
				}
				//情况二：找到相同长度的路径
				else if (dist[v] == dist[u] + G[u][v]) {
					num_paths[v] = num_paths[v] + num_paths[u];
					//如果这条新路径能够召集更多救援队，则更新最大救援队的人数和前驱节点
					if (max_teams[v] < max_teams[u] + teams[v]) {
						max_teams[v] = max_teams[u] + teams[v]; //更新最大救援队人数
						pre[v] = u;  //更新前驱节点
					}
				}
			}
		}
	}
	//-----输出结果----
	cout << num_paths[D] << " " << max_teams[D] << endl;
	//递归输出最短路径
	vector<int> path;
	int curr = D;  //从目的地开始回溯
	while (curr != -1) {
		path.push_back(curr);  //压栈
		curr = pre[curr];
	}
	for (int i = path.size() - 1;i >= 0; i--) {
		cout << path[i];
		if (i > 0) {
			cout << " ";
		}
	}
	cout << endl;
	return 0;

}