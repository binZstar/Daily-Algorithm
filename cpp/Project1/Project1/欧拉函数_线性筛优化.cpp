#include<iostream>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N = 1e9;
int primes[N], cnt;
bool st[N];
int phi[N];  //phi[i]表示i的欧拉函数
LL get_eulers(int n)
{
	//1~1中互质的个数为1
	phi[1] = 1;
	//线性筛求欧拉函数 时间复杂度为O(n)
	for (int i = 2; i <= n; i++) {
		//该数为质数
		if (!st[i]) {
			primes[cnt++] = i;
			//质数i的欧拉函数为i - 1
			phi[i] = i - 1;
		}
		for (int j = 0; primes[j] <= n / i; j++) {
			st[primes[j] * i] = true;
			if (i % primes[j] == 0) {
				phi[primes[j] * i] = phi[i] * primes[j];
				break;
			}
			else {
				phi[primes[j] * i] = phi[i] * (primes[j] - 1);
			}
		}
	}
	LL res = 0;
	for (int i = 1; i <= n; i++) {
		res += phi[i];
	}
	return res;
}
int main()
{
	int n;
	scanf("%d", &n);
	LL res = get_eulers(n);
	cout << res << endl;
	return 0;
}