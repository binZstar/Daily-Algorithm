#include<iostream>
using namespace std;
const int N = 10010;
int a[N], cnt[N];
//时间复杂度为O(n^2)
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int res = 0;
	for (int i = 0; i < n; i++) {
		memset(cnt, 0, sizeof cnt);
		for (int j = i; j < n;j++) {
			cnt[a[j]]++;
			if (cnt[a[j]] > 1) {
				break;
			}
			res = max(res, j - i + 1);
		}
	}
	cout << res << endl;
}