#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int main()
{
	double x;
	scanf("%lf", &x);
	int l = -10000, r = 10000;
	while(r - l > 1e-8){
		double mid = l + r >> 1;
		if (mid * mid * mid >= x) r = mid;
		else l = mid;
	}
	printf("%lf", l);
	return 0;
}