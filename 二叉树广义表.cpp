	// 二叉树序列化(serialize)以及反序列化(deserialize)--->使用广义表
#include <bits/stdc++.h>
#define KEY(n) (n ? n->data : -1)
typedef struct Node{
	int data;
	struct Node *lchild, *rchild;
}Node;

Node *getNewNode(int val){
	Node *p = (Node *)malloc(sizeof(Node));
	p->data = val;
	p->lchild = p->rchild = NULL;
	return p;
}

Node *insert(Node *root, int val){
	if(root == NULL) return getNewNode(val);
	if(rand() % 2) root->lchild = insert(root->lchild, val);
	else root->rchild = insert(root->rchild, val);
	return root;
}

Node *getRandomBT(int num){
	Node *root = NULL;
	for(int i = 0; i < num; i++){
		root = insert(root, rand() % 100);
	}
	return root;
}


void clear(Node *root){
	if(root == NULL) return;
	clear(root->lchild);
	clear(root->rchild);
	free(root);
	return;
}

char buff[1000];
int len = 0;

void __serialize(Node *root){
	if(root == NULL) return;
	//root
	//注意printf类函数的返回值是什么 
	len += sprintf(buff + len, "%d", root->data);
	if(root->lchild == NULL && root->rchild == NULL) return;
	else len += sprintf(buff + len, "(");
	//lchild
	__serialize(root->lchild);	
	//rchild
	if(root->rchild){
		len += sprintf(buff + len, ",");
		__serialize(root->rchild);
	}
	len += sprintf(buff + len, ")");
	return ;
}

void serialize(Node *root){
	//做初始化
	memset(buff, 0, sizeof(buff));
	len = 0;
	//封装功能 
	__serialize(root); 
}

Node *deserialize(char *buff, int len){
	//使用数组维护一个栈
	Node **s = (Node **)malloc(sizeof(Node *));
	int top = -1;//栈顶标识
	int flag = 0;//用于标识当前是左子树（0）还是右子树（1）
	int scode = 0;//状态码,用于判断当前应该执行什么操作 
	Node *p = NULL;
	Node *root = NULL;
	for(int i = 0; buff[i]; i++){
		switch(scode){
			//如果scode=0，那么就根据当前buff[i]的值来分发任务(也就是改变scode的值) 
			case 0: {
				if(buff[i] >= '0' && buff[i] <= '9') scode = 1;
				if(buff[i] == '(') scode = 2;
				if(buff[i] == ',') scode = 3;
				if(buff[i] == ')') scode = 4;
				i--;
				break;
			}
			case 1:{
				int num = 0;//用于获取完整的数 
				//小技巧 
				while(buff[i] >= '0' && buff[i] <= '9'){
					num = num * 10 + (buff[i] - '0');
					i++;
				}
				i--;
				p = getNewNode(num);
				if(top >= 0){
					if(flag == 1) s[top]->rchild = p;
					else s[top]->lchild = p;
				}
				scode = 0;//每次循环后都要重新分发任务 
				break;
			}
			//压栈 
			case 2:{
				s[++top] = p;
				flag = 0;
				scode = 0;
				break;
			}
			case 3:{
				flag = 1;//转为右子树 
				scode = 0;
				break;
			}
			//弹栈 
			case 4:{
				root = s[top];
				--top;
				scode = 0;
				break;
			}
		}
			
	}
	return root;
} 

void print(Node *node){
	printf("%d(%d, %d)\n", KEY(node), KEY(node->lchild), KEY(node->rchild));
}

void output(Node *root){
	if(root == NULL) return;
	print(root);
	output(root->lchild);
	output(root->rchild);
	return;
}

int main(void){
	srand(time(0));
	#define MAX_NODE 10
	Node *root = getRandomBT(MAX_NODE);
	serialize(root);
	printf("原二叉树:\n");
	output(root);
	printf("\n");
	printf("buff[]:%s\n", buff);
	printf("\n");
	printf("由序列还原二叉树的结果:\n");
	Node *new_root = deserialize(buff, strlen(buff));
	output(new_root);//与序列化之前的输出做对比 
	return 0;
} 























