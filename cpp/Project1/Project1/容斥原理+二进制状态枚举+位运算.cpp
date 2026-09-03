#include<iostream>
using namespace std;
typedef long long LL;
const int N = 20;
int primes[N];
int main()
{
	//求解1~n中能至少被m个质数中的一个整除的数的个数
	//将可以被某个质数整除的数看做一个集合i 一共m个质数，共有m个集合
	// s[i]代表能被质数i整除的数的个数
	//利用容斥原理来求解
	int n, m;
	cin >> n;
	//m个质数
	for (int i = 0; i < m; i++) cin >> primes[i];
	LL res = 0;
	//一共有2^m - 1个项
	//二进制状态枚举
	//一共m个质数 每个数的二进制一共m位数 0代表不选p[j]这个质数 1代表选择p[j]这个质数
	for (int i = 1; i < (1 << m); i++) {
		//t代表i的二进制选择的质数的乘积
		LL t = 1;
		//i的二进制选择的质数的个数
		int cnt = 0;
		//每个数的二进制一共m位数
		for (int j = 0; j < m; i++) {
			//0代表不选p[j]这个质数 1代表选择p[j]这个质数
			//如果i的第j位是1，则选择了质数p[j]
			if (i >> j & 1) {
				//防止乘积超过n
				if (t > n / primes[j]) {
					t = -1;
					break;
				}
				t *= primes[j];
				cnt++;
			}
		}
		if (t == -1) {
			continue;
		}
		//n/t代表1~n中能被t整除的个数
		//选择奇数个质数，则加
		if (cnt % 2) {
			res += n / t;
		}
		//选择偶数个质数，则减
		else {
			res -= n / t;
		}
	}
	cout << res << endl;
	return 0;
}