#include<iostream>
using namespace std;
const int N = 100010;
int p[N];   //p[x]代表x的父节点
//查找x所在集合的根节点  路径压缩
int find(int x)
{
	if (p[x] != x) p[x] = find(p[x]);
	return p[x];
}
int main()
{
	int n, m;
	cin >> n >> m;
	//初始化
	for (int i = 1; i <= n; i++) {
		p[i] = i;
	}
	while (m--) {
		char op;
		int a, b;
		cin >> op >> a >> b;
		//合并a和b所在的集合
		if (op == 'M') {
			p[find(a)] = find(b);
		}
		//判断a和b是否在一个集合中
		else {
			if (find(a) == find(b)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}
