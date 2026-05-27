#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
vector<int> alls;
//二分查找 找到第一个大于等于x的数
int find(int x)
{
	int l = 0, r = alls.size() - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if (alls[mid] >= x) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}
	return r + 1;
}
int main()
{
	int n;
	scanf("%d", &n);
	vector <int> a(n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		alls.push_back(a[i]);
	}
	//排序
	sort(alls.begin(), alls.end());
	//去重
	alls.erase(unique(alls.begin(), alls.end()), alls.end());
	
	for (int i = 0; i < n; i++) {
		cout << a[i] << " -> " << find(a[i]) << endl;
	}

	return 0;
}
