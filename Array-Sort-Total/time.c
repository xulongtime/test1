#include "sort.h"

void print( int *num, long long len)
{
    long long i = 0;
    for( i=0;i<len;i++)
	{
		printf("%d ",num[i]);
	}
	printf("\n");
}

 int testResult( int n , int *num1, int *num2, long long len)
{
    long long i = 0;
    while(i<len)
    {
        if(num1[i] != num2[i])
        {
            printf("%d����%d������һ��,%d,%d��\n",n,i,num1[i],num2[i]);
            return -1;
        }
        i++;
    }

    return 0;
}

