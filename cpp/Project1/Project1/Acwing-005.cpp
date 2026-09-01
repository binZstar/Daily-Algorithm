#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int q[N];
int main()
{
	//整数二分
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &q[i]);
	//q[]  1 3 4 4 5 
	//依次输出4的起始位置和末位置
	while (m--) {
		int x;
		scanf("%d", &x);
		int l = 0, r = n - 1;    //l左指针，r右指针
		//先输入x的起始位置
		while (l < r) {
			int mid = (l + r) >> 1;
			if (q[mid] >= x) {   //若q[mid]大于等于x，则r右指针向左移动
				r = mid;
			}
			else {
				l = mid + 1;     //若q[mid]小于x，则i左指针向右移动
			}
		}
		if (q[l] != x) cout << "-1 -1" << endl;   //若没有找到，则输出-1
												  //若找到，接着找末位置
		else {
			cout << l << " ";
			int l = 0, r = n - 1;
			while (l < r) {
				int mid = (l + r + 1) >> 1;
				if (q[x] <= x) {
					l = mid;                    //若q[mid]小于等于x,则l左指针往右移动
				}
				else {
					r = mid - 1;				//若q[mid]大于x，则r右指针往左移动
				}
			}
			cout << l << endl;
		}
	}
	return 0;
}