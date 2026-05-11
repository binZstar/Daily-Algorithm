#include<iostream>
using namespace std;
bool check()
{

}
//整数二分
//区间[l,r]被划分为[l,mid]和[mid + 1,r]时使用
int bsearch_Int(int q[], int l, int r)
{
	
	while (l < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
}
//区间[l,r]被划分为[l,mid - 1]和[mid,r]时使用
int bsearch_Int(int q[], int l, int r)
{
	while (l < r) {
		int mid = (l + r + 1) >> 1;
		if (check(mid)) {
			l = mid;
		}
		else {
			r = mid - 1;
		}
	}
}

//浮点二分
double bsearch_Double(double q[n], double l, double r)
{
	int l = 0; int r = n - 1;
	while (r - l > 1e-8) {
		double mid = l + r >> 1;
		if (check(mid)) {
			l = mid;
		}
		else {
			r = mid;
		}	
	}
}