#include "sort.h"

void shellSort(int *num,long long len)
{
    len++;
    long long gap, i, j, temp;
    for(gap=len/2;gap>0;gap/=2) //�趨����
        for(i=gap;i<len;++i) //��Ԫ�ؼ��ƶ�Ϊֹ
            for(j=i-gap; j>=0&&num[j]>num[j+gap]; j-=gap) //�Ƚ����gap��Ԫ�أ����򻥻�
            {
                temp=num[j];
                num[j]=num[j+gap];
                num[j+gap]=temp;
            }
}
