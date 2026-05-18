#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	double x;
	scanf("%lf", &x);
	double l = 0, r = max(1.0,x);
	while (r - l > 1e-8) {         //保留n位小数，-1e(n + 2)
		double mid = (l + r) / 2;
		if (mid * mid >= x) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	cout << l << endl;
	return 0;

}