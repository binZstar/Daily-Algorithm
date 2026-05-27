#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> PII;

const int N = 300010;
int a[N], s[N];
vector<int> alls;
vector<PII> add, query;
//二分查找 找到第一个大于等于x的数的下标， 从1开始
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
	int n, m;
	cin >> n >> m;
	while(n--) {
		int x, c;
		cin >> x >> c;          //a[x]加上c
		add.push_back({ x,c }); 
		alls.push_back(x);		//所有有关的数组下标全部离散化
	}

	while (m--) {
		int l, r;
		cin >> l >> r;
		alls.push_back(l);
		alls.push_back(r);
		query.push_back({ l,r });
	}
	//离散化

	//排序
	sort(alls.begin(), alls.end());
	//去重
	alls.erase(unique(alls.begin(), alls.end()), alls.end());

	//处理插入
	for (auto team : add) {
		int x = find(team.first);  //二分查找
		a[x] += team.second;
	}
	//预处理前缀和
	for (int i = 1; i <= alls.size(); i++) {
		s[i] = s[i - 1] + a[i];
	}

	//处理查询 [l,r]区间和
	for (auto team : query) {
		int l = find(team.first);
		int r = find(team.second);
		cout << s[r] - s[l - 1] << endl;
	}

	return 0;
}