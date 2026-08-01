#include<iostream>
using namespace std;
const int N = 10;
char g[N][N];
bool col[N];   //col[i]代表第i列是否被放置皇后
bool diag1[2 * N];   //主对角线 行 - 列
bool diag2[2 * N];	 //副对角线 行 + 列
int n;       
//给第u行放置皇后
void dfs(int u)
{
	//若u == n,代表第0~n-1行都放置了皇后
	if (u == n) {
		for (int i = 0; i < n; i++) {
			cout << g[i] << ' ';
		}
		cout << endl;
	}
	//枚举第u行的每一列
	for (int i = 0; i < n; i++) {
		//如果列和两条斜线都没有皇后，就可以放
		if (!col[i] && diag1[i] && !diag2[i]) {
			g[u][i] = 'Q';
			col[i] = diag1[u - i + n] = diag2[u + i] = true;
			//进入下一行
			dfs(u + 1);
			//恢复现场
			g[u][i] = '.';
			col[i] = diag1[u - i + n] = diag2[u + i] = false;
		}
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = '.';
		}
	}
	dfs(0);
	return 0;
}