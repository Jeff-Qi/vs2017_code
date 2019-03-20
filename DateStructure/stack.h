#pragma once
//ջ��ʵ��
#include"stdio.h"
#include"stdlib.h"

#define stacksize 10
typedef int ElemType;
typedef struct {
	//����ջ�ṹ��
	int top;
	ElemType *base;
	int size;
}sqstack;

void initstack(sqstack *s) {
	//��ʼ��ջ
	s->base = (ElemType *)malloc(stacksize * sizeof(ElemType));
	s->top = 0;
	s->size = stacksize;
}

int getlen(sqstack *s) {
	//����ջ��
	return s->top;
}

int getvlaus(sqstack *s) {
	//ȡջ��Ԫ��
	int x;
	if (s->top <= 0) {
		printf("NULL stack\n");
		return 0;
	}
	x = s->base[s->top - 1];
	printf("ջ��Ԫ��:%d\n", x);
	return x;
}

int push(sqstack *s, int num) {
	//��ջ����
	if (s->top >= stacksize) {
		printf("stack full!\n");
		return NULL;
	}
	s->base[s->top] = num;
	s->top = s->top + 1;
	printf("push stack successfully!\n");
	return s->base[s->top - 1];
}

int pop(sqstack *s) {
	//��ջ����
	int x;
	if (s->top <= 0) {
		printf("stack is none!\n");
		return NULL;
	}
	x = s->base[s->top - 1];
	s->top = s->top - 1;
	printf("��ջԪ��:%d\n", x);
	return x;
}

int emptystack(sqstack *s) {
	//�ж�ջ�Ƿ�Ϊ��
	if (s->top <= 0) {
		printf("stack is null!\n");
		return 1;
	}
	printf("stack is no null!\n");
	return 0;
}

void list(sqstack *s) {
	//����ջ����Ԫ��
	for (int i = s->top - 1; i > 0; i--) {
		printf("%d\t", s->base[i]);
	}
	printf("\n");
}
