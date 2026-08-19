#include<iostream>
#include<algorithm>
using namespace std;
//欧拉函数为1~N中和N互质的个数
int main()
{
	int n;
	scanf("%d", &n);
	while (n--)
	{
		int a;
		scanf("%d", &a);
		int res = a;
		for (int i = 2; i <= a / i; i++) {
			if (a % i == 0) {
				while (a % i == 0) {
					a /= i;
				}
				res = res * (i - 1) / i;
			}
		}
		cout << res << endl;
	}
	return 0;
}