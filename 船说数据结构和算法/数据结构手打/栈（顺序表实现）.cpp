// ����ջ
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Stack{
	int *data;//���ݴ洢�� 
	int size;//ջ�Ŀռ��С 
	int top;//ջ��ָ�� 
}Stack;

//ջ�ĳ�ʼ�� 
Stack* init_Stack(int n){
	Stack *s = (Stack *)malloc(sizeof(Stack));
	s->size = n;
	s->data = (int *)malloc(sizeof(int) * n);
	s->top = -1;
	return s;
}

//�пղ��� 
int empty(Stack *s){
	return s->top == -1;
}

//�鿴ջ��Ԫ�� 
int top(Stack *s){
	if(empty(s)) return -1;
	return s->data[s->top];
}

//��ָ��Ԫ��ѹ��ջ�� 
int push(Stack *s, int val){
	if(s->top + 1 == s->size) return 0;
	s->data[++s->top] = val;
	return 1;
}

//����ջ��Ԫ�� 
int pop(Stack *s){
	if(empty(s)) return 0;
	s->top--;
	return 1;
}

//����ջ�ռ� 
void clear_Stack(Stack *s){
	if(s == NULL) return;
	free(s->data);
	free(s);
	return ;
}

//��ջ��Ԫ�ؿ�ʼ��ӡջ��Ԫ�� 
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



















