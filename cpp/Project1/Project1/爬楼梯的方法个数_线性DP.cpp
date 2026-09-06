#include<iostream>
#include<algorithm>
using namespace std;
const int N = 100010;
int a[N];
int f[N];
int main()
{
	//n层楼梯
	int n;
	cin >> n;
	//状态表示：f[i]表示从0~i层的总方案数
	//状态计算：走到第i层只有最后一步只有2种走法
	//走法1：从第i - 2层走2层到达第i层
	//走法2：从第i - 1层走i层到达第i层
	//所以当前步的走法种类取决与前一步是怎么走的,由上一步转移过来的
	//f[i] = f[i - 1] + f[i - 2]
	//初始化
	f[1] = 1;
	f[0] = 1;
	for (int i = 2; i <= n; i++) {
		f[i] = f[i - 1] + f[i - 2];
	}
	cout << f[n] << endl;
	return 0;
}