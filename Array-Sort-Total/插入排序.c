#include "sort.h"

void insertSort(int *num,long long len)
{
    long long i = 0;
    long long start = 2;    //默认第一个元素有序
    long long pos = 0;
    int temp;
    if(num[0]>num[1])
    {
        temp = num[1];
        num[1] =num[0];
        num[0] =temp;
    }
    while( start <= len )
    {
        pos = findPos(num,0,start-1,num[start]);
        if( pos == start )
        {
            start++;
            continue;
        }
        //pos = findP(num,start,num[start]);
        temp = num[start];
        i=start;
        while( pos < i )
        {
            num[i] =  num[i-1];
            i--;
        }
        num[pos] =temp;
        start++;
    }
}

long long findP(int *num,long long len,int value)
{
    long long i =0;
    while( i<len)
    {
        if( num[i]>value)
            return i;
            i++;
    }
    return len;
}

/*二分查找法更快的确定位置*/
long long findPos(int *num,long long start,long long end,int value)
{
    long long mid;
    while( start<=end )
    {
        mid = (end+start)/2;
        if( num[mid] >= value )
        {
            end = mid-1;
        }
        else
        {
            start = mid+1;
        }
    }
    return start;
}
