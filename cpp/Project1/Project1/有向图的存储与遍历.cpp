#include<iostream>
#include<cstring>
using namespace std;
const int N = 100010;
const int M = 100010;
int h[N];
int e[M], ne[M], idx;
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	memset(h, -1, sizeof h); //初始化-1表示当前节点没有出边
	while (m--) {
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	//u代表当前节点
	for (int u = 1; u <= n; u++) {
		cout << u << ": ";
		//遍历当前节点的所有邻接点
		for (int i = h[u]; i != -1; i = ne[i]) {
			int j = ne[i];
				cout << j << ' ';
		}
		cout << endl;
	}
	return 0;
}