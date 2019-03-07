#include "sort.h"

void quickSort(int num[],  long long begin, long long end)
{
    long long i, j;
    int temp;
    if(begin < end)
    {
        i = begin + 1;  // 将num[begin]作为基准数，因此从num[begin+1]开始与基准数比较！
        j = end;        // num[end]是数组的最后一位

        while(i < j)
        {
            if(num[i] > num[begin])  // 如果比较的数组元素大于基准数，则交换位置。
            {
                temp = num[i];  // 交换两个数.把大的数甩到最后头去，
                num[i] = num[j];
                num[j] = temp;
                j--;            //同时最后头的标志前移一位,防止下一次换的时候又给换回来了
            }
            else
            {
                i++;  // 将数组向后移一位，继续与基准数比较。
            }
        }

        /* 跳出while循环后，i = j。
         * 此时数组被分割成两个部分  -->  num[begin+1] ~ num[i-1] < num[begin]
         *                           -->  num[i+1] ~ num[end] > num[begin]
         * 这个时候将数组array分成两个部分，再将num[i]与num[begin]进行比较，决定num[i]的位置。
         * 最后将num[i]与num[begin]交换，进行两个分割部分的排序！以此类推，直到最后i = j不满足条件就退出！
         */

        if(num[i] >= num[begin])  // 这里必须要取等“>=”，否则数组元素由相同的值时，会出现错误！
        {
            i--;
        }

        // 交换num[i]与num[begin]
        temp = num[i];
        num[i] = num[begin];
        num[begin] = temp;
        quickSort(num,  begin, i);
        quickSort(num,  j, end);
    }
}
