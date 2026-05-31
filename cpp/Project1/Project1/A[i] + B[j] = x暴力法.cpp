#include<iostream>
using namespace std;
const int N = 10010;
int A[N], B[N];
int main()
{
	int n, m, x;
	cin >> n >> m >> x;
	for (int i = 0; i < n; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &B[i]);
	}
	//时间复杂度是 O(n * m)
	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (A[i] + B[j] == x) {
				cout << i << j << endl;
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
	return 0;
}