#include "sort.h"

void heapAdjust(int num[],long long i,long long len)
{
   while( 2*i+1 < len )
   {
      int maxindex=2*i+1; //�������±��ʼ��Ϊs�������±�
      if(2*i+2<len)
      {
         //�Ƚ�������������������¼���ֵ��Index
         if(num[2*i+1]<num[2*i+2])
         {
            maxindex=2*i+2;
         }
      }
      if(num[i]<num[maxindex])
      {
       //����i��maxindex������
        num[i]=num[i]^num[maxindex];
        num[maxindex]=num[i]^num[maxindex];
        num[i]=num[i]^num[maxindex];
        //�ѱ��ƻ��������µ���
        i=maxindex;
      }
      else
      {
      //�Ƚ����Һ��Ӿ������δ�ƻ���������Ҫ����
        break;
      }
   }
   return;
}
//������
void heapSort(int num[],long long len)
{
   long long i=0;
   //��num[0,Len-1]���ɴ󶥶�
   for(i=len/2-1;i>=0;i--)
   {
       //���ù����󶥶Ѻ���
        heapAdjust(num,i,len);
   }
   //ֻ����n-1������
   for(i=len-1;i>0;i--)
   {
     //�������ļ�¼R[1](���Ѷ�)�������������һ����¼R[n]����
     num[0]=num[0]^num[i];  //ͨ�������Ƶ�����λ�ġ��롱���㣬�ҵ�������
     num[i]=num[0]^num[i];
     num[0]=num[0]^num[i];
     //��num[0..i]���µ���Ϊ�󶥶�
      heapAdjust(num,0,i);
   }
   return;
}

