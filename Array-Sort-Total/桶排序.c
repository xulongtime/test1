#include "sort.h"

void tongSort(int num[],long long len,long long tong_size) {
	long long i;
	long long j;
	KeyNode **tong_table = (KeyNode **)malloc(tong_size * sizeof(KeyNode*));
	for(i = 0;i < tong_size;i++)    //��ʼ��ÿ��Ͱ
    {
		tong_table[i] = (KeyNode*)malloc(sizeof(KeyNode));
		tong_table[i]->key = -1;        //����ʼ��Ϊ0����Ϊ������������Ҳ��0
		tong_table[i]->next = NULL;
	}
	for( j=0;j<len;j++)     //�����������ݣ��ѷ���Ҫ������ݷ���Ͱ��
    {
		KeyNode *node = (KeyNode *)malloc(sizeof(KeyNode));
		node->key = num[j];
		node->next = NULL;
		int index = num[j]/10;  //�˴�ÿ��Ͱֻ�洢0-9,10-29��,��Ҫ�����/10��Ͱ��������Ҫ����
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
	for(i = 0;i < tong_size;i++)    //��Ͱ������ݶ�д��ԭ����
    {
        p = tong_table[i]->next;
        while(p!=NULL)
        {
            num[j++]=p->key;
            q=p;
            p=p->next;
            free(q);    //�ͷ�ÿһ���ڵ�Ŀռ�
        }
    }
    free(tong_table);   //�ͷ��ܽڵ�Ŀռ�


}
