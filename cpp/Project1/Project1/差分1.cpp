#include<iostream>
using namespace std;
const int N = 10010;
int a[N], d[N];  //a[N]是前缀和 ，d[N]是前缀和的反向操作，类似于原数组 a[i] = a[i - 1] + d[i]
//差分就是前缀和的反向操作
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	//构造差分数组 
	for (int i = 1; i <= n; i++) {
		d[i] = a[i] - a[i - 1];
	}

	//m次区间修改
	while (m--) {
		int l, r, c;     
		scanf("%d%d%d", &l, &r, &c);   //使a[n]数组从[l,r]区间加上c
		d[l] += c;       //修改差分数组，让d[l]加上c，利用前缀和a[i] = a[i - 1] + d[i];这样使[l,n]都加上了c
		d[r + 1] -= c;   //然后让d[r + 1]减去c，这样就会使a数组[r + 1,n]都减去c，这两部完成只会使a数组[l,r]区域加上c
	}
	for (int i = 1; i <= n; i++) {
		a[i] += a[i - 1] + d[i];   //利用前缀和公式a[i] = [i - 1] + d[i]
		printf("%d", a[i]);
	}
	return 0;

}