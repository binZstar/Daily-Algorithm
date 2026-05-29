#include<iostream>
using namespace std;
const int N = 10010;
int q[N], hh, tt;   //队列是先进先出
int main()
{
	hh = 0;   //hh代表队头
	tt = -1;  //tt代表队尾
	//入队(从队尾插入元素)
	q[++tt] = 3;
	q[++tt] = 5;
	q[++tt] = 7;

	//出队(从队头出元素)
	hh++;
	
	//队列是否为空
	if (hh > tt) empty;
	else not empty;

	//队头
	q[hh];
	return 0;
}