#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> get_divisors(int n)
{
	vector<int> res;
	for (int i = 1; i <= n / i; i++) {
		if (n % i == 0) {
			res.push_back(i);
			//约数成对出现
			if (i != n / i) {
				res.push_back(n / i);
			}
		}
	}
	//将约数从小到大排列
	sort(res.begin(), res.end());
	return res;
}
int main()
{
	int n;
	scanf("%d", &n);
	vector<int> res = get_divisors(n);
	for (auto x : res) {
		cout << x << ' ';
	}
	cout << endl;
	return 0;
}