#include "sort.h"

void maopaoSort( int *num, long long len)
{
    long long i = 0;
    long long temp = 0;
    long long count = 0,tt = 0;

    while(i<len)    //ѭ��len��
    {
        while(i<len)    //��len�������ҵ����������ƶ������
        {
            if( num[i] > num[i+1] )
            {
                temp = num[i];
                num[i] = num[i+1];
                num[i+1] = temp;
            }
            i++;
        }
        len--;      //�����Ѿ���������һ�����ظ��Ƚ�
        i = 0;
    }
}
