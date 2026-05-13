#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector A;
vector<int> div(vector<int>& A, int B, int& t)
{
	//t代表余数，C数组是商
	vector<int> C;
	t = 0;
	for (int i = A.size() - 1;i >= 0; i--) {
		t = t * 10 + A[i];
		C.push_back(t / B);
		t = t % B;
	}
	reverse(C.begin(), C.end());  //逆转栈00123逆转为32100  因为出栈是先出最后面的 栈的特点先入后出，后入先出
	while (C.size() > 0 && C.back() == 0)  C.pop_back();		//出栈
	return C;
}
int main()
{
	string a;      //超大数用string来存储
	int b;		   //正常数
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');  //将超大数的每一位字符转换成int类型并存储到A栈中
	int t;    //代表余数
	auto C = div(A, b, t);
	for (int i = C.size() - 1; i >= 0; i--) cout << C[i];   //输出结果
	cout << endl << t << endl;
	return 0;
}