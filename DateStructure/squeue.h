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
	printf("push num %d successfully!\n",num);
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
	return (s->rear + haha - s->front) % haha;
}

void list(cqueue *s) {
	//����ջ
	int i = s->front;
	int j = getlen(s);
	for (int k = 0; k < j&&(s->flag == 1||s->front!=s->rear); k++) {
		printf("%d\t", s->base[i++]);
	}
	printf("\n");
}

