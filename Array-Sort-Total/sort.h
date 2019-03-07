#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

void print( int *num, long long len);
int testResult( int n ,int *num1, int *num2, long long len);

/*ð������*/
void maopaoSort( int *num, long long len);

/*ѡ������*/
void selectSort(int *num,long long len);

/*��������*/
void insertSort(int *num,long long len);
long long findP(int *num,long long len,int value);
long long findPos(int *num,long long start,long long end,int value);

/*shell����*/
void shellSort(int *num,long long len);

/*�鲢����*/
void MergeArray( int num[], long long begin, long long mid, long long end, int *temp);
void mergesort( int num[], long long begin, long long end, int *temp);

//��������
void quickSort(int num[],  long long begin, long long end);

//������
void heapAdjust(int num[],long long i,long long len);
void heapSort(int num[],long long len);

//��������
void countSort(int *num, int len);

//Ͱ����
typedef struct node {
	int key;
	struct node *next;
}KeyNode;
void tongSort(int num[],long long len,long long tong_size);

//��������
int GetNumInPos(int num,long long pos);
void RadixSort(int* num, long long len);


