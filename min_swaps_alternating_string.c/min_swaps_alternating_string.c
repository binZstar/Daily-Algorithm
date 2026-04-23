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
           char a[len+1];
           char b[len+1];
           char c[len+1];
           for(int j = 1; j < len + 1; j++){
             scanf(" %c",&a[j]);
             if(j % 2 == 0){
                b[j] = 'B';
                c[j] = 'A';
             }else{
               b[j] = 'A';
               c[j] = 'B';
             }
      }
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
     int ans = min(count1,count2) / 2;
     printf("%d\n",ans);
    }
    return 0;
}
