#include<iostream>
using namespace std;
const int N = 10010;
int  e[N], l[N],r[N], idx;  //e[i]代表下标i存储的数值 l[i]代表下标i左边的节点的下标 r[i]代表下标i右边的节点的下标 idx代表当前能使用的最新节点的下标，也代表已经插入节点的数量
void init()
{
	r[0] = 1;
	l[1] = 0;
	idx = 2;   //左右哨兵占据了0和1的下标
}
//在下标为k的节点的右边插入x
void add(int k,int x)
{
	e[idx] = x;

	r[idx] = r[k];
	l[idx] = k;

	l[r[k]] = idx;
	r[k] = idx;

	idx++;	
}
//删除下标为k的节点
void remove(int k)
{
	r[l[k]] = r[k];
	l[r[k]] = l[k];
}
int main()
{
	init();
	add(0, 9);		//在最左边插入9			-1 <-> 9 <-> -1
	add(l[1], 8);	//在最右边插入8			-1 <-> 9 <-> 8 <-> -1
	add(2, 6);		//在下标为2的节点的右边插入		-1 <-> 9 <-> 6 <-> 8 <-> -1     //这里的-1代表左右哨兵的假设值，不会输出
	remove(4);      //删除下标为4的节点		-1 <-> 9 <-> 8 <-> -1
	for (int i = r[0]; i != 1; i = r[i]) {
		cout << e[i] << ' ';
	}
	return 0;
}