#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> ans;
bool is_prime(int x)
{
	if (x < 2) return false;
	for (int i = 2; i <= x / i; i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}
int make_palindrome(int x)
{
	int res = x;
	x /= 10;
	while (x) {
		res = res * 10 + x % 10;
		x /= 10;
	}
	return res;
}
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	//先处理一位数字
	for (int i = 1; i <= 9; i++) {
		if (i >= a && i <= b && is_prime(i)) {
			ans.push_back(i);
		}
	}
	//再处理11
	if (11 >= a && 11 <= b) ans.push_back(11);
	
	//只处理奇位数(3位数，5位数，7位数) 因为偶位数回文数除了11其余都不是质数
	for (int len = 3; len <= 7; len += 2) {
		int half_len = len / 2 + 1;
		//前半部分数字的开头
		int start = 1;
		for (int i = 1; i < half_len; i++) {
			start *= 10;
		}
		//前半部分数字的结尾
		int end = start * 10 - 1;
		//遍历每一位奇数位数
		for (int x = start; x <= end; x++) {
			//根据前半部分生成回文数
			int p = make_palindrome(x);
			if (p > b) continue;
			if (p >= a && is_prime(p)) {
				ans.push_back(p);
			}
		}
	}
	for (auto x : ans) {
		cout << x << endl;
	}
	return 0;
}