#include "sort.h"

void shellSort(int *num,long long len)
{
    len++;
    long long gap, i, j, temp;
    for(gap=len/2;gap>0;gap/=2) //设定步长
        for(i=gap;i<len;++i) //在元素间移动为止
            for(j=i-gap; j>=0&&num[j]>num[j+gap]; j-=gap) //比较相距gap的元素，逆序互换
            {
                temp=num[j];
                num[j]=num[j+gap];
                num[j+gap]=temp;
            }
}
