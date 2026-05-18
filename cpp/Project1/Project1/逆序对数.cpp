#include<iostream>
using namespace std;
const int N = 1e5 + 10;
typedef long long LL;
LL q[N],temp[N];
//题目要求求逆序对数(i < j,但q[i] > q[j])
//利用归并分治的思想，每次分割为左右俩边，左边的下标一定比右边的下标小，并且左右俩边都为有序数组，一旦左边的某一个q[i] > 右边的q[j]，那么逆序对数就加mid - i + 1
LL merge_sort(int l, int r)
{
	if (l >= r)  return 0;
	int mid = l + r >> 1;
	LL res = merge_sort(l, mid) + merge_sort(mid + 1, r);
	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r) {
		if (q[i] <= q[j]) {
			temp[k++] = q[i++];
		}
		else {
			temp[k++] = q[j++];
			res += mid - i + 1;
		}
	}
	while (i <= mid) temp[k++] = q[i++];
	while (j <= r)	 temp[k++] = q[j++];
	for (int i = l, j = 0; i <= r;i++, j++)  q[i] = temp[j];
	return res;
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);
	cout << merge_sort(0, n - 1);
	return 0;
}