#include<stdio.h>
int main()
{
     int n,k;
     scanf("%d %d",&n,&k);
     long long a[n + 1];
     long long sum[n +1];
     sum[0] = 0;
     //核心原理：同余定理：(sum[j] - sum[i]) % k == 0,即为sum[j] % k ==  sum[i] % k
     //只要找到两个取余相同的和，它们的区间和就是k的倍数
     int mp[k];  //mp[i]记录sum为i的数量
     mp[0] = 1;
     long long  ans = 0;
     for(int i = 1; i < k; i++){
        mp[i] = 0;
     }
     for(int i = 1; i < n + 1; i++){
        scanf("%lld",&a[i]);
        sum[i] = (sum[i - 1] + a[i]) % k;
        if(sum[i] < 0){
            sum[i] += k;    //若sum为负数，加上取余的数k
        }
        ans += mp[sum[i]];   //到一个新的sum,看他前面有几个与该sum相同
        mp[sum[i]] ++;          //表示前面的sum可以与该sum形成k倍区间，有几个相同的就加几，
     }
     printf("%lld\n",ans);
     return 0;
     }
