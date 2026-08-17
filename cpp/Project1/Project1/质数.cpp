#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//时间复杂度为O(√n)
bool is_prime(int n)
{
	if (n < 2) return false;
	for (int i = 2; i <= n / i; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}
int main()
{
	int n;
	scanf("%d", &n);
	if (is_prime(n)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}