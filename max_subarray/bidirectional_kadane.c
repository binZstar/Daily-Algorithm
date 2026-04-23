#include<stdio.h>
long long max(long long m, long long n)
{
       return m > n ? m : n;
}
int main()
{
    int n;
    scanf("%d",&n);
    long long  a[n + 1];
    long long  left_max[n + 1];    //左边连续最大值,存储以i结尾的最大值
    long long  right_max[n + 1];  //右边连续最大值,存储以i开头的最大值
    left_max[0] = -1e18;    //初始化边界,防止干扰
    right_max[0] = -1e18;
    for(int i = 1; i < n + 1; i++){
        scanf("%lld",&a[i]);
    }
    //正向Kadane,从左往右
    for(int i = 1; i < n + 1; i++){
        if(i == 1){
            left_max[i] = a[i];
         }else{
            left_max[i] = max(a[i],left_max[i - 1] + a[i]);  //Kadane算法核心,断臂重来
        }
    }
    //反向Kadane,从右往左
    for(int i = n; i > 0; i--){
        if(i == n){
            right_max[i] = a[i];
        }else{
            right_max[i] = max(a[i],right_max[i + 1] + a[i]);  //Kadane算法核心,断臂重来
        }
    }
    //合二为一
    for(int i = 1; i < n+1; i++){
        int ans = left_max[i] + right_max[i] - a[i];  //左边和右边分别统计自己本身一次,减去一次
        printf("%lld ",ans);
    }
    printf("\n");
    return 0;
    }
