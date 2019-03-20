#pragma once
//������ʵ��
#include"stdio.h"
#include"stdlib.h"


typedef int Elemtype;
typedef struct node {
	//��������ṹ��
	Elemtype data;
	struct node *next;
}slink;

slink * creatslink(int n) {
	//��������
	slink *head, *p, *s;
	int i;
	p = head = (slink *)malloc(sizeof(slink));
	for (i = 1; i <= n; i++) {
		s = (slink *)malloc(sizeof(slink));
		s->data = i * i;
		p->next = s;
		p = s;
	}
	p->next = NULL;
	return head;
}

int getlen(slink *L) {
	//���������
	slink *p;
	p = L->next;
	int n = 0;
	while (p != NULL) {
		n++;
		p = p->next;
	}
	return n;
}

int getnumber(slink *L, int n) {
	//��ȡ��n����������
	slink *p;
	int i;
	if (n < 1) {
		printf("����ֵ�Ƿ�!\n");
		return 0;
	}
	p = L->next;
	i = 1;
	while (p != NULL && i < n) {
		i++;
		p = p->next;
	}
	if (p == NULL) {
		printf("����������!\n");
		return 0;
	}
	printf("��%d������ֵΪ:%d\n", n, p->data);
	return 1;
}

int local(slink *L, int num) {
	//��λ������numֵ��λ��
	slink *p;
	int i = 0;
	if (L == NULL) {
		printf("��ǰ����Ϊ��!\n");
		return 0;
	}
	p = L->next;
	while (p != NULL && p->data != num) {
		p = p->next;
		i++;
	}
	if (p == NULL) {
		printf("�������޴���\n");
		return 0;
	}
	else {
		printf("��%d������Ϊ%d\n", i, num);
		return 0;
	}
}

slink * deleteslink(slink *L, int n) {
	//ɾ����n������
	slink *p, *s;
	int i;
	if (n < 1) {
		printf("number is invalid\n");
		return L;
	}
	p = L;
	i = 1;
	while (p->next != NULL && i != n) {
		i++;
		p = p->next;
	}
	if (p->next == NULL) {
		printf("number is beyond the range\n");
		return L;
	}
	else {
		s = p->next;
		p->next = s->next;
		free(s);
		printf("delete successfully\n");
		return L;
	}
}

slink * insert(slink * L, int i, int num) {
	//�������
	slink *p, *s;
	int j = 1;
	p = L;
	if (i < 1) {
		printf("invalid\n");
		return L;
	}
	while (p->next != NULL && j != i) {
		p = p->next;
		j++;
	}
	if (p->next == NULL) {
		printf("byyond\n");
		return L;
	}
	else {
		s = (slink *)malloc(sizeof(slink));
		s->next = NULL;
		s->data = num;
		s->next = p->next;
		p->next = s;
		return L;
	}
}

void list(slink *L) {
	//��������
	slink *p;
	p = L->next;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
