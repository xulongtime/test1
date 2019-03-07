#include "sort.h"
 long long main()
{
    long long len = 0;    //待排序数据长度
    int kind = 65535;   //数据范围，int最大为65535，如果要超过这个限制，又得改成long long的类型
    int a=0;
    time_t t1,t2,t3,t4;   //统计程序实行时间
    double total = 0.0,total1=0.0,total2=0.0,total3=0.0;
    long long i=0;
    int snResult = 0;
    //测试数据太大消耗栈空间，会直接停止运行，才用malloc获取空间

    printf("请输入测试数据大小：");
    scanf("%d",&len);

    int *num1 = (int*)malloc(len*sizeof(int));
    int *num2 = (int*)malloc(len*sizeof(int));
    int *num3 = (int*)malloc(len*sizeof(int));
    int *num4 = (int*)malloc(len*sizeof(int));
    int *num5 = (int*)malloc(len*sizeof(int));
    int *num6 = (int*)malloc(len*sizeof(int));
    int *num7 = (int*)malloc(len*sizeof(int));
    int *num8 = (int*)malloc(len*sizeof(int));
    int *num9 = (int*)malloc(len*sizeof(int));
    int *num10 = (int*)malloc(len*sizeof(int));
    int *temp = (int*)malloc(len*sizeof(int));
    int *guibing = (int *)malloc(len*sizeof(int));

	while( i < len )
        num1[i++] = 0;

	/*获取随机测试数据并备份*/
	i = 0;
	while(i<len)
    {
        a = rand()%kind;
        num1[i] = (int)a;
        temp[i] = num1[i];
        i++;
    }
    /*冒泡排序*/
    t1 = clock();
    maopaoSort(num1,len-1);
    t2 = clock();
    total = (t2-t1);
    printf("冒泡排序所用时间：%d毫秒\n",(int)total);

    /*从备份数据处恢复数据*/
	for( i = 0 ; i<len ; i++)
        num2[i] = temp[i];

    /*选择排序*/
    total = 0.0;
    t1 = clock();
    selectSort(num2,len-1);
    t2 = clock();
    total = t2-t1;
    printf("选择排序所用时间：%d毫秒\n",(int)total);

    /*从备份数据处恢复数据*/
	for( i = 0 ; i<len ; i++)
        num3[i] = temp[i];

    total = 0.0;
    t1 = clock();
    insertSort(num3,len-1);
    t2 = clock();
    total =t2-t1;
    printf("插入排序所用时间：%d毫秒\n",(int)total);

    /*从备份数据处恢复数据*/
	for( i = 0 ; i<len ; i++)
        num4[i] = temp[i];
    /*shell排序*/
    total = 0.0;
    t1 = clock();
    shellSort(num4,len-1);
    t2 = clock();
    total =t2-t1;
    printf("shell排序所用时间：%d毫秒\n",(int)total);

    /*从备份数据处恢复数据*/
	for( i = 0 ; i<len ; i++)
        num5[i] = temp[i];
    /*归并排序*/
    total = 0;
    t1 = clock();
	mergesort(num5,0,len-1,guibing);
	t2 = clock();
	total = t2-t1;
    printf("归并排序所用时间：%d毫秒\n",(int)total);

    /*从备份数据处恢复数据*/
	for( i = 0 ; i<len ; i++)
        num6[i] = temp[i];
    /*快速排序*/
    total = 0;
    t1 = clock();
	quickSort(num6,0,len-1);
	t2 = clock();
	total = t2-t1;
    printf("快速排序所用时间：%d毫秒\n",(int)total);


    /*从备份数据处恢复数据*/
	for( i = 0 ; i<len ; i++)
        num7[i] = temp[i];
    /*快速排序*/
    total = 0;
    t1 = clock();
	quickSort(num7,0,len-1);
	t2 = clock();
	total = t2-t1;
    printf("堆  排序所用时间：%d毫秒\n",(int)total);

    /*从备份数据处恢复数据*/
	for( i = 0 ; i<len ; i++)
        num8[i] = temp[i];
    /*计数排序*/
    total = 0;
    t1 = clock();
	countSort(num8,len);
	t2 = clock();
	total = t2-t1;
    printf("计数排序所用时间：%d毫秒\n",(int)total);

    /*从备份数据处恢复数据*/
	for( i = 0 ; i<len ; i++)
        num9[i] = temp[i];
    /*桶排序*/
    total = 0;
    t1 = clock();
	tongSort(num9,len,6600);
	t2 = clock();
	total = t2-t1;
    printf("桶  排序所用时间：%d毫秒      理论上和计数排序一样是n+k的时间复杂度，但和桶的个数有关\n",(int)total);

    /*从备份数据处恢复数据*/
	for( i = 0 ; i<len ; i++)
        num10[i] = temp[i];
    /*计数排序*/
    total = 0;
    t1 = clock();
	countSort(num10,len);
	t2 = clock();
	total = t2-t1;
    printf("基数排序所用时间：%d毫秒\n",(int)total);

    testResult(1,num1,num2,len);
    testResult(2,num2,num3,len);
    testResult(3,num3,num4,len);
    testResult(4,num4,num5,len);
    testResult(5,num5,num6,len);
    testResult(6,num6,num7,len);
    testResult(7,num7,num8,len);
    testResult(8,num8,num9,len);
    testResult(9,num9,num10,len);


    free(num1);
    free(num2);
    free(num3);
    free(num4);
    free(num5);
    free(num6);
    free(num7);
    free(num8);
    free(num9);
    free(num10);
    free(temp);
    free(guibing);
    return 0;
}
