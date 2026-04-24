#include<stdio.h>
int  max(int m , int n)
{
    return m > n ? m : n;
}
int main()
{
     int n;
     scanf("%d",&n);
     long long a[n + 1];
     long long sum[n + 1];  //前缀和的进阶
     sum[0] = 0;
     // 核心原理：同余定理。若 (S[j] - S[i]) % 7 == 0，则 S[j] % 7 == S[i] % 7
    // 只要找到余数相同的两个前缀和，它们之间的区间和就是 7 的倍数
     int ans = 0;
     int mp[7];   //mp[i]记录sum为i的最左侧位置
     mp[0] = 0;  //最左侧sum为0的最左侧位置是0
     for(int i = 1; i < 7; i++){
            mp[i] = -1;
    }
     for(int i = 1; i < n + 1; i++){
        scanf("%lld",&a[i]);
        sum[i] = (sum[i - 1] + a[i]) % 7;
        if(sum[i] < 0){
            sum[i] += 7;        //若sum为负数,加上一个取余的数
        }
        if(mp[sum[i]] == -1){
            mp[sum[i]] = i;     //若没有记录过该sum的位置，则将它视为最左侧位置
        }else{
            ans = max(ans, i - mp[sum[i]]);    //若记录过该sum的位置，求其距离，取距离最大值，即为求解和为7的倍数的最长子区间
        }
     }
     printf("%d\n",ans);
     return 0;
}
