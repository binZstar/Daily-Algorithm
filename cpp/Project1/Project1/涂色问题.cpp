#include<iostream>
using namespace std;
const int N = 55;
string g[N];
int n, m;
int cost(int row, char color)
{
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		if (g[row][i] != color) {
			cnt++;
		}
	}
	return cnt;
}
int main()
{
	//必须涂三个颜色
	//0 ~ i行白色
	//i+1 ~ j行蓝色
	//j+1 ~ n-1行红色
	//i <= 0 < j < n-1
	cin >> n >> m;
	int ans = 0;
	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			//确定i和j后开始涂色
			int sum = 0;
			//0~i行白色
			for (int k = 0; k <= i; k++) {
				sum += cost(k, 'W');
			}
			//i+1~j行蓝色
			for (int k = i + 1; k <= j; k++) {
				sum += cost(k, 'B');
			}
			//j~n-1行红色
			for (int k = j + 1; k <= n - 1; k++) {
				sum += cost(k, 'R');
			}
			//找涂色的最小次数
			ans = min(ans, sum);
		}
	}
	cout << ans << endl;
	return 0;
}