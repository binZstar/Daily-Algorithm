#include<iostream>
#include<unordered_set>  //自动去重
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;

	unordered_set<string> has_friend; //有朋友的人

	for (int i = 0; i < n; i++) {
		int k;
		cin >> k;
			for (int j = 0; j < k; j++) {
				string id;
				cin >> id;
				if(k > 1){
					has_friend.insert(id);
			}
		}
	}

	int m;
	cin >> m;

	unordered_set<string> printed; //记录已经输出过的人
	bool first = true;
	bool found = false;
	for (int i = 0; i < m; i++) {
		string id;
		cin >> id;
		if (!has_friend.count(id) && !printed.count(id)) {
			if (!first) {
				cout << " ";
			}
			cout << id;
			printed.insert(id);
			first = false;
			found = true;
		}
	}
	if (!found) {
		cout << "No one is handsome";
	}
	return 0;
}

