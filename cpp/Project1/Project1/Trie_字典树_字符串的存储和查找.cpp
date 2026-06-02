#include<iostream>
using namespace std;
const int N = 100010;
int son[N][26];  // son[p][u] 表示节点 p 的字符 u 儿子节点编号  // p 是当前节点编号，u 是字符编号，0 表示没有这个儿子
int idx;		// idx 表示当前已经用到的最大节点编号
int cnt[N];		//cnt[p]代表以节点p结尾的相同字符串的个数
char str[N];    //存储或查找的字符串
//字符串的存储
void insert(char str[])
{
	int p = 0;  //根节点是0
	for (int i = 0; str[i]; i++) {
		int u = str[i] - 'a';   //将字符转换为数字存储
		if (!son[p][u]) {       //如果该字符串的某个字符编号没有以p为父节点存储过，存储它
			son[p][u] = ++idx;  
		}
		p = son[p][u];      //存储完以后再将这个新的字符编号作为父节点p来存储下一个字符编号
	}
	cnt[p]++;               // 以节点p结尾的相同字符串的数目加1
}
//字符串的查找
int query(char str[])
{
	int p = 0;             //从根节点0开始查找
	for (int i = 0; str[i]; i++) {
		int u = str[i] - 'a';
		if (!son[p][u]) {    //如果没有查找到这个字符串的某一个字符 直接返回0
			return 0;
		}
		p = son[p][u];      //如果该字符找到，继续以该节点为父节点继续查找下一个字符
	}
	return cnt[p];         //如果找到该字符串，返回以p结尾的字符串的数目
}
int main()
{
	int n;
	cin >> n;
	while (n--) {
		char op[2];
		scanf("%s%s", op, str);
		if (op[0] == 'I') {
			insert(str);
		}
		else {
			cout << query(str) << endl;
		}
	}
	return 0;
}