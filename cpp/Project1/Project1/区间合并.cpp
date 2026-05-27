#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
typedef pair<int, int> PII;

vector<PII> segs;

void merge(vector<PII>& segs)
{
	vector<PII> res;
	//先按左端点排序
	sort(segs.begin(), segs.end());

	int st = -2e9, ed = -2e9;
	for (auto seg : segs) {
		int l = seg.first, r = seg.second;
		//
		if (ed < l) {               
			if (st != -2e9) {
				res.push_back({ st,ed });  //如果没有交集，把这个区间存进答案
			}
			st = l;                        //并且进入下一个区间
			ed = r;
		}
		else {
			ed = max(ed, r);               //若有交集，取大的右端点
		}
	}
	if (st != -2e9) {
		res.push_back({ st,ed });          //将最后一个区间存进答案
	}
	segs = res;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		segs.push_back({ l,r });
	}
	merge(segs);

	cout << segs.size() << endl;
	return 0;
}