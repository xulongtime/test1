#include "sort.h"

void quickSort(int num[],  long long begin, long long end)
{
    long long i, j;
    int temp;
    if(begin < end)
    {
        i = begin + 1;  // ��num[begin]��Ϊ��׼������˴�num[begin+1]��ʼ���׼���Ƚϣ�
        j = end;        // num[end]����������һλ

        while(i < j)
        {
            if(num[i] > num[begin])  // ����Ƚϵ�����Ԫ�ش��ڻ�׼�����򽻻�λ�á�
            {
                temp = num[i];  // ����������.�Ѵ����˦�����ͷȥ��
                num[i] = num[j];
                num[j] = temp;
                j--;            //ͬʱ���ͷ�ı�־ǰ��һλ,��ֹ��һ�λ���ʱ���ָ���������
            }
            else
            {
                i++;  // �����������һλ���������׼���Ƚϡ�
            }
        }

        /* ����whileѭ����i = j��
         * ��ʱ���鱻�ָ����������  -->  num[begin+1] ~ num[i-1] < num[begin]
         *                           -->  num[i+1] ~ num[end] > num[begin]
         * ���ʱ������array�ֳ��������֣��ٽ�num[i]��num[begin]���бȽϣ�����num[i]��λ�á�
         * ���num[i]��num[begin]���������������ָ�ֵ������Դ����ƣ�ֱ�����i = j�������������˳���
         */

        if(num[i] >= num[begin])  // �������Ҫȡ�ȡ�>=������������Ԫ������ͬ��ֵʱ������ִ���
        {
            i--;
        }

        // ����num[i]��num[begin]
        temp = num[i];
        num[i] = num[begin];
        num[begin] = temp;
        quickSort(num,  begin, i);
        quickSort(num,  j, end);
    }
}
