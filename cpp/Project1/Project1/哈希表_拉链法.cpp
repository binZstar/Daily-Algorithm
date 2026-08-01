#include<iostream>
using namespace std;
const int N = 100010;
int h[N];  //头结点
int e[N];
int ne[N];
int idx;
//插入一个数
void insert(int x)
{
	int k = (x % N + N) % N;
	e[idx] = x;
	ne[idx] = h[k];
	h[k] = idx;
	idx++;
}
bool query(int x)
{
	int k = (x % N + N) % N;
	for (int i = h[k]; i != -1; i = ne[i]) {
		if (e[i] == x) {
			return true;
		}
	}
	return false;
}
int main()
{
	int n;
	scanf("%d", &n);
	memset(h, -1, sizeof h);
	while (n--) {
		int x;
		scanf("%d", &x);
		char op[2];
		scanf("%s", op);
		if (op == "I") {
			insert(x);
		}
		else {
			if (query(x)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
			
		}
	}
	return 0;
}
