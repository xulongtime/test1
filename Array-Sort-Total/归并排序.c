#include "sort.h"
//将有二个有序子数组a[begin...mid]和a[mid+1...end]合并。
void MergeArray( int a[], long long begin, long long mid, long long end, int temp[])
{
	 long long i=begin,j=mid+1;
	 long long m=mid,n=end;
	 long long k=0;

	while(i<=m && j<=n)
	{
		if(a[i]<=a[j])
			temp[k++]=a[i++];
		else
			temp[k++]=a[j++];
	}
	while(i<=m)
		temp[k++]=a[i++];
	while(j<=n)
		temp[k++]=a[j++];

	//把temp数组中的结果装回a数组
	for(i=0;i<k;i++)
    {
		a[begin+i]=temp[i];
	}
}

void mergesort( int a[], long long begin, long long end, int temp[])
{
	if(begin<end)
	{
		long long mid = (begin+end)/2;
		mergesort(a,begin,mid,temp);   //左边有序
		mergesort(a,mid+1,end,temp);   //右边有序
		MergeArray(a,begin,mid,end,temp); //将左右两边有序的数组合并
	}
}


