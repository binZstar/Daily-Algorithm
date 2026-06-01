#include<iostream>
using namespace std;
int main()
{
	int t1, t2;
	cin >> t1 >> t2;
	int n;
	cin >> n;
	int cnt1 = 0,cnt2 = 0;
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int sum = x1 + x2;
		if (sum == y1 && sum != y2) {
			cnt1++;
		}
		if (sum != y1 && sum == y2) {
			cnt2++;
		}
		if (cnt1 > t1) {
			cout << "A" << endl << cnt2 << endl;
			break;
		}
		if (cnt2 > t2) {
			cout << "B" << endl << cnt1 << endl;
			break;
		}
	}
	return 0;
}