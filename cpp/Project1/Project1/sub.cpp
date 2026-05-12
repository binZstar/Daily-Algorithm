#include<iostream>
#include<vector>
using namespace std;
vector<int> A, B;
//比较a是否大于等于bf
bool cmp(vector<int>& A, vector<int>& B)
{
	if (A.size() != B.size()) return A.size() > B.size();  //如果位数不相等，返回A.size() > B.size()，若返回值为真，就计算a - b,若返回值为假，计算 b - a
	for (int i = A.size() - 1; i >= 0; i--) {
		if (A[i] != B[i]) {
			return A[i] > B[i];
		}
	}
	return true;
}
//计算二个超大数的减法
vector<int> sub(vector<int>& A, vector<int>& B)
{
	vector<int> C;   //存储每一位计算的结果
	int t = 0;       //借位的数
	for (int i = 0; i < A.size(); i++) {
		t = A[i] - t;
		if (i < B.size()) t -= B[i];  //如果B数组还存在，则减去B[i]
		C.push_back((t + 10) % 10);   //将计算的结果压入栈中 若t<0，需要借1也就是加上10再取余，若t<0,则不需要借1，直接取余，这里加上10再取余不影响
		if (t < 0) t = 1;             //若t<0,则刚才借1，需要在下一位计算的时候减去借走的1
		else t = 0;                    //若t>=0，则刚才没借1，恢复到0
	}
	while (C.size() > 1 && C.back() == 0) C.pop_back();  //若高位数减去的结果为0,不能输出002，应该输出2，出栈把前导0去掉
	return C;
}
int main()
{
	string a, b;
	cin >> a >> b;
	for (int i = a.size() - 1; i >= 0; i--) A.push_back(a[i] - '0');
	for (int i = b.size() - 1; i >= 0; i--) B.push_back(b[i] - '0');
	//若A>=B，直接计算
	if (cmp(A, B)) {
		auto c = sub(A, B);
		for (int i = c.size(); i >= 0; i--) cout << c[i];
	}
	//若A<B，先输出负号-,再计算他的相反数
	else {
		cout << '-';
		auto c = sub(B, A);
		for (int i = c.size() - 1; i >= 0; i--) cout << c[i];
	}
	return 0;
}