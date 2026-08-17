#include<iostream>
using namespace std;
const int N = 100010;
int primes[N];	//保存所有质数
bool st[N];		//是否被筛选过
int cnt;		//质数的数量
//朴素筛：筛选每个数的倍数
void get_primes(int n)
{
	for (int i = 2; i <= n; i++) {
		//选择质数
		if (!st[i]) {
			primes[cnt++] = i;
		}
		//筛选i的全部倍数
		for (int j = i + i; j <= n; j += i) {
			st[j] = true;
		}
	}
}
//埃式筛：只筛选质数的倍数
//埃式筛的时间复杂度为O(n log log n)
void get_primes(int n)
{
	for (int i = 2; i <= n; i++) {
		//i没有被之前的数筛选过，说明i是质数
		if (!st[i]) {
			primes[cnt++] = i;
			//筛选质数i的倍数
			for (int j = i + i; j <= n; j += i) {
				st[j] = true;
			}
		}
	}
}
//线性筛：一个合数只筛选一次
//线性筛的时间复杂度为O(n)
void is_primes(int n)
{
	for (int i = 2; i <= n; i++) {
		//如果i没筛掉，i就是质数
		if (!st[i]) {
			primes[cnt++] = i;
		}
		//用最小质因数来筛选每个合数，每个合数只由最小的质因数筛选一遍
		for (int j = 0; primes[j] <= n / i; j++) {
			st[primes[j] * i] = true; 
			//当p[j]是i的最小质因数，跳出循环
			if (i % primes[j] == 0) {
				break;
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; !primes[i]; i++) {
		cout << primes[i] << ' ';
	}
	return 0;
}
