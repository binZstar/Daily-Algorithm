#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
const int N = 510;
const int M = 100010;
int n1, n2, m;
int h[N], e[M], ne[M], idx;
int match[N];
bool st[N];
void add(int a, int b)
{
	e[idx] = b;
	ne[idx] = h[a];
	h[a] = idx++;
}
bool find(int x)
{
	//访问x喜欢的所有右侧节点
	for (int i = h[x]; i != -1; i = ne[i]) {
		int j = e[i]; 
		//这一轮x还没考虑过j
		if (!st[j]) {
			st[j] = true;
			//j还没人匹配
			//或者j原来的对象还能找到别人
			if (match[j] == 0 || find(match[j])) {
				//把j匹配给x
				match[j] = x;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	scanf("%d%d%d", &n1, &n2, &m);
	memset(h, -1, sizeof h);
	while (m--)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		add(a, b);
	}
	int cnt = 0;
	//左边的每个人都访问自己喜欢的所有右侧节点
	for (int i = 1; i <= n1; i++) {
		//每个人都重新开始寻找
		memset(st, false, sizeof st);
		//匹配成功的个数加1
		if (find(i)) {
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}
