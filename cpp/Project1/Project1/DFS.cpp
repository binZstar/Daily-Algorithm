#include<iostream>
#include<cstring>
using namespace std;
const int N = 10;     //按照字典序遍历1-n
int path[N];          //存储路径   
bool st[N];           //当前节点是否遍历
int n;
void dfs(int u)
{
	if (u == n) {
		for (int i = 0; i < n; i++) {
			cout << path[i] << " ";
		}
		cout << endl;
		return;
	}
	for (int i = 1; i <= n; i++) {
		if (!st[i]) {
			path[u] = i;           
			st[i] = true;
			dfs(u + 1);
			//path[u] = 0;
			st[i] = false;   //回溯
		}
	}
}
int main()
{
	scanf("%d", &n);
	dfs(0);
	return 0;
}