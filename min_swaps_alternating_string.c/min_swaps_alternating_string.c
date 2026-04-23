#include<stdio.h>
int min(int m , int n){
        return m > n ? n : m;
 }
int main()
{
      int t;
      scanf("%d",&t);
      for(int i = 0; i < t; i++){
           int n;
           scanf("%d",&n);
           int len = 2 * n;
           char a[len+1];  //原数组
           char b[len+1];  //创建目标数组1
           char c[len+1];  //创建目标数组2
           for(int j = 1; j < len + 1; j++){
             scanf(" %c",&a[j]);
            //创建目标数组
             if(j % 2 == 0){
                b[j] = 'B';
                c[j] = 'A';
             }else{
               b[j] = 'A';
               c[j] = 'B';
             }
      }
      //记录与目标数组不同的元素数量，最小交换次数就是它数量的1/2
      int count1 = 0;
      int count2 = 0;
      for(int k = 1; k < len + 1; k++){
            if(a[k] != b[k]){
              count1++;
              }
             if(a[k] != c[k]){
              count2++;
              }
        }
    //取与目标数组不同元素数量的最小值，最小交换次数 = 最小不同元素数量 / 2
     int ans = min(count1,count2) / 2;
     printf("%d\n",ans);
    }
    return 0;
}
