#include<iostream>
#include<algorithm>
using namespace std;
typedef unsigned long long  ULL;  //字符串哈希判断2个子串是否相等
const int N = 100010;
const int P = 131;      //将字符串转化为P进制的数 P一般为131 ， 13331 哈希冲突的概率很小
ULL h[N];
ULL p[N];
char str[N];
//计算得到任意子串的哈希值
ULL get(int l, int r)
{
	return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	//字符串P进制的前缀和                         //acwing
	p[0] = 1;									//a p[]
	for (int i = 1; i <= n; i++) {
		p[i] = p[i - 1] * P;             //p进制 p[0] = 1
		h[i] = h[i - 1] * P + str[i];    //i位字符串的哈希值
	}
	while (m--)
	{
		int l1, l2, r1, r2;
		scanf("%d%d%d%d", &l1, &r1, &l2, r2);
		if (get(l1, r2) == get(l2, r2)) {
			cout << "Equal" << endl;
		}
		else {
			cout << "No Euqal" << endl;
		}
		return 0;
	}
}