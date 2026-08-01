#include<iostream>
#include<algorithm>
using namespace std;
const int N = 50010;
int h[N],ph[N],hp[N];  //ph[k]代表第k个插入的数在堆中的位置  hp[x]代表堆中第x个数是第几个插入的数
int n, m;
int size;
void heap_swap(int a, int b)
{
	swap(ph[hp[a]], ph[hp[b]]);  //交换堆中的位置
	swap(hp[a], hp[b]);				//交换第几个插入的数
	swap(h[a], h[b]);           //交换堆中的值
}
void down(int u)
{
	int t = u;
	if (2 * u <= size && h[2 * u] < h[t]) t = 2 * u;
	if (2 * u + 1 <= size && h[2 * u + 1] < h[t]) t = 2 * u + 1;
	if (t != u) {
		heap_swap(u, t);
		down(t);
	}
}
void up(int u)
{
	while (u / 2 && h[u / 2] > h[u]) {
		heap_swap(u, u / 2);
		u /= 2;
	}
}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &h[i]);
	}
	size = n;
	for (int i = n / 2; i; i--) down(i);   //建立小根堆
	while (m--) {
		char c[4];
		scanf("%s", c);
		//删除第k个插入的元素  crud  增删改查
		if (c == "d1") {
			int k;
			scanf("%d", &k);
			h[ph[k]] = h[size];
			size--;
			down(ph[k]);
			up(ph[k]);
		}
		//删除下标为k的元素
		if (c == "d2") {
			int k;
			scanf("%d", &k);
			h[k] = h[size];
			size--;
			down(k);
			up(k);
		}
		if (c == "c") {
			int x;
			scanf("%d", &x);
			h[++size] = x;
			up[size];
		}
		//更新第k个插入的元素
		if (c == "u") {
			int k,x;
			scanf("&d,%d",&k,&x);
			h[ph[k]] = x;
			down(ph[k]);
			up(ph[k]);
		}
		for (int i = 1; i <= size) {
			cout << h[i] << endl;
		}
		return 0;
	}
	
}