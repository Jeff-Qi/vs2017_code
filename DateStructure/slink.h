#pragma once
//单链表实现
#include"stdio.h"
#include"stdlib.h"


typedef int Elemtype;
typedef struct node {
	//定义链表结构体
	Elemtype data;
	struct node *next;
}slink;

slink * creatslink(int n) {
	//创建链表
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
	//获得链表长度
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
	//获取第n个链表数据
	slink *p;
	int i;
	if (n < 1) {
		printf("输入值非法!\n");
		return 0;
	}
	p = L->next;
	i = 1;
	while (p != NULL && i < n) {
		i++;
		p = p->next;
	}
	if (p == NULL) {
		printf("超过链表长度!\n");
		return 0;
	}
	printf("第%d个链表值为:%d\n", n, p->data);
	return 1;
}

int local(slink *L, int num) {
	//定位给定的num值得位置
	slink *p;
	int i = 0;
	if (L == NULL) {
		printf("当前链表为空!\n");
		return 0;
	}
	p = L->next;
	while (p != NULL && p->data != num) {
		p = p->next;
		i++;
	}
	if (p == NULL) {
		printf("链表中无此数\n");
		return 0;
	}
	else {
		printf("第%d个链表为%d\n", i, num);
		return 0;
	}
}

slink * deleteslink(slink *L, int n) {
	//删除第n个链表
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
	//插入操作
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
	//遍历链表
	slink *p;
	p = L->next;
	while (p != NULL) {
		printf("%d\t", p->data);
		p = p->next;
	}
	printf("\n");
}
