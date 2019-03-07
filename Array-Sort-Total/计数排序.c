#include "sort.h"

void countSort(int *num, int len)
{
    int i;
    int minValue = num[0];
    int maxValue = num[0];
    int range = 0;
    int* tmp = 0;
    int count = 0;
    for (i = 0; i < len; i++)//找到最大的数和最小的数
    {
        if (num[i] < minValue){
            minValue = num[i];
        }
        if (num[i] > maxValue){
            maxValue = num[i];
        }
    }
    range = maxValue - minValue + 1;
    tmp = (int*)malloc(sizeof(num[0])*range);//申请辅助空间
    if (tmp == NULL)
        return;
    memset(tmp, 0, sizeof(int)*range);//初始化

    for (i = 0; i < len; i++)//统计每个元素出现的次数
    {
        tmp[num[i] - minValue]++;
    }

    for(i=0;i<range;i++)//通过统计tmp[]
    {
        while (tmp[i]--)
        {
            num[count++] = i + minValue;
        }
    }
    free(tmp);
}
