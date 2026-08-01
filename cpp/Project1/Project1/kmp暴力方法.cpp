#include<iostream>
using namespace std;
const int N = 100010;
const int M = 10010;
char p[N], s[M];    //p[]代表模板串 s[]代表文本串
int main()
{
	int n, m;
	cin >> n >> p >> m >> s;
	for (int i = 0; i < m - n + 1; i++) {
		bool flag = true;
		for (int j = 0; j < n; j++) {
			if (s[i + j] != p[j]) {
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << i << ' ';
		}
	}
	return 0;
	for(int i = 0; i < n; i ++)
}