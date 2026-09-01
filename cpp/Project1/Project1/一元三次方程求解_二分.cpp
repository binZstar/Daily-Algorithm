#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
double a, b, c, d;
double f(double x)
{
	return a * x * x * x + b * x * x + c * x + d;
}
int main()
{
	cin >> a >> b >> c >> d;
	int cnt = 0;
	for (int i = -100; i < 100; i++) {
		double l = i, r = i + 1;
		double fl = f(l);
		double fr = f(r);
		//如果左端点本身就是根
		if (fl == 0) {
			if (cnt) cout << " ";
			cout << fixed << setprecision(2) << l;
			cnt++;
		}
		//如果两端异号 那么中间一定存在根
		else if (fl * fr < 0) {
			//二分查找
			while (r - l > 1e-7) {
				double mid = (l + r) / 2;
				if (f(l) * f(mid) <= 0) {
					r = mid;
				}
				else {
					l = mid;
				}
			}
			if (cnt) cout << " ";
			cout << fixed << setprecision(2) << l;
			cnt++;
		}
		if (cnt == 3) break;
	}
	//对最右端点100特判
	if (cnt < 3 && fabs(f(100)) == 0) {
		if (cnt) cout << " ";
		cout << fixed << setprecision(2) << 100.0;
	}
	return 0;
}