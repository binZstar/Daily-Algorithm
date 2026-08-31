#include<iostream>
#include<algorithm>
using namespace std;
const int N = 310;
struct Student {
    int id;
    int chinese;
    int math;
    int english;
    int sum;
};
Student q[N];
Student temp[N];
void merge_sort(int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) / 2;
    merge_sort(l, mid);
    merge_sort(mid + 1, r);
    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r) {
        if (q[i].sum > q[j].sum) {
            temp[k++] = q[i++];
        }
        else if (q[i].sum < q[j].sum) {
            temp[k++] = q[j++];
        }
        else if (q[i].sum == q[j].sum) {
            if (q[i].chinese >= q[j].chinese) {
                temp[k++] = q[i++];
            }
            else {
                temp[k++] = q[j++];
            }
        }
    }
    while (i <= mid) temp[k++] = q[i++];
    while (j <= r) temp[k++] = q[j++];
    for (int i = l, j = 0; i <= r; i++, j++) q[i] = temp[j];
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        q[i].id = i;
        scanf("%d%d%d", &q[i].chinese, &q[i].math, &q[i].english);
        q[i].sum = q[i].chinese + q[i].math + q[i].english;
    }
    merge_sort(1, n);
    for (int i = 1; i <= 5; i++) {
        cout << q[i].id << ' ' << q[i].sum << endl;
    }
    return 0;
}