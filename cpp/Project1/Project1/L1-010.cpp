#include<iostream>
#include<string>
using namespace std;
int main()
{
	string A, B;      //A - B
	getline(cin, A);
	getline(cin, B);    //因为字符串里面有空格 所以用getline(cin,变量名)
	bool st[256] = { false };   //st[]数组代表某个字符是否字符串B中出现过,出现过true,未出现过false
	//标记字符串B中出现过的字符
	for (char c : B) {
		st[(unsigned char)c] = true;    //(unsigned char)c 表示将字符c强制转换成对应的ASCII编码，当成数组下标来使用
	}
	//遍历A字符串
	for (char c : A) {
		if (!st[(unsigned char)c]) {
			cout << c;
		}
	}
	return 0;
}
