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
}cqueue;

void initcqueue(cqueue *s) {
	//��ʼ��ѭ������
	s->base = (ElemType *)malloc(haha * sizeof(ElemType));
	for (int i = 0; i < haha; i++) {
		s->base[i] = -1;
	}
	s->front = s->rear = 0;
	printf("��ʼ���ɹ�");
}

int judge(cqueue *s) {
	//�ж϶����Ƿ�Ϊ�����
	if ((s->front==s->rear)&&(s->base[s->rear] == -1)) {
		return 0;
	}
	else {
		return 1;
	}
}

void push(cqueue *s,int num) {
	//�����
	if (!judge(s)) {
		printf("cqueue is full!\n");
		return;
	}
	s->base[s->rear] = num;
	s->rear = s->rear + 1;
	if (s->front == s->rear) {
		s->rear = s->rear%haha;
	}
	printf("push successfully!\n");
}

void pop(cqueue *s) {
	//������
	if (s->base[s->front] == -1) {
		printf("cqueue is empty!\n");
		return;
	}
	else {
		s->base[s->front] = -1;
		s->front = s->front - 1;
		if (s->front == haha) {
			s->front = s->front%haha;
		}
		return;
	}
}