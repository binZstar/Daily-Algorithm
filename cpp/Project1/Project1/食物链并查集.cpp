#include<iostream>
using namespace std;
const int N = 50010;
int p[N], d[N];   //p[x]代表x的父节点，d[x]代表于x与父节点的关系 
//d[x] = 0 代表x与父节点关系为同类,d[x] = 1 代表与父节点关系为 x 吃父节点，d[x] = 2代表 x 与父节点的关系为 x 被父节点吃

int find(int x)            //找到x的根节点以及x与根节点的关系
{
	if (p[x] != x) {
		int t = p[x];
		p[x] = find(p[x]);
		d[x] = (d[x] + d[t]) % 3;
	}
	return p[x];
}
int main()
{
	int n,k;  //k句话
	scanf("%d%d",&n,&k);
	for (int i = 1; i <= n; i++) {
		p[i] = i;
		d[i] = 0;
	}
	int ans = 0;   //假话的个数
	while (k--) {
		int op, x, y;
		scanf("%d%d%d", &op, &x, &y);
		if (x > n || y > n) {
			ans++;
			continue;
		}
		if (op == 2 && x == y) {
			ans++;
			continue;
		}
		int px = find(x);
		int py = find(y);
		if (px != py) {
			p[px] = py;  //没有关系先建立关系
			//维护关系
			if (op == 1) {
				d[px] = d[y] - d[x];                  
			}
			else {
				d[px] = d[y] + 1 - d[x];
			}
			d[px] = (d[px] % 3 + 3) % 3;
		}
		else {
			if (op == 1) {
				if ((d[x] - d[y]) % 3 != 0) {
					ans++;
				}
			}
			else {
				if ((d[x] - d[y]) % 3 != 1) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}