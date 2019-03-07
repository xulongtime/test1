#include "sort.h"
//���ж�������������a[begin...mid]��a[mid+1...end]�ϲ���
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

	//��temp�����еĽ��װ��a����
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
		mergesort(a,begin,mid,temp);   //�������
		mergesort(a,mid+1,end,temp);   //�ұ�����
		MergeArray(a,begin,mid,end,temp); //�������������������ϲ�
	}
}


