#include<iostream>
using namespace std;
const int N = 1e5 + 10;
int q[N];
//选择快速排序会更快
//题目要求将数组排序后输入第k小个数，每次快排完，如果左边的数量 >= k，说明第 k 小的数在左半区 如果左边的数量 < k，说明第 k 小的数在右半区
//时间复杂度 O(n)   2n(1 - (1/2)^n)
int quick_sort(int l, int r, int k)
{
	if (l >= r) return q[l];
	int x = q[(l + r) / 2];
	int i = l - 1, j = r + 1;
	while (i < j) {
		do i++; while (q[i] < x);
		do j--; while (q[j] > x);
		if (i < j) swap(q[i], q[j]);
	}
	int sl = j - l + 1;
	if (k <= sl) return quick_sort(l, j, k);
	return quick_sort(j + 1, r, k - sl);
}
int main()
{
	int n, k;
	scanf("%d%d", &n,&k);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);
	cout << quick_sort(0, n - 1, k);
	return 0;
}