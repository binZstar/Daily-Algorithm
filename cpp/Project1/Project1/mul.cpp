#include<iostream>
#include<vector>
using namespace std;
vector<int> A, B;
//一个超大数与一个正常数相乘
vector<int> mul(vector<int> &A , int B)
{
	vector<int> C;  //用于存储超大数的每一位与正常数的取余的结果
	int t = 0;      //记录进位的值
	for (int i = 0; i < A.size() || t > 0; i++) {   //当超大数的每一位未与正常数相乘或者进位的值仍然大于0时进行
		if (i < A.size()) t += A[i] * B;        //当超大数的每一位数字为处理完，计算超大数的每一位与正常数相乘的值加上上一次计算进位的值
		C.push_back(t % 10);   //t取余就是结果中的一位
		t /= 10;				//更新进位的值t
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();  //若B = 0，则C数组会存储A.size()个0，把这些前导0出栈
	return C;
}
int main()
{
	string a;    //超大数用string存储
	int b;       //正常数
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');  //把超大数的每一位从字符类型转换成整数类型并存储到A栈中
	auto C = mul(A, b);

	for (int i = C.size() - 1; i >= 0; i--)   cout << C[i];
	cout << endl;
	return 0;

}