#pragma once
//栈的实现
#include"stdio.h"
#include"stdlib.h"

#define stacksize 10
typedef int ElemType;
typedef struct {
	//定义栈结构体
	int top;
	ElemType *base;
	int size;
}sqstack;

void initstack(sqstack *s) {
	//初始化栈
	s->base = (ElemType *)malloc(stacksize * sizeof(ElemType));
	s->top = 0;
	s->size = stacksize;
}

int getlen(sqstack *s) {
	//返回栈长
	return s->top;
}

int getvlaus(sqstack *s) {
	//取栈顶元素
	int x;
	if (s->top <= 0) {
		printf("NULL stack\n");
		return 0;
	}
	x = s->base[s->top - 1];
	printf("栈顶元素:%d\n", x);
	return x;
}

int push(sqstack *s, int num) {
	//入栈操作
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
	//出栈操作
	int x;
	if (s->top <= 0) {
		printf("stack is none!\n");
		return NULL;
	}
	x = s->base[s->top - 1];
	s->top = s->top - 1;
	printf("出栈元素:%d\n", x);
	return x;
}

int emptystack(sqstack *s) {
	//判断栈是否为空
	if (s->top <= 0) {
		printf("stack is null!\n");
		return 1;
	}
	printf("stack is no null!\n");
	return 0;
}

void list(sqstack *s) {
	//遍历栈所有元素
	for (int i = s->top - 1; i > 0; i--) {
		printf("%d\t", s->base[i]);
	}
	printf("\n");
}
