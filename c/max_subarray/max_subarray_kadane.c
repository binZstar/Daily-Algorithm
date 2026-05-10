#include<stdio.h>
long long Max(long long  m, long long n)
{
       return m > n ? m : n;
}
int main()
{
     int n;
     scanf("%d",&n);
     long long a[n+1];
     //Kadane算法
     long long current_sum = 0;     //记录当前的连续累加和
     long long max_sum = -1e18;   //记录我们路上见过的最大连续和(区间和)
     for(int i = 1; i < n+1; i++){  
       scanf("%lld",&a[i]);   
       current_sum += a[i];  //输入一个数据加到当前连续和中，为后来判断是否要断臂重来做准备
       max_sum = Max(max_sum, current_sum);   //修改路上见过的最大连续和
       if(current_sum < 0){ 
        current_sum = 0;  //如果是负数，直接断臂重来
        }
    }
    printf("%lld\n",max_sum);
    return 0;
}
