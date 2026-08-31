#include<iostream>
#include<vector>
using namespace std;
const int n = 10;
int path[n];
vector<vector<int>> ans;
int x;
void dfs(int u,int sum)
{
	if (u == n) {
		if (sum == x) {
			vector<int> t;
			for (int i = 0; i < n; i++) {
				t.push_back(path[i]);
			}
			ans.push_back(t);
		}
		return;
	}
	//还有几种配料未放
	int left = n - u;
	//遍历每种配料的克数
	for (int i = 1; i <= 3; i++) {
		int new_sum = sum + i;
		//剪枝
		//选完这一种配料还剩下几种配料未选
		int rest = left - 1;
		//选的不符合 重新选择 下面不继续进行
		if (new_sum + rest * 1 > x) continue;
		if (new_sum + rest * 3 < x) continue;
		//符合则递归
		path[u] = i;
		dfs(u + 1,new_sum);
		//回溯
		path[u] = 0;
	}
}
int main()
{
	scanf("%d", &x);
	dfs(0, 0);
	cout << ans.size() << endl;
	for (auto t : ans) {
		for (int i = 0; i < t.size(); i++) {
			cout << t[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}