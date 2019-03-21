#pragma once
//ѭ������ʵ��
#include"stdio.h"
#include"stdlib.h"
#define haha 10

typedef int ElemType;
typedef struct {
	ElemType *base;
	int front;
	int rear;
	bool flag;
}cqueue;

bool judge(cqueue *s) {
	if (s->front%haha == s->rear%haha) {
		return 1;
	}
	else {
		return 0;
	}
}

void initcqueue(cqueue *s) {
	//��ʼ��ѭ������
	s->base = (ElemType *)malloc(haha * sizeof(ElemType));
	s->front = s->rear = 0;
	s->flag = 0;
	printf("��ʼ���ɹ�\n");
}


void push(cqueue *s,int num) {
	//�����
	if (s->flag==1&&judge(s)) {
		printf("cqueue is full!\n");
		return;
	}
	s->base[s->rear] = num;
	s->rear = s->rear + 1;
	if (judge(s)) {
		s->flag = 1;
	}
	printf("push successfully!\n");
}

void pop(cqueue *s) {
	//������
	if (s->flag==0&&judge(s)) {
		printf("cqueue is empty!\n");
		return;
	}
	else {
		s->front = s->front + 1;
		if (judge(s)) {
			s->flag=0;
		}
		return;
	}
}

int getlen(cqueue *s) {
	//���ض��г���
	printf("the lenth of cqueue is %d\n", (s->rear + haha - s->front) % haha);
	return (s->rear + haha - s->front) % haha;
}

void list(cqueue *s) {
	int i = s->front;
	int j = getlen(s);
	while (s->flag != 0 || !judge(s)) {
		if (i >= j) {
			break;
		}
		printf("%d\t", s->base[i]);
		i = i + 1;
	}
}

