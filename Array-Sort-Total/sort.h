#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>

void print( int *num, long long len);
int testResult( int n ,int *num1, int *num2, long long len);

/*√∞≈›≈≈–Ú*/
void maopaoSort( int *num, long long len);

/*—°‘Ò≈≈–Ú*/
void selectSort(int *num,long long len);

/*≤Â»Î≈≈–Ú*/
void insertSort(int *num,long long len);
long long findP(int *num,long long len,int value);
long long findPos(int *num,long long start,long long end,int value);

/*shell≈≈–Ú*/
void shellSort(int *num,long long len);

/*πÈ≤¢≈≈–Ú*/
void MergeArray( int num[], long long begin, long long mid, long long end, int *temp);
void mergesort( int num[], long long begin, long long end, int *temp);

//øÏÀŸ≈≈–Ú
void quickSort(int num[],  long long begin, long long end);

//∂—≈≈–Ú
void heapAdjust(int num[],long long i,long long len);
void heapSort(int num[],long long len);

//º∆ ˝≈≈–Ú
void countSort(int *num, int len);

//Õ∞≈≈–Ú
typedef struct node {
	int key;
	struct node *next;
}KeyNode;
void tongSort(int num[],long long len,long long tong_size);

//ª˘ ˝≈≈–Ú
int GetNumInPos(int num,long long pos);
void RadixSort(int* num, long long len);


