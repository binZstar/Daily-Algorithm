#include<iostream>
#include<algorithm>
using namespace std;
const int N = 50010;
int h[N];
int n, m;
int size;
void down(int u)
{
	int t = u;
	if (2 * u <= size && h[2 * u] < h[t]) t = 2 * u;
	if (2 * u + 1 <= size && h[2 * u + 1] < h[t]) t = 2 * u + 1;
	if (t != u) {
		swap(h[u], h[t]);
		down(t);
	}
}
void up(int u)
{
	while (u / 2 > 0 && h[u / 2] > h[u]) {
		swap(h[u], h[u / 2]);
		u /= 2;
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	size = n;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	for (int i = n / 2; i; i--) down(i);
	//输出前m个小的数 即依次输出m个小根堆的根节点
	while (m--) {
		cout << h[1] << endl;
		h[1] = h[size];
		size--;
		down(1);
	}
}