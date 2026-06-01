#include<iostream>
using namespace std;
const int N = 10010;
int head, e[N], ne[N], idx;    // head代表头节点的下标 e[i]代表下标为i节点存储的值 ne[i]代表下标为i的节点所指向的下一个节点的坐标  idx代表当前可以使用的新节点的下标，也代表已经插入节点的数量
//初始化单链表
void init()
{
	head = -1;
	idx = 0;
}
//头插法
void add_to_head(int x)
{
	e[idx] = x;
	ne[idx] = head;
	head = idx;
	idx++;
}
//在下标为k的节点后面插入新的数x
void add(int k,int x)
{
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx;
	idx++;
}
//删除下标为k的节点的后面的一个节点
void remove(int k)
{
	//删除头结点
	if (k == 0) {
		head = ne[head];
	}
	else {
		ne[k] = ne[ne[k]];
	}
}
int main()
{
	init();
	add_to_head(3);  // 3
	add_to_head(5);  // 5 -> 3
	add_to_head(7);  // 7 -> 5 -> 3
	remove(1);    // 7 -> 5
	add(1, 4);    // 7 -> 5 -> 4
	//遍历单链表
	for (int i = head; i != -1; i = ne[i]) {
		cout << e[i] << ' ';
	}
	return 0;
}