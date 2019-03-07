#include "sort.h"

// �ҵ�num�Ĵӵ͵��ߵĵ�posλ������
int GetNumInPos(int num,long long pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
		temp *= 10;

	return (num / temp) % 10;
}


void RadixSort(int* num, long long len)
{
	int *singleNum[10];    //�ֱ�Ϊ0~9�����пռ�
	long long i =0,pos =0;
	for ( i = 0; i < 10; i++)
	{
		singleNum[i] = (int *)malloc(sizeof(int) * (len + 1));  //ÿһ��β���ڵ㶼����len���ռ䣬Ϊ�˱�������Ԫ�ض���һ��β��
		singleNum[i][0] = 0;    //indexΪ0����¼�������ݵĸ���
	}

	for ( pos = 1; pos <= 5; pos++)    //���ݵ����Ϊ5λ�����Ը�����Ҫ������������������Ӱ��ϴ�
	{
		for ( i = 0; i < len; i++)    //�������е���
		{
			int tt = GetNumInPos(num[i], pos);  //�ҵ������Ӧ������
			int index = ++singleNum[tt][0];     //��Ӧ���ڵĶ��м���+1
			singleNum[tt][index] = num[i];      //ʹ��0������ĸ�����¼����������������ŵ�Ӧ��ȥ��λ��
		}

		for (int i = 0, j =0; i < 10; i++)    //�Ż�ԭ����
		{
			for (int k = 1; k <= singleNum[i][0]; k++)
				num[j++] = singleNum[i][k];
			singleNum[i][0] = 0;    //��λ
		}
	}
		for ( i = 0; i < 10; i++)
        {
            free(singleNum[i]); //�黹�ռ�
        }

}

