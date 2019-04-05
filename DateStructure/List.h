#pragma once

//���Ա�

#include"stdio.h"
#include"stdlib.h"

#define List_size 2
#define List_increase 1

typedef struct {
	int *data;
	int length;
	int listsize;
}List;

void Init_List(List *L) {
	//��ʼ���б�	initial a list
	L->data = (int *)malloc(sizeof(int)*List_size);
	L->length = List_size;
	L->listsize = 0;
}

void Insert_List(List *L, int i, int num) {
	//��������	insert an data into list
	if (i<0 || i>L->length + 1) {
		printf("location is invalid!\n");
		return;
	}
	if (L->listsize >= List_size) {
		int *newdata;
		newdata = (int *)realloc(L->data, sizeof(int)*(L->length + List_increase));
		if (!newdata) {
			printf("realloc is unsuccessful!\n");
			return;
		}
		L->data = newdata;
		L->length += List_increase;
	}
	for (int j = L->listsize - 1; j >= i - 1; j--) {
		L->data[j + 1] = L->data[j];
	}
	L->data[i - 1] = num;
	L->listsize += 1;
	printf("insert successfully!\n");
}

void Delete_List(List *L, int i) {
	//ɾ�����Ա��Ԫ��	delete a number in list
	if (i<0 || i>L->length + 1) {
		printf("location is invalid!\n");
		return;
	}
	for (; i < L->listsize; i++) {
		L->data[i - 1] = L->data[i];
	}
	L->listsize--;
}

void Search_List(List *L, int num) {
	//��ѯԪ��	search a number in a list
	if (L->listsize == 0) {
		printf("list is empty!\n");
		return;
	}
	for (int i = 1; i < L->listsize; i++) {
		if (L->data[i - 1] == num) {
			printf("search successfully!\n");
			return;
		}
	}
}

void List_List(List *L) {
	//�����б�	list a list
	for (int i = 0; i < L->listsize; i++) {
		printf("%d\t", L->data[i]);
	}
	printf("\n");
}