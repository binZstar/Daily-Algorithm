#include<iostream>
#include<string>
#include<unordered_map> //哈希表
#include<algorithm>
using namespace std;
const int N = 100010;
string q[N];
int hh = 0, tt = -1;
int bfs(string start)
{
	//目标状态
	string target = "12345678x";
	//d[state]表示从start状态到state状态需要的最少步数
	unordered_map<string, int> d;
	//初始状态入队
	q[++tt] = start;
	//初始状态到初始状态所需的步数为0
	d[start] = 0;
	//移动方向   上~右~下~左
	int dx[4] = { -1,0,1,0 };
	int dy[4] = { 0,1,0,-1 };
	while (hh <= tt)
	{
		//取出队头
		string t = q[hh++];
		int distance = d[t];
		if (t == target) {
			return d[t];
		}
		//找到当前状态中空格在字符串中的下标
		int k = t.find('x');
		//将字符串一维下标转换为二维的3x3的坐标
		int x = k / 3; //行
		int y = k % 3; //列
		//移动空格
		//枚举当前状态可转换的4种状态
		for (int i = 0; i < 4; i++) {
			int a = x + dx[i];
			int b = y + dy[i];
			if (a >= 0 && a < 3 && b >= 0 && b < 3) {
				//更新状态
				swap(t[k], t[a * 3 + b]);
				//如果新状态没有被访问过
				if (!d.count(t)) {
					//新状态入队
					q[++tt] = t;
					//更新步数
					d[t] = distance + 1;
				}
				//恢复状态
				swap(t[k], t[a * 3 + b]);
			}
		}
		return -1;
	}
}
int main()
{
	string start;
	char c;
	for (int i = 0; i < 9; i++) {
		cin >> c;
		start += c;
	}
	cout << bfs(start) << endl;
	return 0;
}
