#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int q[N], temp[N];
//归并排序（先切分排序为两个有序数组，再合二为一变为一个新的有序数组）时间复杂度 O(n*log2(n)) 空间复杂度 O(n)
void merge_sort(int q[], int l, int r)
{
	if (l >= r) return;   //如果数组大小为空或者1，则不用排序
	int mid = (l + r) / 2;     //确定中间值
	merge_sort(q, l, mid);       //递归排序左半边
	merge_sort(q, mid + 1, r);   //递归排序右半边
	int k = 0, i = l, j = mid + 1;   //i代表左指针，j代表右指针，从二个有序的数组挑选出最小的值，保存在新建有序数组temp中
	while (i <= mid && j <= r) {     //小中取小
		if (q[i] <= q[j]) {
			temp[k++] = q[i++];
		}
		else {
			temp[k++] = q[j++];
		}
	}
	while (i <= mid) temp[k++] = q[i++];    //如果某一个有序数组的指针遍历完成后，而另一个数组的指针还没移动完成，需要将剩余的数据粘贴过来
	while (j <= r) temp[k++] = q[j++];
	for (int i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];   //将新建的数组赋值给原来的q数组
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", q[i]);
	merge_sort(q, 0, n - 1);
	for (int i = 0; i < n; i++) cout << q[i] << " " << endl;
	return 0;
}