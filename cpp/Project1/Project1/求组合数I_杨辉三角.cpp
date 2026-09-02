#include<iostream>
using namespace std;
const int N = 2010,mod = 1e9 + 7;
int c[N][N];
void init()
{
	//时间复杂度O(N^2)
	//C[a][b] = C[a - 1][b - 1] + C[a - 1][b]
	//从a个苹果中选择b个苹果 把1个苹果拿出来
	//情况一：拿出的这1个苹果选 c[a - 1][b - 1]
	//情况二：拿出的这1个苹果不选 c[a - 1][b]
	for (int i = 0; i < N; i++) {
		for (int j = 0; j <= i; j++) {
			if (!j) c[i][j] = 1;
			else c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
		}
	}
}
int main()
{
	init();
	int n;
	cin >> n;
	while (n--)
	{
		int a, b;
		cin >> a >> b;
		cout << c[a][b] % mod << endl;
	}
	return 0;
}