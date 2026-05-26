#include<iostream>
using namespace std;
const int N = 10010;
int a[N];
int main()
{
	int n, x;
	scanf("%d%d", &n,&x);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int l = 0, r = n - 1;
	while (l < r) {
		int s = a[l] + a[r];
		if (s == x) {
			cout << l << " " << r << endl;
			break;
		}
		else if (s < x) {
			l++;
		}
		else {
			r--;
		}
	}
	return 0;
}