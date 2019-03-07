#include "sort.h"

void tongSort(int num[],long long len,long long tong_size) {
	long long i;
	long long j;
	KeyNode **tong_table = (KeyNode **)malloc(tong_size * sizeof(KeyNode*));
	for(i = 0;i < tong_size;i++)    //初始化每个桶
    {
		tong_table[i] = (KeyNode*)malloc(sizeof(KeyNode));
		tong_table[i]->key = -1;        //不初始化为0是因为待排序数组中也有0
		tong_table[i]->next = NULL;
	}
	for( j=0;j<len;j++)     //遍历整个数据，把符合要求的数据放入桶中
    {
		KeyNode *node = (KeyNode *)malloc(sizeof(KeyNode));
		node->key = num[j];
		node->next = NULL;
		int index = num[j]/10;  //此处每个桶只存储0-9,10-29，,需要最大数/10个桶，根据需要调整
		KeyNode *p = tong_table[index];
		if(p->key == -1) {
			tong_table[index]->next = node;
			(tong_table[index]->key)++;
		}else {
			while(p->next != NULL && p->next->key <= node->key)
				p = p->next;
			node->next = p->next;
			p->next = node;
			(tong_table[index]->key)++;
		}
	}
    i = 0;
	j = 0;
	KeyNode *p,*q;
	for(i = 0;i < tong_size;i++)    //将桶里的数据都写回原数组
    {
        p = tong_table[i]->next;
        while(p!=NULL)
        {
            num[j++]=p->key;
            q=p;
            p=p->next;
            free(q);    //释放每一个节点的空间
        }
    }
    free(tong_table);   //释放总节点的空间


}
