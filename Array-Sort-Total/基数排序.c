#include "sort.h"

// 找到num的从低到高的第pos位的数据
int GetNumInPos(int num,long long pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
		temp *= 10;

	return (num / temp) % 10;
}


void RadixSort(int* num, long long len)
{
	int *singleNum[10];    //分别为0~9的序列空间
	long long i =0,pos =0;
	for ( i = 0; i < 10; i++)
	{
		singleNum[i] = (int *)malloc(sizeof(int) * (len + 1));  //每一个尾数节点都申请len个空间，为了避免所有元素都是一个尾数
		singleNum[i][0] = 0;    //index为0处记录这组数据的个数
	}

	for ( pos = 1; pos <= 5; pos++)    //数据的最多为5位，可以根据需要调整，但对整个程序影响较大
	{
		for ( i = 0; i < len; i++)    //遍历所有的数
		{
			int tt = GetNumInPos(num[i], pos);  //找到这个数应该在哪
			int index = ++singleNum[tt][0];     //他应该在的队列计数+1
			singleNum[tt][index] = num[i];      //使用0处保存的个数纪录，将待排序的整数放到应该去的位置
		}

		for (int i = 0, j =0; i < 10; i++)    //放回原数组
		{
			for (int k = 1; k <= singleNum[i][0]; k++)
				num[j++] = singleNum[i][k];
			singleNum[i][0] = 0;    //复位
		}
	}
		for ( i = 0; i < 10; i++)
        {
            free(singleNum[i]); //归还空间
        }

}

