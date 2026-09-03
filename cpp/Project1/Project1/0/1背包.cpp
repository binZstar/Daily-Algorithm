#include<iostream>
#include<algorithm>
using namespace std;
const int N = 25;
const int M = 1010;
int s[4]; //s[i]表示i学科有几道题
int a[N]; //a[i]表示解决第i道题需要的时间
int solve(int n)
{
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	int f[M] = { 0 }; //f[j]表示给你j时间，最多解决多少分钟的题
	//0/1背包核心
	//因为左右脑可同时算题，左右脑算题的总时间越近，消耗的总时间越少
	// 所以从n道题中选出若干道题给左脑，使选出来的题的总时间不超过所有题时间的1/2，且越大越好
	//每一道题只有两种选择：选 不选 
	//f[j]不选
	//f[j - a[i]] + a[i]选   f[j - a[i]]表示已经选a[i]前提下，f[j]还剩余的容量
	for (int i = 0; i < n; i++) {
		for (int j = sum / 2; j >= a[i]; j--) {
			f[j] = max(f[j], f[j - a[i]] + a[i]);
		}
	}
	return sum - f[sum / 2];
}
int main()
{
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		cin >> s[i];
		ans += solve(s[i]);
	}
	cout << ans << endl;
	return 0;
}