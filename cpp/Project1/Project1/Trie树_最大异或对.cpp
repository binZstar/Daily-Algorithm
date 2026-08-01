#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
const int M = N * 31;
int son[M][2];	//二进制每个位数只能是0或1
int a[N];		
int idx;        //字典树中数据的个数
void insert(int x)  //把整数x的二进制从高位往低位存储到Trie树中
{
	int p = 0;
	for (int i = 30; i >= 0; i--) {
		int u = (x >> i) & 1;  //看第i位数字是0还是1  &只有都是1时才是1
		if (!son[p][u]) {
			son[p][u] = ++idx;
		}
		p = son[p][u];
	}
}
int query(int x)     //查询x与Trie树中最大的异或值
{
	int p = 0;
	int res = 0;
	for (int i = 30; i >= 0; i--) {
		int u = (x >> i) & 1;   //看第i位数字是0还是1
		//优先寻找与当前位相反的分支
		if (son[p][u ^ 1]) {      //^相同时为0 不同时为1
			res |= 1 << i;    //res += 1 << i;    |有1个是1的时候就是1
			p = son[p][u ^ 1];
		}else {
			p = son[p][u];
		}
	}
	return res;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		insert(a[i]);
	}
	int res = 0;
	//Trie树方法时间复杂度为O(n)
	for (int i = 0; i < n; i++) {
		res = max(res, query(a[i]));
	}
	cout << res << endl;
	return 0;
	//最大异或对暴力方法 时间复杂度为O(n^2)
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			res = max(res, a[i] ^ a[j]);
		}
	}
}