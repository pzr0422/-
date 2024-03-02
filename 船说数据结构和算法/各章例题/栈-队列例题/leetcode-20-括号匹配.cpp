#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Stack {
    char *data; // 数据存储区
    int size;   // 栈的空间大小
    int top;    // 栈顶指针
} Stack;

// 栈的初始化
Stack *init_Stack(int n) {
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->size = n;
    s->data = (char *)malloc(sizeof(char) * n);
    s->top = -1;
    return s;
}

// 判空操作
int empty(Stack *s) {
    return s->top == -1;
}

// 查看栈顶元素
char top(Stack *s) {
    if (empty(s))
        return -1;
    return s->data[s->top];
}

// 把指定元素压入栈中
int push(Stack *s, char val) {
    if (s->top + 1 == s->size)
        return 0;
    s->data[++s->top] = val;
    return 1;
}

// 弹出栈顶元素
int pop(Stack *s) {
    if (empty(s))
        return 0;
    s->top--;
    return 1;
}

// 清理栈空间
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
    judge = judge && empty(stack); // 检查栈是否为空
    clear_Stack(stack);
    return judge;
}


