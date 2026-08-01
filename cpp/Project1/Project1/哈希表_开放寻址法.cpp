#include<iostream>
using namespace std;
const int N = 10000;  //开的数组大小是数据数量的2倍 并且是质数 哈希冲突的概率最小
const int null = 0x3f3f3f3f;
int h[N];
//质数
/*int find()
{
	for (int i = 100000; ; i++) {
		bool flag = true;
		for (int j = 2; j * j <= i; j++) {
			if (i % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			return i;
		}
	}
}*/
int find(int x)   //返回应该存储x的数组下标k
{
	int k = (x % N + N) % N;
	while (h[k] != null && h[k] != x) {
		k++;
		if (k == N) k = 0;
	}
	return k;
}
int main()
{
	int n;
	scanf("%d", &n);
	memset(h, 0x3f, sizeof h);  //按字节来赋值
	while (n--) {
		int x;
		char op[2];
		scanf("%d%s", &x, op);
		int k = find(x);  //k为x应属的数组下标
		if (op == "I") {
			h[k] = x;
		}
		else {
			if (h[k] == x) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}