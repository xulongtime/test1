#include "sort.h"

void selectSort(int *num,long long len)
{
    long long i = 0;
    int pos = 0;
    int temp = 0;
    while( len>=1 )
    {
        temp = num[i];
        pos = i;
        while( i<= len )
        {
            if( num[i] > temp )
            {
                temp = num[i];
                pos = i;
            }
            i++;
        }
        num[pos] = num[len];
        num[len] = temp;
        len--;
        i = 0;
    }
}
