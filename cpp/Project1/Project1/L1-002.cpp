#include<iostream>
using namespace std;
int main()
{
	int N;
	char c;
	cin >> N >> c;
	//计算行数
	//假设行数为k,第i行的字符数为2*i-1,则k行总共的字符数为1+3+5+...+(2*k-1)=k^2等差数列前n项和的公式为(a1+an)*n/2,其中a1=1,an=2*k-1
	//下半段为k^2-1;那么总共的字符数为k^2+(k^2-1)=2*k^2-1
	int k = 1;
	while (2 * k * k - 1 <= N) {
		k++;
	}
	k--;
	//打印上半段
	for (int i = k; i > 0; i--) {
		//打印空格
		for (int j = 0; j < k - i; j++) {
			cout << " ";
		}
		//打印字符
		for (int j = 0; j < 2 * i - 1; j++) {
			cout << c;
		}
		cout << endl;
	}
	//打印下半段
	for (int i = 2; i <= k; i++) {
		//打印空格
		for (int j = 0; j < k - i;j++) {
			cout << " ";
		}
		//打印字符
		for (int j = 0; j < 2 * i - 1;j++) {
			cout << c;
		}
		cout << endl;
	}
	//计算未使用的字符数
	cout << N - (2 * k * k - 1) << endl;
	
	return 0;
}