#include<iostream>
#include<string>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int w[17] = { 7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2 };  //权重
	char m[11] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };  //最后一位M效验码
	bool all_past = true;    //全部格式符合为true
	while (n--) {
		string s;
		cin >> s;
		bool flag = true;  //当前格式假设符合
		//身份证前17位是否是数字
		for (int i = 0; i < 17; i++) {
			if (s[i] < '0' || s[i] > '9') {
				flag = false;
				break;
			}
		}
		//加权求z
		if (flag) {
			int sum = 0;
			for (int i = 0; i < 17; i++) {
				sum += (s[i] - '0') * w[i];
			}
			int z = sum % 11;
			if (m[z] != s[17]) {
				flag = false;
			}
		}
		if (!flag) {
			cout << s << endl;
			all_past = false;
		}
	}
	if (all_past) {
		cout << "All passed" << endl;
	}
	return 0;
}