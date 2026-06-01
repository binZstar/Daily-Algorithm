#include<iostream>
using namespace std;
const int N = 10010;
int a[N], q[N], hh, tt;  //a数组存储数列，q数组存储a数组的下标
int main()
{
	int n, k;           //n元素的数量，k窗口的大小
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	hh = 0;   //q[hh]代表队头下标
	tt = -1;  //q[tt]代表队尾下标
	for (int i = 0; i < n; i++) {
		//判断队头是否滑出窗口
		if (hh <= tt && q[hh] < i - k + 1) {       //如果i - q[hh] + 1> k; 那么代表当前队尾与队头之间的大小已经超出窗口k的大小，队头已经滑出窗口
			hh++;                                  //如果队头已经滑出窗口，队头向右移动
		}
		//维护单调递增队列
		while (hh <= tt && a[q[tt]] >= a[i]) {
			tt--;									//如果队内存储的数组a的下标的元素大于等于窗口当前坐标所代表的数，将原先存储的坐标出队
		}
		//当前下标入队
		q[++tt] = i;   
		//窗口形成输出最小值
		if (i >= k - 1) {
			cout << a[q[hh]] << ' ';                //满足窗口的大小k即可输出窗口中的最小值
		}
	}
	cout << endl;
	return 0;
}
