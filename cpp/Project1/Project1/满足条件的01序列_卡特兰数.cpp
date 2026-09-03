#include<iostream>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
//快速幂
int qml(int a, int k, int p)
{
	int res = 1;
	while (k)
	{
		if (k & 1) res = res * a % p;
		a = a * a % p;
		k >>= 1;
	}
	return res;
}
int main()
{
	//给定n个0和n个1，将这2n个数排列，使得任意前缀序列0的个数都不少于1的个数
	//把这个带要求的序列问题抓换为坐标的移动问题
	//0代表向横坐标(右)移动 1代表向纵坐标(上)移动 最终到达(n,n) (n,n)关于y = x + 1对称的坐标是(n - 1,n + 1)
	// 到达(n,n)的走法共有C(2n,n)种
	//要求0的数量不少于1的数量 转换为 x >= y
	//其中x超过y且最终仍然到达坐标(n,n)的走法为C(2n,n - 1)种
	//所以x不超过不超过y的走法有C(2n,n) - C(2n,n - 1)种 化简为 C(2n,n)/(n + 1)
	int n;
	cin >> n;
	int a = 2 * n;
	int b = n;
	int res = 1;
	//a的阶乘
	for (int i = a; i > a - b; i--) res *= i % mod;
	//b的阶乘的逆元
	for (int i = 1; i <= b; i++) res *= qml(i, mod - 2, mod) % mod;
	res *= qml(n + 1, mod - 2, mod) % mod;
	cout << res << endl;
	return 0;
}