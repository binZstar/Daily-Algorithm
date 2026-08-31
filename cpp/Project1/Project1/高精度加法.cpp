#include<iostream>
#include<vector>
using namespace std;
const int N = 1e6 + 10; //数字的最大长度(无用，助理解)
vector<int> A, B;       //存储二个超大数的每一位数
//计算二个超大数的函数
vector<int> add(vector<int>& A, vector<int>& B)
{
	vector<int> C;    //二个数组的每一个数(也就是每一位数)相加的值保存在C数组中
	int t = 0;    //记录二个数每一个位数相加的和
	for (int i = 0; i < A.size() || i < B.size(); i++) {
		if (i < A.size()) t += A[i];
		if (i < B.size()) t += B[i];
		C.push_back(t % 10);  //将相加的值取余保存在C数组中
		t /= 10;   //t更新为进位的值 (进一) (用于下一组位数相加)
	}
	if (t) C.push_back(1);  //若最后一组位数相加还有进位的值，再进一
	return C;
}
int main()
{
	string a, b;      //用string存储超大数字
	cin >> a >> b;
	//a = "123456789";
	for (int i = a.size() - 1;i >= 0; i--)  A.push_back(a[i] - '0');  //将a超大"数字"转换成int类型并将每一位数存储到A数组中(先存储个位数字)
	for (int i = b.size() - 1;i >= 0; i--)  B.push_back(b[i] - '0');  //将b超大"数字"转换成int类型并将每一位数存储到B数组中(先存储个位数字)
	//auto自动推断返回值的类型
	auto c = add(A, B);     //调用二个超大数相加的函数
	for (int i = c.size() - 1; i >= 0; i--) {
		cout << c[i];
	}
	cout << endl;
	return 0;
}