#include<iostream>
using namespace std;
const int N = 10010;
int stk[N],tt;
int main()
{
	tt = 0; //初始化 表示栈为空
	
	//入栈
	stk[++tt] = 1;
	stk[++tt] = 2;
	stk[++tt] = 3;
	//出栈
	tt--;

	//栈顶
	cout << stk[tt] << endl; //栈顶是3

	//栈是否为空
	if (!tt) empty;
	else not empty;
	return 0;
}