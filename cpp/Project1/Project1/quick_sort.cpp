#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int q[N];
//快排（左边的值都小于等于临界值，右边的值都大于等于临界值）
void quick_sort(int q[], int l, int r)
{
	if (l >= r) return;  //数组是空或只有一个数不用排序
	//确定临界值
	int x = q[l]; //若数据增强 int x = q[(l + r) / 2];
	int i = l - 1; int j = r + 1;  //i代表左指针，j代表右指针
	while (i < j) {
		do(i++); while (q[i] < x);     //先移动指针，若左边的值小于临界值，则移动指针，若大于等于临界值，则停下里
		do(j--); while (q[j] > x);	   //若右边的值大于临界值，则移动指针，若小于临界值，则停下来
		if (i < j) swap(q[i], q[j]);   //都停下来交换数值，把大的往右边移动，小的往左边移动
	}
	quick_sort(q, l, j);            //递归快排
	quick_sort(q, j + 1, r);
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n;i++) {
		scanf("%d", q[i]);
	}
	quick_sort(q, 0, n - 1);
	for (int i = 0; i < n; i++) {
		printf("%d ", q[i]);
	}
	return 0;
}