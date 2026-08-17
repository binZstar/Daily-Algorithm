#include<iostream>
using namespace std;
//时间复杂度为O(√n)
void divide(int x)
{
	for (int i = 2; i <= x / i; i++) {
		if (x % i == 0) {
			//s表示质因数i出现的次数 
			int s = 0;
			while (x % i == 0) {
				x /= i;
				s++;
			}
			cout << i << ' ' << s << endl;
		}
	}
	if (x > 1) {
		cout << x << ' ' << 1 << endl;
	}
}
int main()
{
	int x;
	scanf("%d", &x);
	divide(x);
	return 0;
}