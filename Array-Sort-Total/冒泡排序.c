#include "sort.h"

void maopaoSort( int *num, long long len)
{
    long long i = 0;
    long long temp = 0;
    long long count = 0,tt = 0;

    while(i<len)    //循环len次
    {
        while(i<len)    //在len个数中找到最大的数并移动到最后
        {
            if( num[i] > num[i+1] )
            {
                temp = num[i];
                num[i] = num[i+1];
                num[i+1] = temp;
            }
            i++;
        }
        len--;      //避免已经有序的最后一个数重复比较
        i = 0;
    }
}
