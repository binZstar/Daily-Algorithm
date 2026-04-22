#include<stdio.h>
long long Max(long long  m, long long n)
{
       return m > n ? m : n;
}
int main()
{
     int n;
     scanf("%d",n);
     long long a[n+1];
     long long current_sum = 0;
     long long max_sum = 1e-18;
     for(int i = 1; i < n+1; i++){
       scanf("%d",&a[i]);
       current_sum += a[i];
       max_sum = Max(max_sum, current_sum);
       if(current_sum < 0){
        current_sum = 0;
        }
    }
    return 0;
}
