#include<iostream>
using namespace std;
#include<vector>;
int main()
{
	//int N;
	//cin >> N;
	//vector<int> v(10);
	//int x = N;
	//while (x > 0) {
	//	int d = x % 10;
	//	v[d]++;
	//	x = x / 10;
	//}
	//for (int i = 0; i < v.size(); i++) {
	//	if (v[i] != 0) {
	//		cout << i << ":" << v[i] << endl;
	//	}
	//}
	//return 0;
	//由于题目要求存储一个不超过1000位的正整数，int最多存储10位正整数，改用string类型可以存储任意长度
	string N;  //用字符串存储整数
	cin >> N;
	vector<int> v(10,0);
	//遍历字符串的每个字符
	for (char c : N) {
		int d = c - '0';
		v[d]++;
	}
	for (int i = 0; i < v.size();i++) {
		if (v[i] != 0) {
			cout << i << ":" << v[i] << endl;
		}
	}
	return 0;
}