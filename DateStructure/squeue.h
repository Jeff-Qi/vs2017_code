#pragma once
//循环队列实现
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
	//初始化循环队列
	s->base = (ElemType *)malloc(haha * sizeof(ElemType));
	for (int i = 0; i < haha; i++) {
		s->base[i] = -1;
	}
	s->front = s->rear = 0;
	printf("初始化成功");
}

int judge(cqueue *s) {
	//判断队列是否为假溢出
	if ((s->front==s->rear)&&(s->base[s->rear] == -1)) {
		return 0;
	}
	else {
		return 1;
	}
}

void push(cqueue *s,int num) {
	//入队列
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
	//出队列
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