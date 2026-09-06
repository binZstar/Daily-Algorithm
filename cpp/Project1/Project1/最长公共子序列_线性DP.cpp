#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
char a[N];
char b[N];
int f[N][N];
int main()
{
	int n, m;
	cin >> n >> m;
	cin >> a + 1;
	cin >> b + 1;
	//A = abc
	//B = ac
	//状态表示：f[i][j]表示A的前 i 个字符，与 B 的前 j 个字符的最长公共子序列长度
	//状态计算：两种情况
	// 如果a[i] = b[j]，在前面i - 1 和 j - 1的最长公共子序列基础上加1
	// 如果a[i] != b[j]，分别舍去一个i，舍去一个j,保留前面的最长公共子序列
	// 如果 a[i] != b[j]，那么这两个字符(不能同时)作为(公共子序列)的最后一个字符
	// 所以要么舍去 a[i]，要么舍去 b[j]，两种情况取最大值
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i] == b[j]) {
				f[i][j] = f[i - 1][j - 1] + 1;
			}
			else {
				f[i][j] = max(f[i - 1][j], f[i][j - 1]);
			}
		}
	}
	cout << f[n][m] << endl;
	return 0;
}