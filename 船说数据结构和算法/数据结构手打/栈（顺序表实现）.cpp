// 手敲栈
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack{
	int *data;//数据存储区 
	int size;//栈的空间大小 
	int top;//栈顶指针 
}Stack;

//栈的初始化 
Stack* init_Stack(int n){
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->size = n;
	s->data = (int *)malloc(sizeof(int) * n);
	s->top = -1;
	return s;
}

//判空操作 
int empty(Stack *s){
	return s->top == -1;
}

//查看栈顶元素 
int top(Stack *s){
	if(empty(s)) return -1;
	return s->data[s->top];
}

//把指定元素压入栈中 
int push(Stack *s, int val){
	if(s->top + 1 == s->size) return 0;
	s->data[++s->top] = val;
	return 1;
}

//弹出栈顶元素 
int pop(Stack *s){
	if(empty(s)) return 0;
	s->top--;
	return 1;
}

//清理栈空间 
void clear_Stack(Stack *s){
	if(s == NULL) return;
	free(s->data);
	free(s);
	return ;
}

//从栈顶元素开始打印栈中元素 
void output_stack(Stack *s){
	printf("Stack:");
	if(s == NULL) return;
	for(int i = s->top; i >= 0; --i){
		printf("%4d", s->data[i]);
	}
	printf("\n\n");
	return;
}

int main(void){
	srand(time(0));
	#define MAX_OP 10
	Stack *s = init_Stack(5);
	for(int i = 0; i < MAX_OP; i++){
		int op = rand() % 3, val = rand() % 100;
		switch(op){
			case 0:
				printf("pop stack, item = %d\n", top(s));
				pop(s);
				break;
			case 1:
			case 2:
				printf("push stack, item = %d\n", val);
				push(s, val);
				break;
		}
		output_stack(s);
	}
	clear_Stack(s);
	return 0;
} 



















