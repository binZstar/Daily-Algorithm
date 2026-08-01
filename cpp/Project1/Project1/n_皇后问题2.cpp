#include<iostream>
using namespace std;
const int N = 10;
char g[N][N];
char row[N];      //行
char col[N];      //列
char diag1[2 * N];//主对角线
char diag2[2 * N];//副对角线
int n; //皇后的个数
//枚举每一个位置 选择放皇后还是不放皇后
//x 行 y 列 s 已放置皇后的数量
void dfs(int x, int y, int s)
{
	if (y == n) x++; y = 0;      //如果第一行枚举完后，枚举下一行
	//n行枚举完后放置皇后的数量是否等于n
	if (x == n) {
		//若皇后的数量等于n，则输出放置的状态
		if (s == n) {
			for (int i = 0; i < n; i++) {
				cout << g[i] << '\n';
				cout << '\n';
			}
		}
		return;
	}
	//选择一：当前位置不放置皇后
	dfs(x, y + 1, s);
	//选择二：当前位置放置皇后
	if (!row[x] && !col[y] && !diag1[x - y + n] && !diag2[x + y]) {
		g[x][y] = 'Q';
		row[x] = true;
		col[y] = true;
		diag1[x - y + n] = true;
		diag2[x + y] = true;
		dfs(x, y + 1, s + 1);
		//恢复现场
		g[x][y] = '.';
		row[x] = false;
		col[y] = false;
		diag1[x - y + n] = false;
		diag2[x + y] = false;

	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			g[i][j] = '.';
		}
	}
	dfs(0, 0, 0);
	return 0;
}