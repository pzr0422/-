#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack {
    char *data; // ���ݴ洢��
    int size;   // ջ�Ŀռ��С
    int top;    // ջ��ָ��
} Stack;

// ջ�ĳ�ʼ��
Stack *init_Stack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = n;
    s->data = (char *)malloc(sizeof(char) * n);
    s->top = -1;
    return s;
}

// �пղ���
int empty(Stack *s) {
    return s->top == -1;
}

// �鿴ջ��Ԫ��
char top(Stack *s) {
    if (empty(s))
        return -1;
    return s->data[s->top];
}

// ��ָ��Ԫ��ѹ��ջ��
int push(Stack *s, char val) {
    if (s->top + 1 == s->size)
        return 0;
    s->data[++s->top] = val;
    return 1;
}

// ����ջ��Ԫ��
int pop(Stack *s) {
    if (empty(s))
        return 0;
    s->top--;
    return 1;
}

// ����ջ�ռ�
void clear_Stack(Stack *s) {
    if (s == NULL)
        return;
    free(s->data);
    free(s);
    return;
}

bool isValid(char *s) {
    Stack *stack = init_Stack(5000);
    bool judge = true;
    while (*s) {
        if (*s == '(' || *s == '[' || *s == '{') {
            push(stack, *s);
        } else {
            if (empty(stack)) {
                judge = false;
                break;
            }
            switch (*s) {
                case ')': {
                    if (top(stack) == '(') pop(stack);
                    else
                        judge = false;
                    break;
                }
                case ']': {
                    if (top(stack) == '[') pop(stack);
                    else
                        judge = false;
                    break;
                }
                case '}': {
                    if (top(stack) == '{') pop(stack);
                    else
                        judge = false;
                    break;
                }
            }
        }
        if (judge == false)
            break;
        s++;
    }
    judge = judge && empty(stack); // ���ջ�Ƿ�Ϊ��
    clear_Stack(stack);
    return judge;
}


