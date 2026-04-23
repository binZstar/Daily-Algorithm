#include<stdio.h>
long long min(int m, int n)
{
      return m > n ? n : m;
}
long long max(int m ,int n)
{
    return m > n ? m : n;
}
int main()
{
     int n;
     scanf("%d",&n);
     long long  a[n+1];
     long long  sum[n+1];
     sum[0] = 0;
     long long prefix[n+2];  //从0到i最小的前缀和
     prefix[0] = 0;
     long long suffix[n+2];  //从i到n最大的前缀和
     suffix[n+1] = -1e18;
     for(int i = 1; i < n+1; i++){
          scanf("%lld",&a[i]);
          sum[i] = sum[i-1] + a[i];
     }
     for(int i = 1; i < n+1; i++){
       prefix[i] = min(prefix[i-1],sum[i]);
       }
    for(int i = n+1; i > 0; i--){
        suffix[i] = max(suffix[i+1],sum[i]);
     }
     //包含a[i]区间的最大值 = a[i]右边前缀和出现的最大值 - a[1]左边前缀和出现的最小值
     for(int i = 1; i < n+1; i++){
        long long  ans = suffix[i] - prefix[i-1];
        printf("%lld ",ans);
        }
    printf("\n");
     return 0;
}
