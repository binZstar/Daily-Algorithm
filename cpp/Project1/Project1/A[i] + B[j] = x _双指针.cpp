#include<iostream>
using namespace std;
const int N = 10010;
int A[N], B[N];  //A,B数组是升序
int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> B[i];
	}
	//时间复杂度是O(n + m)
	for (int i = 0, j = m - 1; i < n; i++) {
		while (j >= 0 && A[i] + B[j] > x) {
			j--;
		}
		if (A[i] + B[j] == x) {
			cout << i << j << endl;
			break;
		}
	}
	return 0;
}