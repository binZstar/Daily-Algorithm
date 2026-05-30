#include<iostream>
using namespace std;
const int N = 10010;
int stk[N], tt;  
int main()
{
	int n;
	cin >> n;   //找每个数左边最近且比它小的数
	while (n--) {
		int x;
		cin >> x;

		while (tt && stk[tt] >= x) {     //如果栈内有比她大的数，都先出栈
			tt--;
		}

		if (tt) {
			cout << stk[tt] << ' ';      //如果栈内有元素，输出栈顶元素
		}
		else {
			cout << -1 << ' ';           //如果栈为空，输出-1
		}
		stk[++tt] = x;                     //将它入栈，用于后面的数比较
	}
	return 0;
}