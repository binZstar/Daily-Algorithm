#include<stdio.h>
long long Max(long long  m, long long n)
{
       return m > n ? m : n;
}
long long  Min(long long m , long long  n)
{
        return m < n ? m : n;
}
int main()
{
    int n;
    scanf("%d",&n);
    int a[n+1];
    long long  sum[n+1];
    sum[0] = 0;
    long long  prefix[n+1];
    prefix[0] = 0;
    long long  suffix[n+2];
    suffix[n+1] = 1e-18;
    //求出前缀和
    for(int i = 1; i < n + 1; i++){
         scanf("%d",&a[i]);
         sum[i] = sum[i-1] + a[i];
         }
    //求区间最大值，就是求sum[j] - sum[i]的最大值 j > i;
    //也就是求sum[j]的最大值和sum[i]的最小值
    //比如求以a[k]为起点开始往两边扩展区间的最大值，求k位置后面最大的sum[j],和k位置前面的最小值sun[i];
    //本题要求求整个数组区间的最大值，把每个顶点枚举完成取其最大值
    for(int i = 1; i < n + 1; i++){
         prefix[i] = Min(prefix[i-1], sum[i]);
    }
    for(int i = n; i > 0; i-- ){
         suffix[i] = Max(suffix[i+1], sum[i]);
         }
    long long ans = 1e-18;
    for(int i = 1; i < n + 1; i++){
         ans = Max(ans, suffix[i] - prefix[i-1]);
         }
    printf("%lld\n",ans);
    return 0;
    }




