#include "sort.h"

void countSort(int *num, int len)
{
    int i;
    int minValue = num[0];
    int maxValue = num[0];
    int range = 0;
    int* tmp = 0;
    int count = 0;
    for (i = 0; i < len; i++)//�ҵ�����������С����
    {
        if (num[i] < minValue){
            minValue = num[i];
        }
        if (num[i] > maxValue){
            maxValue = num[i];
        }
    }
    range = maxValue - minValue + 1;
    tmp = (int*)malloc(sizeof(num[0])*range);//���븨���ռ�
    if (tmp == NULL)
        return;
    memset(tmp, 0, sizeof(int)*range);//��ʼ��

    for (i = 0; i < len; i++)//ͳ��ÿ��Ԫ�س��ֵĴ���
    {
        tmp[num[i] - minValue]++;
    }

    for(i=0;i<range;i++)//ͨ��ͳ��tmp[]
    {
        while (tmp[i]--)
        {
            num[count++] = i + minValue;
        }
    }
    free(tmp);
}
