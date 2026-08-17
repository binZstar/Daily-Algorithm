#include<iostream>
#include<unordered_map>
using namespace std;
typedef long long LL;
int mod = 1e9 + 7;
int main()
{
	int n;
	scanf("%d", &n);
	unordered_map<int, int> primes;
	while (n--)
	{
		int x;
		scanf("%d", &x);
		for (int i = 2; i <= x / i; i++) {
			if (x % i == 0) {
				while (x % i == 0) {
					x /= i;
					primes[i]++;
				}
			}
		}
		if (x > 1) {
			primes[x]++;
		}
	}
	LL res = 0;
	for (auto prime : primes) {
		int p = prime.first;
		int a = prime.second;
		LL t = 1;
		while (a--) {
			t = (t * p + 1) % mod;
		}
		res = res * t % mod;
	}
	cout << res << endl;
	return 0;
}
//LL get_divisor_sum(int x)
//{
//	LL res = 1;
//	for (int i = 2; i <= x / i; i++) {
//		if (x % i == 0) {
//			LL t = 1;
//			LL sum = 1;
//			while (x % i == 0) {
//				x /= i;
//				t *= i; 
//				sum += t; 
//			}
//			res *= sum;
//		}
//	}
//	if (x > 1) {
//		res *= (x + 1);
//	}
//	return res;
//}
