#include "sort.h"

void heapAdjust(int num[],long long i,long long len)
{
   while( 2*i+1 < len )
   {
      int maxindex=2*i+1; //将最大的下标初始化为s的子树下标
      if(2*i+2<len)
      {
         //比较左子树和右子树，记录最大值的Index
         if(num[2*i+1]<num[2*i+2])
         {
            maxindex=2*i+2;
         }
      }
      if(num[i]<num[maxindex])
      {
       //交换i与maxindex的数据
        num[i]=num[i]^num[maxindex];
        num[maxindex]=num[i]^num[maxindex];
        num[i]=num[i]^num[maxindex];
        //堆被破坏，需重新调整
        i=maxindex;
      }
      else
      {
      //比较左右孩子均大则堆未破坏，不再需要调整
        break;
      }
   }
   return;
}
//堆排序
void heapSort(int num[],long long len)
{
   long long i=0;
   //将num[0,Len-1]建成大顶堆
   for(i=len/2-1;i>=0;i--)
   {
       //调用构建大顶堆函数
        heapAdjust(num,i,len);
   }
   //只需做n-1趟排序
   for(i=len-1;i>0;i--)
   {
     //将字最大的记录R[1](即堆顶)和无序区的最后一个记录R[n]交换
     num[0]=num[0]^num[i];  //通过二进制的所有位的“与”运算，找到最大的数
     num[i]=num[0]^num[i];
     num[0]=num[0]^num[i];
     //将num[0..i]重新调整为大顶堆
      heapAdjust(num,0,i);
   }
   return;
}

