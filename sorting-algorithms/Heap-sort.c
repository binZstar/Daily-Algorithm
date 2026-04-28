#include<stdio.h>
//创建堆
void createHeap(int *data,int i,int len)
{
        int t = data[i];
        int child = 2 * i;  //左孩子下标
        while(child <= len){
           //看是否有右孩子,如果有右孩子，与左孩子进行比较，找出子结点的较大值
            if(child < len && data[child] < data[child + 1]){
                child++;
            }
            //如果父结点大于子结点，则不需要调整
            if(data[child] < t){
              break;
            }
            //若子结点大于父结点，则应调换位置
            data[child / 2] = data[child];
            //换完之后，为保证是大根堆，应确保父结点始终大于子结点，继续往下进行对比交换
            child = child * 2;
        }
        data[child / 2] = t;
}
//交换
void swap(int *data,int m, int n)
{
        int t = data[m];
        data[m] = data[n];
        data[n] = t;
}
//堆排序
void heapSort(int *data,int len){
     //从最后一个非叶子结点开始，自底向上创建大根堆
     for(int i = len / 2; i > 0; i--){
        createHeap(data, i, len);
    }
    //排序过程: 把堆顶最大值放到最后，然后把剩下的重新堆化
     for(int i = len; i > 0; i--){
            swap(data,1,i);                  //将堆顶最大值与最后一个子节点进行交换
            createHeap(data,1,i - 1);  //对剩余部分重新建立大根堆
     }
}
int main()
{
     int data[] = {-1,11,13,56,78,44,36,99,66,88};
     int len = sizeof(data) / sizeof(data[0]);
     //堆排序
     heapSort(data,len - 1);  //(len - 1 是因为我们有个占位符 -1，实际参与排序的数字只有9个)
                                          //完全二叉树中父结点是i,那么左孩子是2 * i,右孩子是(2 * i) + 1,把0下标去掉利用
     //输出排序结果
     for(int i = 1; i < len; i++){
            printf("%d ",data[i]);
     }
     return 0;
     }
