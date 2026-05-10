#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	long long N;
	cin >> N;
	int maxlen = 0;   //最长连续因子的长度
	long long  startnum = 0; //最长连续因子的起始数字
	//从2开始暴力枚举
	//优化：枚举到sqrt(N) 连续因子越长，小于sqrt(N)的数越多，并且sqrt(N) * (sqrt(N) + 1) > N，越界不符合题意
	for (long long i = 2; i <= sqrt(N); i++) {
		int currentlen = 0; //当前连续因子的长度/个数
		long long  temp = 1;  //当前连续因子的乘积
		for (long long j = i; ; j++) {
			temp *= j;  
			//能整除，则连续，看是否还能接着连续
			if (N % temp == 0) {
				currentlen++;
				//更新最大连续因子的个数和起始数字 ；  当前连续的个数大于最大连续的个数，则赋值给最大连续因子的个数
				if (currentlen > maxlen) {
					maxlen = currentlen;
					startnum = i;
				}
			}
			//不能整除，代表连续断开，继续枚举
			else {
				break;
			}
		}
	}
	//特殊情况：如果该数字是质数，那么只能被1和它本身整除
	//题目因子不包含1，所以最小连续因子是它本身,长度为1
	if (maxlen == 0) {
		maxlen = 1;
		startnum = N;
	}
	cout << maxlen << endl;
	for (int i = 0; i < maxlen;i++) {
		cout << startnum + i;
		if (i != maxlen - 1) {
			cout << "*";
		}
	}
	cout << endl;
	
	return 0;
}