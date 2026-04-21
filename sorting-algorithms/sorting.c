#include<stdio.h>
//重置数组
void resetArray(int *a, int *original, int len)
{
    for(int i = 0; i < len; i++){
        a[i] = original[i];
    }
}
//打印数组
void printArray(int *a, int len)
{
    for(int i = 0; i < len; i++){
        printf("%d ",a[i]);
    }
    printf("\n");
}
//冒泡排序
void bubble_sort(int *a, int len){
     for(int i = 0; i < len - 1; i++){
         for(int j = 0; j < len - 1 - i; j++){
             if(a[j] > a[j+1]){
               int t = a[j];
               a[j] = a[j+1];
               a[j+1] = t;
               }
            }
        }
}
//简单选择排序
void selection_sort(int *a, int len){
     for(int  i = 0; i < len - 1; i++){
        //内层循环只记最小位置，最后交换
         int min = i;
         for(int j = i + 1; j < len; j++){
            if(a[min] > a[j]){
                min = j;
            }
        }
        if(min != i){
        int t = a[i];
        a[i] = a[min];
        a[min] = t;
        }
    }
}
//插入排序
void insertion_sort(int *a, int len){
    for(int i = 1; i < len; i++){
        int key = a[i];
        int j = i -1;
        while(j >= 0 && a[j] > key){
           a[j+1] = a[j];
           j--;
           }
        a[j+1] = key;
    }
}
//折半插入排序
void binary_insertion_sort(int *a, int len){
    for(int i = 1; i < len; i++){
        int key = a[i];
        int low = 0;
        int high = i - 1;
        while(low <= high){
           int mid = (low + high) / 2;
           if(a[mid] > key){
            high = mid - 1;
           }else{
           low = mid + 1;}
           }
        int j = i - 1;
        while(j >= low){
         a[j+1] = a[j];
         j--;
         }
         a[low] = key;
        }
}
int main()
{
     int original[8] = {12,66,88,11,9,53,80,34};
     int len = sizeof(original) / sizeof(original[0]);
     int a[len];
     resetArray(a,original,len);
     bubble_sort(a,len);
     printArray(a,len);
     resetArray(a,original,len);
     selection_sort(a,len);
     printArray(a,len);
     resetArray(a,original,len);
     insertion_sort(a,len);
     printArray(a,len);
     resetArray(a,original,len);
     binary_insertion_sort(a,len);
     printArray(a,len);
     return 0;
     }
