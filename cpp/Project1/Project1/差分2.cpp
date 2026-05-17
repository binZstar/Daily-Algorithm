#include<iostream>
using namespace std;
const int N = 100010;
int a[N], d[N];
void insert(int l, int r, int c)
{
	d[l] += c;
	d[r + 1] -= c;

}
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
	//构造差分数组
	for (int i = 1; i <= n; i++) insert(i, i, a[i]);
	
	//m次修改
	while (m--)
	{
		int l, int r, int c;
		scanf("%d%d%d", &l, &r, &c);
		insert(l, r, c);    
	}
	for (int i = 1; i <= n; i++) d[i] += d[i - 1];
	for (int i = 1; i <= n; i++) {
		cout << d[i] << " ";
	}
	return 0;
}