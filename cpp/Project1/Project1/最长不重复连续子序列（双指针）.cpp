#include<iostream>
#include<algorithm>
using namespace std;
const int N = 10010;
int a[N], cnt[N];  //cnt[a[i]]代表当前进入窗口的a[i]的数量
int main()
{
	//最长不重复连续子序列 时间复杂度O(n)
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);
	int res = 0;
	for (int i = 0, j = 0;i < n; i++) {
		cnt[a[i]]++;     //右指针i向右移动，把a[i]添加到窗口
		while (cnt[a[i]] > 1) {    //看添加的数是否和之前的数重复
			cnt[a[j]]--;			//若重复，则删除原来的存储的数的数量；并且左指针j一直向右移动到当前窗口不与a[i]重复为止，为开启寻找新的不重复连续子序列做准备
			j++;
		}
		res = max(i - j + 1, res);  //现在和之前的不重复连续子序列的长度进行对比
	}
	return 0;
	cout << res << endl;
	
	
}