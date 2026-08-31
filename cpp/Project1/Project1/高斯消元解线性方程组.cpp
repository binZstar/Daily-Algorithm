#include<iostream>
#include<cmath>
using namespace std;
const double eps = 1e-6;
const int N = 1010;
double a[N][N];
int n;
int gauss()
{
	int r = 0;
	//枚举每一列
	for (int c = 0; c < n; c++) {
		//找出这一列中绝对值最大的一行
		int t = r;
		for (int i = r; i < n; i++) {
			if (fabs(a[i][c]) > fabs(a[t][c])) {
				t = i;
			}
		}
		//这一列全部为0
		if (fabs(a[t][c]) < eps) {
			continue;
		}
		//把这一行移动到第一行
		for (int i = c; i <= n; i++) {
			swap(a[t][i], a[r][i]);
		}
		//把这一行第一个非0元素变成1，这一行整体都变
		//必须从后往前归一 因为一直需要用到a[r][c]
		for (int i = n; i >= c; i--) {
			a[r][i] /= a[r][c];
		}
		//把这一列的其余元素全部变成0
		//必须从后往前减
		for (int i = r + 1; i < n; i++) {
			for (int j = n; j >= c; j--) {
				a[i][j] -= a[i][c] * a[r][j];
			}
		}
		//这一行已经确定
		r++;
	}
	if (r < n) {
		for (int i = r; i < n; i++) {
			//无解
			if (fabs(a[i][n]) > eps) {
				return 3;
			}
		}
		//有无穷多解
		return 2;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = i + 1; j < n; j++) {
			a[i][n] -= a[i][j] * a[j][n];
		}
	}
	return 1;
}
int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n + 1; j++) {
			scanf("%lf", &a[i][j]);
		}	
	}
	int res = gauss();
	if (res == 1) {
		for (int i = 0; i < n; i++) {
			printf("x%d = %.2lf\n", i + 1, a[i][n]);
		}
	}
	else if(res == 2) {
		cout << "有无穷多解" << endl;
	}
	else {
		cout << "无解" << endl;
	}
	return 0;
}